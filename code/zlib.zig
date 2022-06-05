const panic = @import("std").debug.panic;

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
            self.buffer[self.used] = byte;
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
            value = value | (next_input_byte << @intCast(u3, inflator.bit_buffer_used));
            inflator.bit_buffer_used += 8;
        }

        const needed_bits = value & ((@as(u32, 1) << bit_count) - 1);
        inflator.bit_buffer = value >> bit_count;
        inflator.bit_buffer_used -= bit_count;

        return needed_bits;
    }

    fn readNotCompressed(inflator: *Inflator) void {
        _ = inflator;
        panic("no compression not implemented", .{});
    }

    fn readCompressed(inflator: *Inflator, len_table: *const Huffman, dist_table: *const Huffman) void {
        _ = dist_table;

        const symbol = inflator.decode(len_table);
        _ = symbol;
        @breakpoint();
    }

    fn decode(inflator: *Inflator, table: *const Huffman) i32 {
        var code: i32 = 0;
        var first: i32 = 0;
        var index: i32 = 0;
        var len: i32 = 1;

        var result: i32 = -10;
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

    var dist_symbols: [MAXDCODES]u16 = undefined;
    const dist_table = Huffman.fromLengths(lengths[0..dist_symbols.len], dist_symbols[0..]);

    var done = false;
    while (!done) {
        const is_last = inflator.readBits(1);
        const block_type = inflator.readBits(2);

        switch (block_type) {
            0 => inflator.readNotCompressed(),
            1 => inflator.readCompressed(&len_table, &dist_table),
            2 => panic("dynamic unimplemented", .{}),
            else => return error.BadBlockType,
        }
        _ = block_type;

        done = is_last == 1;
    }
    @breakpoint();
}
