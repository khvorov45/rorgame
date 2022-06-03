const std = @import("std");
const assert = std.debug.assert;

const log = @import("log.zig");

pub fn parse(buffer_init: []u8) !void {
    var buffer = buffer_init;
    const header = try parse_header(&buffer);
    log.debug("{}", .{header});
}

const Header = struct {
    frame_count: i32,
    width: i32,
    height: i32,
    bits_per_pixel: i32,
    color_count: i32,
};

fn parse_header(buffer: *[]u8) !Header {
    const init_buffer_size = buffer.*.len;
    const file_size = readDWORDle(buffer);
    if (file_size != init_buffer_size) return error.FileSizeMismatch;

    const magic = readWORDle(buffer);
    if (magic != 0xA5E0) return error.WrongMagic;

    const frame_count = readWORDle(buffer);

    const width = readWORDle(buffer);
    const height = readWORDle(buffer);

    const bits_per_pixel = readWORDle(buffer);
    if (bits_per_pixel != 32 and bits_per_pixel != 16 and bits_per_pixel != 8) return error.WrongBitsPerPx;

    const flags = readDWORDle(buffer);
    _ = flags;

    const depricated_speed = readWORDle(buffer);
    _ = depricated_speed;

    _ = readDWORDle(buffer);
    _ = readDWORDle(buffer);

    const transparent_color_pallete_entry = readBYTE(buffer);
    _ = transparent_color_pallete_entry;

    _ = readBYTE(buffer);
    _ = readBYTE(buffer);
    _ = readBYTE(buffer);

    const color_count = readWORDle(buffer);

    const pixel_width = readBYTE(buffer);
    const pixel_height = readBYTE(buffer);
    if (pixel_width != 0 and pixel_height != 0 and pixel_width != pixel_height) return error.NonSquarePixels;

    const grid_x = readSHORTle(buffer);
    const grid_y = readSHORTle(buffer);
    const grid_width = readWORDle(buffer);
    const grid_height = readWORDle(buffer);

    _ = grid_x;
    _ = grid_y;
    _ = grid_width;
    _ = grid_height;

    buffer.* = buffer.*[84..];

    const result = Header{
        .frame_count = @intCast(i32, frame_count),
        .width = @intCast(i32, width),
        .height = @intCast(i32, height),
        .bits_per_pixel = @intCast(i32, bits_per_pixel),
        .color_count = @intCast(i32, color_count),
    };
    return result;
}

const DWORD = u32;
const WORD = u16;
const BYTE = u8;
const SHORT = i16;

fn readDWORDle(buffer: *[]u8) DWORD {
    const bytes = buffer.*[0..4];
    buffer.* = buffer.*[4..];

    const result =
        (@intCast(DWORD, bytes[3]) << 24) |
        (@intCast(DWORD, bytes[2]) << 16) |
        (@intCast(DWORD, bytes[1]) << 8) |
        (@intCast(DWORD, bytes[0]));

    return result;
}

fn readWORDle(buffer: *[]u8) DWORD {
    const bytes = buffer.*[0..2];
    buffer.* = buffer.*[2..];

    const result =
        (@intCast(DWORD, bytes[1]) << 8) |
        (@intCast(DWORD, bytes[0]));

    return result;
}

fn readBYTE(buffer: *[]u8) BYTE {
    const byte = buffer.*[0];
    buffer.* = buffer.*[1..];
    return byte;
}

fn readSHORTle(buffer: *[]u8) SHORT {
    const word = readWORDle(buffer);
    const result = @intCast(SHORT, word);
    return result;
}
