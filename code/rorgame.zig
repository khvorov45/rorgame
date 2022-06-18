const std = @import("std");
const builtin = @import("builtin");

const math = @import("math.zig");
const time = @import("time.zig");
const wnd = @import("window.zig");
const mem = @import("mem.zig");
const rdr = @import("renderer.zig");
const log = @import("log.zig");
const fs = @import("filesystem.zig");
const Assets = @import("assets.zig").Assets;
const Input = @import("input.zig").Input;

const platform = if (builtin.os.tag == .windows) @import("rorgame_windows.zig") else @panic("unimplemented root");

pub fn panic(msg: []const u8, trace: ?*std.builtin.StackTrace) noreturn {
    _ = trace;
    @setCold(true);
    log.err("{s}", .{msg});
    @breakpoint();
    platform.panic_exit();
}

pub fn main() !void {
    var virtual_arena = try mem.VirtualArena.new(1 * mem.GIGABYTE, 1 * mem.MEGABYTE);
    const virtual_arena_allocator = virtual_arena.allocator();

    var window: wnd.Window = undefined;
    try window.init(math.V2i{ .x = 1280, .y = 720 });

    var assets_arena = try mem.Arena.new(1 * mem.MEGABYTE, virtual_arena_allocator);
    const assets_arena_allocator = assets_arena.allocator();
    var assets = try Assets.fromSources(assets_arena_allocator);

    var renderer = try rdr.Renderer.new(window.dim, assets.atlas, &assets.font, virtual_arena_allocator);

    var input = Input.new();

    var rect_topleft_x: f32 = 0;
    var rect_topleft_y: f32 = 0;
    var temp_frame_index: usize = 0;
    var frame_index: usize = 0;

    var timed_sections = time.Sections{.storage = undefined};

    while (window.is_running) {
        timed_sections.used = 0;

        //
        // SECTION Input
        //

        timed_sections.begin("input");
        window.pollForInput(&input);
        timed_sections.endLast();

        //
        // SECTION Update
        //

        timed_sections.begin("update");

        if (input.pressed(.f5)) {
            assets_arena.used = 0;
            assets = try Assets.fromSources(assets_arena_allocator);
        }

        if (input.down(.left)) {
            rect_topleft_x -= 0.5;
        }

        if (input.down(.right)) {
            rect_topleft_x += 0.5;
        }

        rect_topleft_x += 0.0;
        rect_topleft_y += 0.0;

        timed_sections.endLast();

        //
        // SECTION Render
        //

        timed_sections.begin("clear_buffers");
        renderer.clearBuffers();
        timed_sections.endLast();

        timed_sections.begin("animation");

        const req_group = assets.texture_groups.get(.commando_walk);
        const req_tex = req_group[frame_index];
        const temp_factor = 15;
        temp_frame_index = (temp_frame_index + 1) % (req_group.len * temp_factor);
        frame_index = temp_frame_index / temp_factor;

        renderer.drawRectTex(
            math.Rect2f{ .topleft = math.V2f{ .x = rect_topleft_x, .y = rect_topleft_y }, .dim = req_tex.dim.mulf(5) },
            req_tex,
        );

        timed_sections.endLast();

        timed_sections.begin("debug_atlases");
        renderer.drawWholeAtlas(math.V2f{.x = 500, .y = 200});
        timed_sections.endLast();

        timed_sections.begin("debug_timings");

        {
            var y_offset: f32 = 0;
            var total_ms: f32 = 0;
            for (timed_sections.storage[0..timed_sections.used]) |section| {
                var buf: [64]u8 = undefined;
                const text = try std.fmt.bufPrint(buf[0..], "{s}: {d:.3}", .{section.name, section.ms});
                renderer.drawTextline(text, math.V2f{.x = 0, .y = 100 + y_offset}, math.Color{.r = 1, .g = 1, .b = 1, .a = 1});
                y_offset += @intToFloat(f32, renderer.font.px_height_line);
                total_ms += section.ms;
            }
            var buf: [64]u8 = undefined;
            const text = try std.fmt.bufPrint(buf[0..], "total: {d:.3}", .{total_ms});
            renderer.drawTextline(text, math.V2f{.x = 0, .y = 100 + y_offset}, math.Color{.r = 1, .g = 1, .b = 1, .a = 1});
        }

        timed_sections.endLast();

        timed_sections.begin("display_pixels");
        window.displayPixels(renderer.draw_buffer.pixels, renderer.draw_buffer.dim);
        timed_sections.endLast();
    }
}
