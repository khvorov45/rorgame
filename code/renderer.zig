const panic = @import("std").debug.panic;

const math = @import("math.zig");
const mem = @import("mem.zig");

const Texture = @import("assets.zig").Texture;

pub const Renderer = struct {
    draw_buffer: Texture,
    atlas: Texture,

    pub fn new(dim: math.V2i, atlas: Texture, allocator: mem.Allocator) !Renderer {
        const draw_buf = Texture{
            .pixels = try allocator.alloc(u32, @intCast(usize, dim.x * dim.y)),
            .dim = dim,
        };
        return Renderer{ .draw_buffer = draw_buf, .atlas = atlas };
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

        const topleft_aligned = rect_clipped.topleft.floor();
        const bottomright_aligned = bottomright.ceil();

        var row = @floatToInt(i32, topleft_aligned.y);
        while (row < @floatToInt(i32, bottomright_aligned.y)) : (row += 1) {
            var col = @floatToInt(i32, topleft_aligned.x);
            while (col < @floatToInt(i32, bottomright_aligned.x)) : (col += 1) {
                var final_color = color32;

                if (texture_coords) |coords| {
                    const u_left = (@intToFloat(f32, col) - rect.topleft.x) / rect.dim.x;
                    const v_top = (@intToFloat(f32, row) - rect.topleft.y) / rect.dim.y;

                    const u_right = (@intToFloat(f32, col + 1) - rect.topleft.x) / rect.dim.x;
                    const v_bottom = (@intToFloat(f32, row + 1) - rect.topleft.y) / rect.dim.y;

                    const tex_colf_left = u_left * coords.dim.x + coords.topleft.x;
                    const tex_rowf_top = v_top * coords.dim.y + coords.topleft.y;

                    const tex_colf_right = u_right * coords.dim.x + coords.topleft.x;
                    const tex_rowf_bottom = v_bottom * coords.dim.y + coords.topleft.y;

                    const tex_col_left = @floatToInt(i32, tex_colf_left);
                    const tex_row_top = @floatToInt(i32, tex_rowf_top);

                    const tex_col_right = @floatToInt(i32, tex_colf_right);
                    const tex_row_bottom = @floatToInt(i32, tex_rowf_bottom);

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

                    const px_on_left = (@floor(tex_colf_left + 1) - tex_colf_left) / (tex_colf_right - tex_colf_left);
                    const px_on_top = (@floor(tex_rowf_top + 1) - tex_rowf_top) / (tex_rowf_bottom - tex_rowf_top);

                    const blend_top = texel_topleft.mul(px_on_left).add(texel_topright.mul(1 - px_on_left));
                    const blend_bottom = texel_bottomleft.mul(px_on_left).add(texel_bottomright.mul(1 - px_on_left));
                    const blend = blend_top.mul(px_on_top).add(blend_bottom.mul(1 - px_on_top));

                    final_color = blend.toU32ARGB();
                }

                // TODO(khvorov) Alpha
                const px_index = @intCast(usize, row * renderer.draw_buffer.dim.x + col);
                renderer.draw_buffer.pixels[px_index] = final_color;
            }
        }
    }
};
