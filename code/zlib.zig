const std = @import("std");
const panic = std.debug.panic;
const assert = std.debug.assert;

const log = @import("log.zig");
const mem = @import("mem.zig");
const math = @import("math.zig");
const byteio = @import("byteio.zig");

pub fn decompress(buffer_init: []u8, decompressed: []u8) !void {
    var buffer = buffer_init;

    const cmf = byteio.readU8(&buffer);

    const compression_method = cmf & 0b00001111;
    if (compression_method != 8) return error.UnrecognizedCompressionMethod;

    const compression_info = cmf >> 4;
    const window_size = @as(u32, 1) << @intCast(u5, compression_info + 8);
    _ = window_size;

    const flags = byteio.readU8(&buffer);
    const cmf_and_flags = (@as(u16, cmf) << 8) | @as(u16, flags);
    if (@mod(cmf_and_flags, 31) != 0) return error.BadFCHECK;

    const preset_dict = (flags & 0b00100000) != 0;
    _ = preset_dict;

    const flevel = flags >> 6;
    _ = flevel;

    try inflate(buffer, decompressed);
}

const ByteArray = struct {
    buffer: []u8,
    used: i32 = 0,

    pub fn append(self: *ByteArray, byte: u8) !void {
        if (self.used < self.buffer.len) {
            self.buffer[@intCast(usize, self.used)] = byte;
            self.used += 1;
        } else {
            return error.OutOfMemory;
        }
    }
};

const MAXBITS = 15;
const MAXLCODES = 286;
const MAXDCODES = 30;
const MAXCODES = MAXLCODES + MAXDCODES;
const FIXLCODES = 288;

const Huffman = struct {
    counts: [MAXBITS + 1]u16,
    symbols: []u16,

    fn fromLengths(lengths: []u16, symbols: []u16) Huffman {
        var counts: [MAXBITS + 1]u16 = undefined;
        for (counts) |*count| {
            count.* = 0;
        }

        for (lengths) |len| {
            counts[len] += 1;
        }

        var offsets: [counts.len]u16 = undefined;
        offsets[1] = 0;
        var offset_index: usize = 1;
        while (offset_index < counts.len - 1) : (offset_index += 1) {
            offsets[offset_index + 1] = offsets[offset_index] + counts[offset_index];
        }

        var symbol: u16 = 0;
        while (symbol < lengths.len) : (symbol += 1) {
            if (lengths[symbol] != 0) {
                symbols[offsets[lengths[symbol]]] = symbol;
                offsets[lengths[symbol]] += 1;
            }
        }

        const table = Huffman{ .counts = counts, .symbols = symbols };
        return table;
    }
};

const Inflator = struct {
    output: ByteArray,
    input_left: []u8,
    bit_buffer: u32 = 0,
    bit_buffer_used: i32 = 0,

    fn readBits(inflator: *Inflator, bit_count: u5) u32 {
        var value = inflator.bit_buffer;

        while (inflator.bit_buffer_used < bit_count) {
            const next_input_byte = byteio.readU8(&inflator.input_left);
            value |= @intCast(u32, next_input_byte) << @intCast(u5, inflator.bit_buffer_used);
            inflator.bit_buffer_used += 8;
        }

        const needed_bits = value & ((@as(u32, 1) << bit_count) - 1);
        inflator.bit_buffer = value >> bit_count;
        inflator.bit_buffer_used -= bit_count;

        return needed_bits;
    }

    fn readNotCompressed(inflator: *Inflator) !void {
        _ = inflator;
        panic("no compression not implemented", .{});
    }

    fn readCompressed(inflator: *Inflator, len_table: *const Huffman, dist_table: *const Huffman) !void {
        _ = dist_table;

        const lengths = [29]u16{ 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31, 35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258 };
        const lengths_extra = [29]u5{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0 };
        const distances = [30]u16{ 1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193, 257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145, 8193, 12289, 16385, 24577 };
        const distances_extra = [30]u5{ 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13 };

        var reached_end = false;
        while (!reached_end) {
            const symbol = inflator.decode(len_table) orelse return error.FailedToDecodeLength;
            if (symbol < 256) {
                try inflator.output.append(@intCast(u8, symbol));
            } else if (symbol > 256) {
                const length_index = symbol - 257;
                if (length_index >= 29) return error.InvalidFixedCode;
                const length_extra_count = lengths_extra[@intCast(usize, length_index)];
                const length_extra = inflator.readBits(length_extra_count);
                const length = lengths[@intCast(usize, length_index)] + length_extra;

                const distance_index = inflator.decode(dist_table) orelse return error.FailedToDecodeDistance;
                const distance_extra_count = distances_extra[@intCast(usize, distance_index)];
                const distance_extra = inflator.readBits(distance_extra_count);
                const distance = distances[@intCast(usize, distance_index)] + distance_extra;
                if (distance > inflator.output.used) return error.DistanceTooFarBack;

                const copy_start = @intCast(u32, inflator.output.used) - distance;
                const copy_end = copy_start + length;
                var copy_index = copy_start;
                while (copy_index < copy_end) : (copy_index += 1) {
                    const byte_to_copy = inflator.output.buffer[copy_index];
                    try inflator.output.append(byte_to_copy);
                }
            }

            reached_end = symbol == 256;
        }
    }

    fn decode(inflator: *Inflator, table: *const Huffman) ?i32 {
        var code: i32 = 0;
        var first: i32 = 0;
        var index: i32 = 0;
        var len: i32 = 1;

        var result: ?i32 = null;
        while (len <= MAXBITS) {
            code |= @intCast(i32, inflator.readBits(1));
            const count = table.counts[@intCast(usize, len)];
            if (code - count < first) {
                result = table.symbols[@intCast(usize, index + (code - first))];
                break;
            }
            index += count;
            first += count;
            first <<= 1;
            code <<= 1;
            len += 1;
        }

        return result;
    }
};

