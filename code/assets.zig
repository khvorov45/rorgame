const std = @import("std");
const panic = std.debug.panic;
const assert = std.debug.assert;
const EnumArray = std.enums.EnumArray;

const mem = @import("mem.zig");
const math = @import("math.zig");
const fs = @import("filesystem.zig");
const ase = @import("ase.zig");
const log = @import("log.zig");

const ft = @import("freetype/freetype_bindings.zig");

pub const Texture = struct {
    pixels: []u32,
    dim: math.V2i,
};

pub const TextureGroupID = enum {
    commando_idle,
    commando_walk,
    commando_use_skill1,
};

pub const GlyphInfo = struct {
    coords: math.Rect2i,
    advance_x: i32,
};

pub const Font = struct {
    px_height_font: i32,
    px_height_line: i32,
    alphamap: []u8,
    alphamap_glyphs: []GlyphInfo,
    firstchar: u32,
};

pub const Expandable = struct {
    width: i32,
    height: i32 = 0,
    current: math.V2i = math.V2i{},
    tallest_on_line: i32 = 0,

    pub fn add(self: *Expandable, dim: math.V2i) math.V2i {
        const width_left = self.width - self.current.x;

        if (dim.x > width_left) {
            assert(dim.x <= self.width);
            self.current.x = 0;
            self.current.y += self.tallest_on_line;
            self.tallest_on_line = 0;
        }

        const topleft = self.current;
        self.current.x += dim.x;
        const prev_tallest = self.tallest_on_line;
        self.tallest_on_line = @maximum(self.tallest_on_line, dim.y);
        self.height += @maximum(self.tallest_on_line - prev_tallest, 0);

        return topleft;
    }
};

