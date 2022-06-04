const std = @import("std");
const assert = std.debug.assert;

const log = @import("log.zig");

pub fn parse(buffer_init: []u8) !void {
    var buffer = buffer_init;
    const header = try parseHeader(&buffer);
    log.debug("{}", .{header});

    var frame_index: i32 = 0;
    while (frame_index < header.frame_count) : (frame_index += 1) {
        const frame_header = try parseFrameHeader(&buffer);
        log.debug("{}", .{frame_header});

        var chunk_index: i32 = 0;
        while (chunk_index < frame_header.chunk_count) : (chunk_index += 1) {
            const chunk = parseChunk(&buffer);
            log.debug("{}", .{chunk});
        }
    }

    if (buffer.len != 0) return error.DidNotParseEntireBuffer;
}

const Header = struct {
    frame_count: i32,
    width: i32,
    height: i32,
    bits_per_pixel: i32,
    color_count: i32,
};

fn parseHeader(buffer: *[]u8) !Header {
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

const FrameHeader = struct {
    size: i32,
    ms: i32,
    chunk_count: i32,
};

fn parseFrameHeader(buffer: *[]u8) !FrameHeader {
    const frame_size = readDWORDle(buffer);

    const magic = readWORDle(buffer);
    if (magic != 0xF1FA) return error.WrongFrameMagic;

    const old_chunk_count = readWORDle(buffer);
    const frame_ms = readWORDle(buffer);

    _ = readBYTE(buffer);
    _ = readBYTE(buffer);

    const new_chunk_count = readDWORDle(buffer);
    const chunk_count = @maximum(old_chunk_count, new_chunk_count);

    const result = FrameHeader{
        .size = @intCast(i32, frame_size),
        .ms = @intCast(i32, frame_ms),
        .chunk_count = @intCast(i32, chunk_count),
    };
    return result;
}

const ChunkType = enum {
    old_pallette1,
    old_pallette2,
    layer,
    cel,
    cel_extra,
    color_profile,
    external_files,
    mask,
    path,
    tags,
    palette,
    user_data,
    slice,
    tileset,
};

const Chunk = union(ChunkType) {
    old_pallette1: void,
    old_pallette2: void,
    layer: void,
    cel: Cel,
    cel_extra: void,
    color_profile: void,
    external_files: void,
    mask: void,
    path: void,
    tags: void,
    palette: void,
    user_data: void,
    slice: void,
    tileset: void,
};

const Cel = struct {
    x: i32,
    y: i32,
    width: i32,
    height: i32,
};

fn parseChunk(buffer: *[]u8) !Chunk {
    const chunk_size = readDWORDle(buffer);
    const chunk_type = readWORDle(buffer);

    const chunk_data_size = chunk_size - @sizeOf(DWORD) - @sizeOf(WORD);
    const chunk_data = buffer.*[0..chunk_data_size];
    buffer.* = buffer.*[chunk_data_size..];

    _ = chunk_data;

    const chunk = switch (chunk_type) {
        0x0004 => Chunk{ .old_pallette1 = {} },
        0x0011 => Chunk{ .old_pallette2 = {} },
        0x2004 => Chunk{ .layer = {} },
        0x2005 => Chunk{ .cel = try parseCel(chunk_data) },
        0x2006 => Chunk{ .cel_extra = {} },
        0x2007 => Chunk{ .color_profile = {} },
        0x2008 => Chunk{ .external_files = {} },
        0x2016 => Chunk{ .mask = {} },
        0x2017 => Chunk{ .path = {} },
        0x2018 => Chunk{ .tags = {} },
        0x2019 => Chunk{ .palette = {} },
        0x2020 => Chunk{ .user_data = {} },
        0x2022 => Chunk{ .slice = {} },
        0x2023 => Chunk{ .tileset = {} },
        else => return error.WrongChunkType,
    };

    return chunk;
}

fn parseCel(chunk_data_init: []u8) !Cel {
    var chunk_data = chunk_data_init;

    const layer_index = readWORDle(&chunk_data);
    _ = layer_index;

    const x_pos = readSHORTle(&chunk_data);
    const y_pos = readSHORTle(&chunk_data);

    const opacity = readBYTE(&chunk_data);
    _ = opacity;

    const cel_type = readWORDle(&chunk_data);

    chunk_data = chunk_data[7..];

    var width: DWORD = undefined;
    var height: DWORD = undefined;
    switch (cel_type) {
        0 => return error.CelTypeRawImageData,
        1 => return error.CelTypeLinked,
        2 => {
            width = readWORDle(&chunk_data);
            height = readWORDle(&chunk_data);
        },
        3 => return error.CelTypeCompressedTilemap,
        else => return error.CelTypeUnrecognized,
    }

    const result = Cel{
        .x = @intCast(i32, x_pos),
        .y = @intCast(i32, y_pos),
        .width = @intCast(i32, width),
        .height = @intCast(i32, height),
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
