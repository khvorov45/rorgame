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

        const atlas_dim = math.V2i{ .x = 50, .y = 50 };
        const atl = Texture{
            .pixels = try allocator.alloc(u32, @intCast(usize, atlas_dim.x * atlas_dim.y)),
            .dim = atlas_dim,
        };

        for (atl.pixels) |*pixel| {
            pixel.* = 0xFFFFFF00;
        }

        return Renderer{ .draw_buffer = draw_buf, .atlas = atl };
    }

    pub fn clearBuffers(renderer: *Renderer) void {
        for (renderer.draw_buffer.pixels) |*pixel| {
            pixel.* = 0;
        }
    }

    pub fn drawRect(renderer: *Renderer, rect: math.Rect2i, color: math.Color, texture_coords: ?math.Rect2i) void {
        const color32 = color.toU32ARGB();

        const rect_clipped = rect.clipToRect(math.Rect2i{ .topleft = math.V2i{ .x = 0, .y = 0 }, .dim = renderer.draw_buffer.dim });
        const bottomright = rect_clipped.bottomright();

        var row = rect_clipped.topleft.y;
        while (row < bottomright.y) : (row += 1) {
            var col = rect_clipped.topleft.x;
            while (col < bottomright.x) : (col += 1) {
                var final_color = color32;

                if (texture_coords) |coords| {
                    const u = @intToFloat(f32, col - rect.topleft.x) / @intToFloat(f32, rect.dim.x - 1);
                    const v = @intToFloat(f32, row - rect.topleft.y) / @intToFloat(f32, rect.dim.y - 1);
                    const tex_col = @floatToInt(i32, u * @intToFloat(f32, coords.dim.x - 1)) + coords.topleft.x;
                    const tex_row = @floatToInt(i32, v * @intToFloat(f32, coords.dim.y - 1)) + coords.topleft.y;

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
