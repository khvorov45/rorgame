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

    var done = false;
    while (!done) {
        done = true;
    }

    _ = decompressed;

    @breakpoint();
}
