const std = @import("std");
const assert = std.debug.assert;

const log = @import("log.zig");
const math = @import("math.zig");
const zlib = @import("zlib.zig");
const mem = @import("mem.zig");
const byteio = @import("byteio.zig");

const Texture = @import("assets.zig").Texture;

pub fn parse(buffer_init: []u8, allocator: mem.Allocator) ![]Texture {
    var buffer = buffer_init;

    const header = try parseHeader(&buffer);
    const frames = try allocator.alloc(Frame, @intCast(usize, header.frame_count));

    {
        var frame_index: i32 = 0;
        while (frame_index < header.frame_count) : (frame_index += 1) {
            const frame_header = try parseFrameHeader(&buffer);
            const frame = &frames[@intCast(usize, frame_index)];
            frame.chunks = try allocator.alloc(Chunk, @intCast(usize, frame_header.chunk_count));

            var chunk_index: i32 = 0;
            while (chunk_index < frame_header.chunk_count) : (chunk_index += 1) {
                frame.chunks[@intCast(usize, chunk_index)] = try parseChunk(&buffer, header.bits_per_pixel, allocator);
            }
        }
    }

    if (buffer.len != 0) return error.DidNotParseEntireBuffer;

    const textures = try allocator.alloc(Texture, frames.len);
    for (frames) |frame, frame_index| {
        var texture = &textures[frame_index];
        texture.* = Texture{
            .pixels = try allocator.alloc(u32, @intCast(usize, header.dim.x * header.dim.y)),
            .dim = header.dim,
        };
        for (texture.pixels) |*px| {
            px.* = 0;
        }

        var last_layer_index: i32 = -1;
        for (frame.chunks) |chunk| {
            switch (chunk) {
                .cel => |cel| {
                    assert(last_layer_index < cel.layer_index);
                    last_layer_index = cel.layer_index;

                    var decompressed = cel.decompressed;
                    var px_row = cel.pos.y;
                    var px_col = cel.pos.x;

                    while (decompressed.len > 0) {
                        switch (header.bits_per_pixel) {
                            32 => {
                                const px_value = byteio.readRGBAasARGB(&decompressed);
                                const px_index = px_row * texture.dim.x + px_col;

                                // TODO(khvorov) Alpha
                                texture.pixels[@intCast(usize, px_index)] = px_value;

                                if (px_col + 1 == cel.pos.x + cel.dim.x) {
                                    px_col = cel.pos.x;
                                    px_row += 1;
                                } else {
                                    px_col += 1;
                                }
                            },
                            16 => std.debug.panic("16 bits per pixel unimplemented", .{}),
                            8 => std.debug.panic("8 bits per pixel unimplemented", .{}),
                            else => unreachable,
                        }
                    }
                },
                else => {},
            }
        }
    }

    return textures;
}

const Header = struct {
    frame_count: i32,
    dim: math.V2i,
    bits_per_pixel: i32,
    color_count: i32,
};

