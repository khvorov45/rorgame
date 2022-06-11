const std = @import("std");
const panic = std.debug.panic;

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
    dim: math.V2i = math.V2i{},
    free: math.Rect2i = math.Rect2i{},

    pub fn accomodate(self: *Expandable, dim: math.V2i) math.V2i {
        // TODO(khvorov) An actual version of this
        const topleft = self.free.topleft;

        const lack = dim.sub(self.free.dim).max(math.V2i{ .x = 0, .y = 0 });
        self.dim = self.dim.add(lack);
        self.free.dim = self.free.dim.add(lack);
        self.free.topleft.x += dim.x;
        self.free.dim.x -= dim.x;

        return topleft;
    }
};

pub const Assets = struct {
    atlas: Texture,

    pub fn fromSources(allocator: mem.Allocator) !Assets {
        var atlas_dim_builder = Expandable{};

        //
        // SECTION Bitmaps
        //

        const bitmap_files = [_][]const u8{"assets/commando.ase"};

        var filled_rects: [bitmap_files.len][]math.Rect2i = undefined;
        var future_atlas_topleft: [bitmap_files.len][]math.V2i = undefined;
        var textures: [bitmap_files.len][]Texture = undefined;

        inline for (bitmap_files) |file, file_index| {
            const ase_file = try fs.readEntireFile(file, allocator);
            const file_textures = try ase.parse(ase_file, allocator);
            textures[file_index] = file_textures;
            filled_rects[file_index] = try allocator.alloc(math.Rect2i, file_textures.len);
            future_atlas_topleft[file_index] = try allocator.alloc(math.V2i, file_textures.len);

            for (file_textures) |texture, file_texture_index| {
                const filled_rect = fr: {
                    var first_filled_col = texture.dim.x;
                    var first_filled_row = texture.dim.y;
                    var last_filled_col: i32 = 0;
                    var last_filled_row: i32 = 0;

                    var row: i32 = 0;
                    while (row < texture.dim.y) : (row += 1) {
                        var col: i32 = 0;
                        while (col < texture.dim.x) : (col += 1) {
                            const tex_index = row * texture.dim.x + col;
                            if (texture.pixels[@intCast(usize, tex_index)] != 0) {
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

                filled_rects[file_index][file_texture_index] = filled_rect;
                future_atlas_topleft[file_index][file_texture_index] = atlas_dim_builder.accomodate(filled_rect.dim);
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

        const atlas_dim = atlas_dim_builder.dim.add(math.V2i{ .x = 2, .y = 2 });
        const atlas_pixels = try allocator.alloc(
            u32,
            @intCast(usize, atlas_dim.x * atlas_dim.y),
        );
        for (atlas_pixels) |*px| {
            px.* = 0;
        }

        for (filled_rects) |file_filled_rects, file_index| {
            for (file_filled_rects) |filled_rect, rect_index| {
                const atlas_topleft = future_atlas_topleft[file_index][rect_index];
                const texture = textures[file_index][rect_index];

                var row: i32 = filled_rect.topleft.y;
                while (row < filled_rect.topleft.y + filled_rect.dim.y) : (row += 1) {
                    const atlas_row = 1 + (row - filled_rect.topleft.y) + atlas_topleft.y;

                    var col: i32 = filled_rect.topleft.x;
                    while (col < filled_rect.topleft.x + filled_rect.dim.x) : (col += 1) {
                        const atlas_col = 1 + (col - filled_rect.topleft.x) + atlas_topleft.x;
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
