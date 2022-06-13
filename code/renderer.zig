const panic = @import("std").debug.panic;

const math = @import("math.zig");
const mem = @import("mem.zig");

const assets = @import("assets.zig");
const Texture = assets.Texture;
const TextureAlpha = assets.TextureAlpha;

pub const Renderer = struct {
    draw_buffer: Texture,
    atlas: Texture,
    atlas_alpha: TextureAlpha,

    pub fn new(dim: math.V2i, atlas: Texture, atlas_alpha: TextureAlpha, allocator: mem.Allocator) !Renderer {
        const draw_buf = Texture{
            .pixels = try allocator.alloc(u32, @intCast(usize, dim.x * dim.y)),
            .dim = dim,
        };
        return Renderer{ .draw_buffer = draw_buf, .atlas = atlas, .atlas_alpha = atlas_alpha };
    }

    pub fn clearBuffers(renderer: *Renderer) void {
        for (renderer.draw_buffer.pixels) |*pixel| {
            pixel.* = 0;
        }
    }

    fn clipRectToDrawBuffer(renderer: *Renderer, rect: math.Rect2f) math.Rect2f {
        const result = rect.clipToRect(math.Rect2f{ .topleft = math.V2f{ .x = 0, .y = 0 }, .dim = renderer.draw_buffer.dim.to(math.V2f) });
        return result;
    }

    pub fn drawRect(renderer: *Renderer, rect: math.Rect2f, color: math.Color) void {
        const rect_clipped = renderer.clipRectToDrawBuffer(rect);
        const bottomright = rect_clipped.bottomright();

        const topleft_aligned = rect_clipped.topleft.floor();
        const bottomright_aligned = bottomright.ceil();

        var row = @floatToInt(i32, topleft_aligned.y);
        while (row < @floatToInt(i32, bottomright_aligned.y)) : (row += 1) {
            var col = @floatToInt(i32, topleft_aligned.x);
            while (col < @floatToInt(i32, bottomright_aligned.x)) : (col += 1) {
                const colf = @intToFloat(f32, col);
                const rowf = @intToFloat(f32, row);
                const alpha_reduce_h = @maximum(rect.topleft.x - colf, 0) + @maximum(colf + 1 - (rect.topleft.x + rect.dim.x), 0);
                const alpha_reduce_v = @maximum(rect.topleft.y - rowf, 0) + @maximum(rowf + 1 - (rect.topleft.y + rect.dim.y), 0);

                const final_color = math.Color{ .r = color.r, .g = color.g, .b = color.b, .a = color.a * (1 - alpha_reduce_h) * (1 - alpha_reduce_v) };

                const px_index = @intCast(usize, row * renderer.draw_buffer.dim.x + col);
                const old_px = &renderer.draw_buffer.pixels[px_index];
                const old_col = math.Color.fromU32ARGB(old_px.*);
                const new_col = final_color.mul(final_color.a).add(old_col.mul(1 - final_color.a));
                const new_col32 = new_col.toU32ARGB();
                old_px.* = new_col32;
            }
        }
    }

    pub fn drawRectTex(renderer: *Renderer, rect: math.Rect2f, texture_coords: math.Rect2f) void {
        const rect_clipped = renderer.clipRectToDrawBuffer(rect);
        const bottomright = rect_clipped.bottomright();

        const topleft_aligned = rect_clipped.topleft.floor();
        const bottomright_aligned = bottomright.ceil();

        var row = @floatToInt(i32, topleft_aligned.y);
        while (row < @floatToInt(i32, bottomright_aligned.y)) : (row += 1) {
            var col = @floatToInt(i32, topleft_aligned.x);
            while (col < @floatToInt(i32, bottomright_aligned.x)) : (col += 1) {
                const u_left = (@intToFloat(f32, col) - rect.topleft.x) / rect.dim.x;
                const v_top = (@intToFloat(f32, row) - rect.topleft.y) / rect.dim.y;

                const u_right = (@intToFloat(f32, col + 1) - rect.topleft.x) / rect.dim.x;
                const v_bottom = (@intToFloat(f32, row + 1) - rect.topleft.y) / rect.dim.y;

                const tex_colf_left = u_left * texture_coords.dim.x + texture_coords.topleft.x;
                const tex_rowf_top = v_top * texture_coords.dim.y + texture_coords.topleft.y;

                const tex_colf_right = u_right * texture_coords.dim.x + texture_coords.topleft.x;
                const tex_rowf_bottom = v_bottom * texture_coords.dim.y + texture_coords.topleft.y;

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

                const px_index = @intCast(usize, row * renderer.draw_buffer.dim.x + col);
                const old_px = &renderer.draw_buffer.pixels[px_index];
                const old_col = math.Color.fromU32ARGB(old_px.*);
                const new_col = blend.mul(blend.a).add(old_col.mul(1 - blend.a));
                const new_col32 = new_col.toU32ARGB();
                old_px.* = new_col32;
            }
        }
    }

    pub fn drawRectAlpha(renderer: *Renderer, rect: math.Rect2f, color: math.Color, texture_coords: math.Rect2f) void {
        const rect_clipped = renderer.clipRectToDrawBuffer(rect);
        const bottomright = rect_clipped.bottomright();

        const topleft_aligned = rect_clipped.topleft.floor();
        const bottomright_aligned = bottomright.ceil();

        var row = @floatToInt(i32, topleft_aligned.y);
        while (row < @floatToInt(i32, bottomright_aligned.y)) : (row += 1) {
            var col = @floatToInt(i32, topleft_aligned.x);
            while (col < @floatToInt(i32, bottomright_aligned.x)) : (col += 1) {
                const u = (@intToFloat(f32, col) + 0.5 - rect.topleft.x) / rect.dim.x;
                const v = (@intToFloat(f32, row) + 0.5 - rect.topleft.y) / rect.dim.y;

                const tex_colf = u * texture_coords.dim.x + texture_coords.topleft.x - 0.5;
                const tex_rowf = v * texture_coords.dim.y + texture_coords.topleft.y - 0.5;

                const tex_col_left = @floatToInt(i32, tex_colf);
                const tex_row_top = @floatToInt(i32, tex_rowf);

                const tex_col_right = tex_col_left + 1;
                const tex_row_bottom = tex_row_top + 1;

                const tex_from_left = tex_colf - @floor(tex_colf);
                const tex_from_top = tex_rowf - @floor(tex_rowf);

                const tex_index_topleft = @intCast(usize, tex_row_top * renderer.atlas_alpha.dim.x + tex_col_left);
                const tex_index_topright = @intCast(usize, tex_row_top * renderer.atlas_alpha.dim.x + tex_col_right);
                const tex_index_bottomleft = @intCast(usize, tex_row_bottom * renderer.atlas_alpha.dim.x + tex_col_left);
                const tex_index_bottomright = @intCast(usize, tex_row_bottom * renderer.atlas_alpha.dim.x + tex_col_right);

                const texel_topleft_u8 = renderer.atlas_alpha.alpha[tex_index_topleft];
                const texel_topright_u8 = renderer.atlas_alpha.alpha[tex_index_topright];
                const texel_bottomleft_u8 = renderer.atlas_alpha.alpha[tex_index_bottomleft];
                const texel_bottomright_u8 = renderer.atlas_alpha.alpha[tex_index_bottomright];

                const texel_topleft = math.Color{ .r = color.r, .g = color.g, .b = color.b, .a = @intToFloat(f32, texel_topleft_u8) / 255 * color.a };
                const texel_topright = math.Color{ .r = color.r, .g = color.g, .b = color.b, .a = @intToFloat(f32, texel_topright_u8) / 255 * color.a };
                const texel_bottomleft = math.Color{ .r = color.r, .g = color.g, .b = color.b, .a = @intToFloat(f32, texel_bottomleft_u8) / 255 * color.a };
                const texel_bottomright = math.Color{ .r = color.r, .g = color.g, .b = color.b, .a = @intToFloat(f32, texel_bottomright_u8) / 255 * color.a };

                const blend_top = texel_topleft.lerp(tex_from_left, texel_topright);
                const blend_bottom = texel_bottomleft.lerp(tex_from_left, texel_bottomright);
                const blend = blend_top.lerp(tex_from_top, blend_bottom);

                const px_index = @intCast(usize, row * renderer.draw_buffer.dim.x + col);
                const old_px = &renderer.draw_buffer.pixels[px_index];
                const old_col = math.Color.fromU32ARGB(old_px.*);
                const new_col = blend.mul(blend.a).add(old_col.mul(1 - blend.a));
                const new_col32 = new_col.toU32ARGB();
                old_px.* = new_col32;
            }
        }
    }

    pub fn drawRectOutline(renderer: *Renderer, rect: math.Rect2f, color: math.Color) void {
        const thickness = 2;

        const top = math.Rect2f{ .topleft = rect.topleft, .dim = math.V2f{ .x = rect.dim.x, .y = thickness } };
        const bottom = math.Rect2f{ .topleft = math.V2f{ .x = rect.topleft.x, .y = rect.topleft.y + rect.dim.y - thickness }, .dim = top.dim };
        const left = math.Rect2f{ .topleft = rect.topleft, .dim = math.V2f{ .x = thickness, .y = rect.dim.y } };
        const right = math.Rect2f{ .topleft = math.V2f{ .x = rect.topleft.x + rect.dim.x - thickness, .y = rect.topleft.y }, .dim = left.dim };

        renderer.drawRect(top, color);
        renderer.drawRect(bottom, color);
        renderer.drawRect(left, color);
        renderer.drawRect(right, color);
    }
};
