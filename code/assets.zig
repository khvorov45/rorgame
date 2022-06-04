const std = @import("std");
const panic = std.debug.panic;

const mem = @import("mem.zig");
const math = @import("math.zig");
const fs = @import("filesystem.zig");
const ase = @import("ase.zig");
const log = @import("log.zig");

pub const Texture = struct {
    pixels: []u32,
    dim: math.V2i,
};

pub fn pack(allocator: mem.Allocator) !void {
    const commando_ase = try fs.readEntireFile("assets/commando.ase", allocator);
    _ = try ase.parse(commando_ase);
}

pub fn unpack(allocator: mem.Allocator) !Texture {
    const atlas_dim = math.V2i{ .x = 4, .y = 4 };
    const atlas_pixels = try allocator.alloc(u32, @intCast(usize, atlas_dim.x * atlas_dim.y));

    atlas_pixels[0] = 0;
    atlas_pixels[1] = 0;
    atlas_pixels[2] = 0;
    atlas_pixels[3] = 0;

    atlas_pixels[4] = 0;
    atlas_pixels[5] = 0xFFFF0000;
    atlas_pixels[6] = 0xFF00FF00;
    atlas_pixels[7] = 0;

    atlas_pixels[8] = 0;
    atlas_pixels[9] = 0xFF0000FF;
    atlas_pixels[10] = 0xFFFF00FF;
    atlas_pixels[11] = 0;

    atlas_pixels[12] = 0;
    atlas_pixels[13] = 0;
    atlas_pixels[14] = 0;
    atlas_pixels[15] = 0;

    const atlas = Texture{ .pixels = atlas_pixels, .dim = atlas_dim };
    return atlas;
}
