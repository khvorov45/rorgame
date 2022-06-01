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
        atl.pixels[2] = 0xFF00FF00;
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

        const topleft_aligned = rect_clipped.topleft.round();
        const bottomright_aligned = bottomright.round();

        const misalign = rect_clipped.topleft.add(math.V2f{ .x = 1.0, .y = 1.0 }).floor().sub(rect_clipped.topleft);

        var row = @floatToInt(i32, topleft_aligned.y);
        while (row < @floatToInt(i32, bottomright_aligned.y)) : (row += 1) {
            var col = @floatToInt(i32, topleft_aligned.x);
            while (col < @floatToInt(i32, bottomright_aligned.x)) : (col += 1) {
                var final_color = color32;

                if (texture_coords) |coords| {
                    const u = (@intToFloat(f32, col) + 0.5 - rect.topleft.x) / rect.dim.x;
                    const v = (@intToFloat(f32, row) + 0.5 - rect.topleft.y) / rect.dim.y;
                    const tex_colf = u * coords.dim.x + coords.topleft.x - 0.5;
                    const tex_rowf = v * coords.dim.y + coords.topleft.y - 0.5;

                    const tex_col_left = @floatToInt(i32, tex_colf);
                    const tex_col_right = @floatToInt(i32, @minimum(tex_colf + 1, coords.dim.x - 1 + coords.topleft.x));

                    const tex_row_top = @floatToInt(i32, tex_rowf);
                    const tex_row_bottom = @floatToInt(i32, @minimum(tex_rowf + 1, coords.dim.y - 1 + coords.topleft.y));

                    const tex_index_topleft = @intCast(usize, tex_row_top * renderer.atlas.dim.x + tex_col_left);
                    const tex_index_topright = @intCast(usize, tex_row_top * renderer.atlas.dim.x + tex_col_right);
                    const tex_index_bottomleft = @intCast(usize, tex_row_bottom * renderer.atlas.dim.x + tex_col_left);
                    const tex_index_bottomright = @intCast(usize, tex_row_bottom * renderer.atlas.dim.x + tex_col_right);

                    const texel_topleft_u32 = renderer.atlas.pixels[tex_index_topleft];
                    const texel_topright_u32 = renderer.atlas.pixels[tex_index_topright];
                    const texel_bottomleft_u32 = renderer.atlas.pixels[tex_index_bottomleft];
                    const texel_bottomright_u32 = renderer.atlas.pixels[tex_index_bottomright];

                    const texel_topleft = math.Color.fromU32ARGB(texel_topleft_u32);
                    const texel_topright = math.Color.fromU32ARGB(texel_topright_u32);
                    const texel_bottomleft = math.Color.fromU32ARGB(texel_bottomleft_u32);
                    const texel_bottomright = math.Color.fromU32ARGB(texel_bottomright_u32);

                    //
                    //
                    //

                    const col_nearest = @floatToInt(i32, u * (coords.dim.x - 1) + 0.5);
                    const row_nearest = @floatToInt(i32, v * (coords.dim.x - 1) + 0.5);

                    const next_u = @minimum((@intToFloat(f32, col + 1) - rect.topleft.x) / (rect.dim.x - 1), 1);
                    const next_v = @minimum((@intToFloat(f32, row + 1) - rect.topleft.y) / (rect.dim.y - 1), 1);

                    const next_col_nearest = @floatToInt(i32, next_u * (coords.dim.x - 1) + 0.5);
                    const next_row_nearest = @floatToInt(i32, next_v * (coords.dim.x - 1) + 0.5);

                    var blend_top = texel_topleft;
                    var blend_bottom = texel_bottomleft;

                    if (next_col_nearest != col_nearest) {
                        blend_top = texel_topleft.mul(misalign.x).add(texel_topright.mul(1 - misalign.x));
                        blend_bottom = texel_bottomleft.mul(misalign.x).add(texel_bottomright.mul(1 - misalign.x));
                    } else if (col_nearest == tex_col_right) {
                        blend_top = texel_topright;
                        blend_bottom = texel_bottomright;
                    }

                    var blend = blend_top;
                    if (next_row_nearest != row_nearest) {
                        blend = blend_top.mul(misalign.y).add(blend_bottom.mul(1 - misalign.y));
                    } else if (row_nearest == tex_row_bottom) {
                        blend = blend_bottom;
                    }

                    final_color = blend.toU32ARGB();
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
