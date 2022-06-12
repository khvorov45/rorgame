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
        const rect_clipped = rect.clipToRect(math.Rect2f{ .topleft = math.V2f{ .x = 0, .y = 0 }, .dim = renderer.draw_buffer.dim.to(math.V2f) });
        const bottomright = rect_clipped.bottomright();

        const topleft_aligned = rect_clipped.topleft.floor();
        const bottomright_aligned = bottomright.ceil();

        var row = @floatToInt(i32, topleft_aligned.y);
        while (row < @floatToInt(i32, bottomright_aligned.y)) : (row += 1) {
            var col = @floatToInt(i32, topleft_aligned.x);
            while (col < @floatToInt(i32, bottomright_aligned.x)) : (col += 1) {
                var final_tex_color = color;

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

                    const px_on_left = @minimum((@floor(tex_colf_left + 1) - tex_colf_left) / (tex_colf_right - tex_colf_left), 1);
                    const px_on_top = @minimum((@floor(tex_rowf_top + 1) - tex_rowf_top) / (tex_rowf_bottom - tex_rowf_top), 1);

                    const blend_top = texel_topleft.transitionBlend(px_on_left, texel_topright);
                    const blend_bottom = texel_bottomleft.transitionBlend(px_on_left, texel_bottomright);
                    const blend = blend_top.transitionBlend(px_on_top, blend_bottom);

                    final_tex_color = blend;
                }

                const px_index = @intCast(usize, row * renderer.draw_buffer.dim.x + col);
                const old_px = &renderer.draw_buffer.pixels[px_index];
                const old_col = math.Color.fromU32ARGB(old_px.*);
                const new_col = final_tex_color.mul(final_tex_color.a).add(old_col.mul(1 - final_tex_color.a));
                const new_col32 = new_col.toU32ARGB();
                old_px.* = new_col32;
            }
        }
    }

    // TODO(khvorov) Draw rect with a texture with nearest sampling
    // TODO(khvorov) Probably also a plain draw rect with no textures as a separate proc

    pub fn drawRectOutline(renderer: *Renderer, rect: math.Rect2f, color: math.Color) void {
        const thickness = 1;

        const top = math.Rect2f{ .topleft = rect.topleft, .dim = math.V2f{ .x = rect.dim.x, .y = thickness } };
        const bottom = math.Rect2f{ .topleft = math.V2f{ .x = rect.topleft.x, .y = rect.topleft.y + rect.dim.y - thickness }, .dim = top.dim };
        const left = math.Rect2f{ .topleft = rect.topleft, .dim = math.V2f{ .x = thickness, .y = rect.dim.y } };
        const right = math.Rect2f{ .topleft = math.V2f{ .x = rect.topleft.x + rect.dim.x - thickness, .y = rect.topleft.y }, .dim = left.dim };

        renderer.drawRect(top, color, null);
        renderer.drawRect(bottom, color, null);
        renderer.drawRect(left, color, null);
        renderer.drawRect(right, color, null);
    }
};