fn inflate(input: []u8, output: []u8) !void {
    var inflator = Inflator{ .output = ByteArray{ .buffer = output }, .input_left = input };

    const fixed = fx: {
        var lengths: [FIXLCODES]u16 = undefined;

        var symbol: usize = 0;
        while (symbol < 144) : (symbol += 1) {
            lengths[symbol] = 8;
        }
        while (symbol < 256) : (symbol += 1) {
            lengths[symbol] = 9;
        }
        while (symbol < 280) : (symbol += 1) {
            lengths[symbol] = 7;
        }
        while (symbol < FIXLCODES) : (symbol += 1) {
            lengths[symbol] = 8;
        }

        var len_symbols: [FIXLCODES]u16 = undefined;
        const len_table = Huffman.fromLengths(lengths[0..len_symbols.len], len_symbols[0..]);

        symbol = 0;
        while (symbol < MAXDCODES) : (symbol += 1) {
            lengths[symbol] = 5;
        }

        var dist_symbols: [MAXDCODES]u16 = undefined;
        const dist_table = Huffman.fromLengths(lengths[0..dist_symbols.len], dist_symbols[0..]);

        break :fx .{ .len = len_table, .dist = dist_table };
    };

    var done = false;
    while (!done) {
        const is_last = inflator.readBits(1);
        const block_type = inflator.readBits(2);

        switch (block_type) {
            0 => try inflator.readNotCompressed(),
            1 => try inflator.readCompressed(&fixed.len, &fixed.dist),
            2 => {

                const order = [19]u16{16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15};

                const nlen = inflator.readBits(5) + 257;
                const ndist = inflator.readBits(5) + 1;
                const ncode = inflator.readBits(4) + 4;
                assert(nlen <= MAXLCODES and ndist <= MAXDCODES and ncode < order.len);

                var lengths: [MAXCODES]u16 = undefined;
                {
                    var code_index: usize = 0;
                    while (code_index < ncode) : (code_index += 1) {
                        const length_index = order[code_index];
                        lengths[length_index] = @intCast(u16, inflator.readBits(3));
                    }
                    while (code_index < order.len) : (code_index += 1) {
                        const length_index = order[code_index];
                        lengths[length_index] = 0;
                    }
                }

                var len_symbols: [MAXLCODES]u16 = undefined;
                const temp_len_table = Huffman.fromLengths(lengths[0..order.len], len_symbols[0..]);

                {
                    var index: usize = 0;
                    while (index < nlen + ndist) {
                        const symbol = inflator.decode(&temp_len_table) orelse return error.FailedToDecode;
                        var last_length: u16 = 0;

                        if (symbol < 16) {
                            lengths[index] = @intCast(u16, symbol);
                            index += 1;
                        } else {
                            last_length = 0;
                            var to_repeat: u32 = 0;

                            if (symbol == 16) {
                                if (index == 0) return error.NoLastLength;
                                last_length = lengths[index - 1];
                            } else if (symbol == 17) {
                                to_repeat = 3 + inflator.readBits(3);
                            } else {
                                to_repeat = 11 + inflator.readBits(7);
                            }

                            if (index + to_repeat > nlen + ndist) return error.TooManyLengths;

                            while (to_repeat > 0) : (to_repeat -= 1) {
                                lengths[index] = last_length;
                                index += 1;
                            }
                        }
                    }
                }

                if (lengths[256] == 0) return error.NoEndOfBlockCode;

                const len_table = Huffman.fromLengths(lengths[0..nlen], len_symbols[0..]);

                var dist_symbols: [MAXDCODES]u16 = undefined;
                const dist_table = Huffman.fromLengths(lengths[nlen..][0..ndist], dist_symbols[0..]);

                try inflator.readCompressed(&len_table, &dist_table);
            },
            else => return error.BadBlockType,
        }
        _ = block_type;

        done = is_last == 1;
    }
}