pub const Assets = struct {
    atlas: Texture,
    texture_groups: EnumArray(TextureGroupID, []math.Rect2f),

    pub fn fromSources(allocator: mem.Allocator) !Assets {

        //
        // SECTION Bitmaps
        //

        const texture_groups_fields = @typeInfo(TextureGroupID).Enum.fields;
        var filled_rects: [texture_groups_fields.len][]math.Rect2i = undefined;
        var textures: [texture_groups_fields.len][]Texture = undefined;
        var total_rects: i32 = 0;
        var total_atlas_area: i32 = 0;

        inline for (texture_groups_fields) |tex_group_info, tex_group_index| {
            const ase_file = try fs.readEntireFile("assets/" ++ tex_group_info.name ++ ".ase", allocator);
            const file_textures = try ase.parse(ase_file, allocator);
            textures[tex_group_index] = file_textures;
            filled_rects[tex_group_index] = try allocator.alloc(math.Rect2i, file_textures.len);
            total_rects += @intCast(i32, file_textures.len);

            for (file_textures) |texture, tex_index| {
                const filled_rect = fr: {
                    var first_filled_col = texture.dim.x;
                    var first_filled_row = texture.dim.y;
                    var last_filled_col: i32 = 0;
                    var last_filled_row: i32 = 0;

                    var row: i32 = 0;
                    while (row < texture.dim.y) : (row += 1) {
                        var col: i32 = 0;
                        while (col < texture.dim.x) : (col += 1) {
                            const texel_index = row * texture.dim.x + col;
                            if (texture.pixels[@intCast(usize, texel_index)] != 0) {
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

                filled_rects[tex_group_index][tex_index] = filled_rect;
                total_atlas_area += (filled_rect.dim.x + 2) * (filled_rect.dim.y + 2);
            }
        }

        //
        // SECTION Fonts
        //

        // const firstchar = ' ';
        // const char_count = '~' - firstchar + 1;
        // const alphamap_glyphs = make([]GlyphInfo, char_count, font_allocator),

        // var ft_lib: ft.FT_Library = undefined;
        // _ = ft.FT_Init_FreeType(&ft_lib);

        // const font_file_data = try fs.readEntireFile("assets/LiberationMono-Regular.ttf", allocator);

        // var ft_face: ft.FT_Face = undefined;
        // _ = ft.FT_New_Memory_Face(ft_lib, font_file_data.ptr, @intCast(c_long, font_file_data.len), 0, &ft_face);

        // const px_height_font = 14;
        // _ = ft.FT_Set_Pixel_Sizes(ft_face, 0, px_height_font);

        // var req_font_atlas_size: i32 = 0;
        // for ch_index in 0..<char_count {
        //     loadAndRenderFTBitmap(firstchar, ch_index, ft_face)
        //     const bm = ft_face.glyph.bitmap
        //     req_font_atlas_size += bm.width * bm.rows
        // }

        //
        // SECTION Atlas
        //

        const areaFudge = 1.5;
        var atlas_dim_builder = Expandable{ .width = @floatToInt(i32, @sqrt(@intToFloat(f32, total_atlas_area) * areaFudge)) };
        var future_atlas_topleft: [texture_groups_fields.len][]math.V2i = undefined;

        inline for (texture_groups_fields) |tex_group_info, tex_group_index| {
            _ = tex_group_info;
            const tex_group_filled_rects = filled_rects[tex_group_index];
            future_atlas_topleft[tex_group_index] = try allocator.alloc(math.V2i, tex_group_filled_rects.len);
            for (tex_group_filled_rects) |filled_rect, rect_index| {
                const builder_topleft = atlas_dim_builder.add(filled_rect.dim.add(math.V2i{ .x = 2, .y = 2 }));
                future_atlas_topleft[tex_group_index][rect_index] = builder_topleft.add(math.V2i{ .x = 1, .y = 1 });
            }
        }

        const atlas_dim = math.V2i{ .x = atlas_dim_builder.width, .y = atlas_dim_builder.height };
        const atlas_pixels = try allocator.alloc(
            u32,
            @intCast(usize, atlas_dim.x * atlas_dim.y),
        );
        for (atlas_pixels) |*px| {
            px.* = 0;
        }

        var texture_groups: EnumArray(TextureGroupID, []math.Rect2f) = undefined;
        var tex_rects = try allocator.alloc(math.Rect2f, @intCast(usize, total_rects));

        inline for (texture_groups_fields) |tex_group_info, tex_group_index| {
            _ = tex_group_info;
            const tex_group_filled_rects = filled_rects[tex_group_index];
            const tex_group_atlas_rects = tex_rects[0..tex_group_filled_rects.len];
            tex_rects = tex_rects[tex_group_filled_rects.len..];
            texture_groups.set(@intToEnum(TextureGroupID, tex_group_info.value), tex_group_atlas_rects);

            for (tex_group_filled_rects) |filled_rect, rect_index| {
                const atlas_topleft = future_atlas_topleft[tex_group_index][rect_index];
                const texture = textures[tex_group_index][rect_index];

                tex_group_atlas_rects[rect_index] = math.Rect2f{ .topleft = atlas_topleft.to(math.V2f), .dim = filled_rect.dim.to(math.V2f) };

                var row: i32 = filled_rect.topleft.y;
                while (row < filled_rect.topleft.y + filled_rect.dim.y) : (row += 1) {
                    const atlas_row = (row - filled_rect.topleft.y) + atlas_topleft.y;

                    var col: i32 = filled_rect.topleft.x;
                    while (col < filled_rect.topleft.x + filled_rect.dim.x) : (col += 1) {
                        const atlas_col = (col - filled_rect.topleft.x) + atlas_topleft.x;
                        const tex_index = row * texture.dim.x + col;
                        const atlas_index = atlas_row * atlas_dim.x + atlas_col;

                        const texel = texture.pixels[@intCast(usize, tex_index)];
                        atlas_pixels[@intCast(usize, atlas_index)] = texel;
                    }
                }
            }
        }

        const result = Assets{
            .atlas = Texture{ .pixels = atlas_pixels, .dim = atlas_dim },
            .texture_groups = texture_groups,
        };
        return result;
    }

    fn loadAndRenderFTBitmap(firstchar: u32, ch_index: i32, ft_face: ft.Face) void {
        const ch = firstchar + @intCast(u32, ch_index);
        const ft_glyph_index = ft.FT_Get_Char_Index(ft_face, ch);
        ft.FT_Load_Glyph(ft_face, ft_glyph_index, ft.FT_LOAD_DEFAULT);
        if (ft_face.glyph.format != ft.FT_Glyph_Format.BITMAP) {
            _ = ft.FT_Render_Glyph(ft_face.glyph, ft.Render_Mode.NORMAL);
        }
    }
};
