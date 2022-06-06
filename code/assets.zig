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

pub const Assets = struct {
    atlas: Texture,
    commando: math.Rect2f,

    pub fn fromSources(allocator: mem.Allocator) !Assets {
        const commando_ase = try fs.readEntireFile("assets/commando.ase", allocator);
        const commando_textures = try ase.parse(commando_ase, allocator);

        const first_tex = commando_textures[0];
        const filled_rect = fr: {
            var first_filled_col = first_tex.dim.x;
            var first_filled_row = first_tex.dim.y;
            var last_filled_col: i32 = 0;
            var last_filled_row: i32 = 0;

            var row: i32 = 0;
            while (row < first_tex.dim.y) : (row += 1) {
                var col: i32 = 0;
                while (col < first_tex.dim.x) : (col += 1) {
                    const tex_index = row * first_tex.dim.x + col;
                    if (first_tex.pixels[@intCast(usize, tex_index)] != 0) {
                        first_filled_col = @minimum(first_filled_col, col);
                        first_filled_row = @minimum(first_filled_row, row);
                        last_filled_col = @maximum(last_filled_col, col);
                        last_filled_row = @maximum(last_filled_row, row);
                    }
                }
            }

            break :fr math.Rect2i{
                .topleft = math.V2i{ .x = first_filled_col, .y = first_filled_row },
                .dim = math.V2i{ .x = last_filled_col - first_filled_col + 1, .y = last_filled_row - first_filled_row + 1 },
            };
        };

        const atlas_dim = math.V2i{ .x = filled_rect.dim.x + 2, .y = filled_rect.dim.y + 2 };
        const atlas_pixels = try allocator.alloc(
            u32,
            @intCast(usize, atlas_dim.x * atlas_dim.y),
        );
        for (atlas_pixels) |*px| {
            px.* = 0;
        }

        {
            var row: i32 = filled_rect.topleft.y;
            while (row < filled_rect.topleft.y + filled_rect.dim.y) : (row += 1) {
                var col: i32 = filled_rect.topleft.x;
                const atlas_row = 1 + (row - filled_rect.topleft.y);
                while (col < filled_rect.topleft.x + filled_rect.dim.x) : (col += 1) {
                    const atlas_col = 1 + (col - filled_rect.topleft.x);
                    const tex_index = row * first_tex.dim.x + col;
                    const atlas_index = atlas_row * atlas_dim.x + atlas_col;

                    const texel = first_tex.pixels[@intCast(usize, tex_index)];
                    atlas_pixels[@intCast(usize, atlas_index)] = texel;
                }
            }
        }

        const result = Assets{
            .atlas = Texture{ .pixels = atlas_pixels, .dim = atlas_dim },
            .commando = math.Rect2f{ .topleft = math.V2f{ .x = 1, .y = 1 }, .dim = filled_rect.dim.to(math.V2f) },
        };
        return result;
    }
};
