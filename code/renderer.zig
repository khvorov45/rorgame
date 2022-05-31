const panic = @import("std").debug.panic;

const math = @import("math.zig");
const mem = @import("mem.zig");

pub const Renderer = struct {
    draw_buffer: Texture,
    atlas: Texture,

    pub fn new(dim: math.V2i, allocator: mem.Allocator) !Renderer {
        const draw_buf = Texture{
            .pixels = try allocator.alloc(u32, @intCast(usize, dim.x * dim.y)),
            .dim = dim,
        };

        const atlas_dim = math.V2i{ .x = 2, .y = 2 };
        const atl = Texture{
            .pixels = try allocator.alloc(u32, @intCast(usize, atlas_dim.x * atlas_dim.y)),
            .dim = atlas_dim,
        };
        atl.pixels[0] = 0xFFFF0000;
        atl.pixels[1] = 0xFF0000FF;
        atl.pixels[2] = 0xFF0FF000;
        atl.pixels[3] = 0xFFFF00FF;

        return Renderer{ .draw_buffer = draw_buf, .atlas = atl };
    }

    pub fn clearBuffers(renderer: *Renderer) void {
        for (renderer.draw_buffer.pixels) |*pixel| {
            pixel.* = 0;
        }
    }

    pub fn drawRect(renderer: *Renderer, rect: math.Rect2f, color: math.Color, texture_coords: ?math.Rect2f) void {
        const color32 = color.toU32ARGB();

        const rect_clipped = rect.clipToRect(math.Rect2f{ .topleft = math.V2f{ .x = 0, .y = 0 }, .dim = renderer.draw_buffer.dim.to(math.V2f) });
        const bottomright = rect_clipped.bottomright();

        var row = @floatToInt(i32, rect_clipped.topleft.y + 1);
        while (row < @floatToInt(i32, bottomright.y)) : (row += 1) {
            var col = @floatToInt(i32, rect_clipped.topleft.x + 1);
            while (col < @floatToInt(i32, bottomright.x)) : (col += 1) {
                var final_color = color32;

                if (texture_coords) |coords| {
                    const u = (@intToFloat(f32, col) - rect.topleft.x) / (rect.dim.x - 1);
                    const v = (@intToFloat(f32, row) - rect.topleft.y) / (rect.dim.y - 1);
                    const tex_col = @floatToInt(i32, u * (coords.dim.x - 1) + (coords.topleft.x) + 0.5);
                    const tex_row = @floatToInt(i32, v * (coords.dim.y - 1) + (coords.topleft.y) + 0.5);

                    const tex_index = @intCast(usize, tex_row * renderer.atlas.dim.x + tex_col);
                    const texel = renderer.atlas.pixels[tex_index];
                    final_color = texel;
                }

                const px_index = @intCast(usize, row * renderer.draw_buffer.dim.x + col);
                renderer.draw_buffer.pixels[px_index] = final_color;
            }
        }
    }
};

pub const Texture = struct {
    pixels: []u32,
    dim: math.V2i,
};