fn parseHeader(buffer: *[]u8) !Header {
    const init_buffer_size = buffer.*.len;
    const file_size = byteio.readU32le(buffer);
    if (file_size != init_buffer_size) return error.FileSizeMismatch;

    const magic = byteio.readU16le(buffer);
    if (magic != 0xA5E0) return error.WrongMagic;

    const frame_count = byteio.readU16le(buffer);

    const width = byteio.readU16le(buffer);
    const height = byteio.readU16le(buffer);

    const bits_per_pixel = byteio.readU16le(buffer);
    if (bits_per_pixel != 32 and bits_per_pixel != 16 and bits_per_pixel != 8) return error.WrongBitsPerPx;

    const flags = byteio.readU32le(buffer);
    _ = flags;

    const depricated_speed = byteio.readU16le(buffer);
    _ = depricated_speed;

    _ = byteio.readU32le(buffer);
    _ = byteio.readU32le(buffer);

    const transparent_color_pallete_entry = byteio.readU8(buffer);
    _ = transparent_color_pallete_entry;

    _ = byteio.readU8(buffer);
    _ = byteio.readU8(buffer);
    _ = byteio.readU8(buffer);

    const color_count = byteio.readU16le(buffer);

    const pixel_width = byteio.readU8(buffer);
    const pixel_height = byteio.readU8(buffer);
    if (pixel_width != 0 and pixel_height != 0 and pixel_width != pixel_height) return error.NonSquarePixels;

    const grid_x = byteio.readI16le(buffer);
    const grid_y = byteio.readI16le(buffer);
    const grid_width = byteio.readU16le(buffer);
    const grid_height = byteio.readU16le(buffer);

    _ = grid_x;
    _ = grid_y;
    _ = grid_width;
    _ = grid_height;

    buffer.* = buffer.*[84..];

    const result = Header{
        .frame_count = @intCast(i32, frame_count),
        .dim = math.V2i{ .x = @intCast(i32, width), .y = @intCast(i32, height) },
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
    const frame_size = byteio.readU32le(buffer);

    const magic = byteio.readU16le(buffer);
    if (magic != 0xF1FA) return error.WrongFrameMagic;

    const old_chunk_count = byteio.readU16le(buffer);
    const frame_ms = byteio.readU16le(buffer);

    _ = byteio.readU8(buffer);
    _ = byteio.readU8(buffer);

    const new_chunk_count = byteio.readU32le(buffer);
    const chunk_count = @maximum(old_chunk_count, new_chunk_count);

    const result = FrameHeader{
        .size = @intCast(i32, frame_size),
        .ms = @intCast(i32, frame_ms),
        .chunk_count = @intCast(i32, chunk_count),
    };
    return result;
}

const Frame = struct {
    chunks: []Chunk,
};

const Chunk = union(enum) {
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
    layer_index: i32,
    pos: math.V2i,
    dim: math.V2i,
    decompressed: []u8,
};

fn parseChunk(buffer: *[]u8, bits_per_pixel: i32, allocator: mem.Allocator) !Chunk {
    const chunk_size = byteio.readU32le(buffer);
    const chunk_type = byteio.readU16le(buffer);

    const chunk_data_size = chunk_size - @sizeOf(u32) - @sizeOf(u16);
    const chunk_data = buffer.*[0..chunk_data_size];
    buffer.* = buffer.*[chunk_data_size..];

    _ = chunk_data;

    const chunk = switch (chunk_type) {
        0x0004 => Chunk{ .old_pallette1 = {} },
        0x0011 => Chunk{ .old_pallette2 = {} },
        0x2004 => Chunk{ .layer = {} },
        0x2005 => Chunk{ .cel = try parseCel(chunk_data, bits_per_pixel, allocator) },
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

fn parseCel(chunk_data_init: []u8, bits_per_pixel: i32, allocator: mem.Allocator) !Cel {
    var chunk_data = chunk_data_init;

    const layer_index = byteio.readU16le(&chunk_data);
    _ = layer_index;

    const x_pos = byteio.readI16le(&chunk_data);
    const y_pos = byteio.readI16le(&chunk_data);
    const pos = math.V2i{ .x = @intCast(i32, x_pos), .y = @intCast(i32, y_pos) };

    const opacity = byteio.readU8(&chunk_data);
    _ = opacity;

    const cel_type = byteio.readU16le(&chunk_data);

    chunk_data = chunk_data[7..];

    var dim: math.V2i = undefined;
    switch (cel_type) {
        0 => return error.CelTypeRawImageData,
        1 => return error.CelTypeLinked,
        2 => {
            dim.x = @intCast(i32, byteio.readU16le(&chunk_data));
            dim.y = @intCast(i32, byteio.readU16le(&chunk_data));
        },
        3 => return error.CelTypeCompressedTilemap,
        else => return error.CelTypeUnrecognized,
    }

    var decompressed = try allocator.alloc(u8, @intCast(usize, dim.x * dim.y * @divExact(bits_per_pixel, 8)));
    try zlib.decompress(chunk_data, decompressed);

    const result = Cel{
        .layer_index = @intCast(i32, layer_index),
        .pos = pos,
        .dim = dim,
        .decompressed = decompressed,
    };
    return result;
}
