const std = @import("std");
const builtin = @import("builtin");

const math = @import("math.zig");
const wnd = @import("window.zig");
const mem = @import("mem.zig");
const rdr = @import("renderer.zig");
const log = @import("log.zig");
const fs = @import("filesystem.zig");
const Assets = @import("assets.zig").Assets;
const Input = @import("input.zig").Input;
const time = @import("time.zig");

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
    var rect_topleft_y: f32 = 100;
    var temp_frame_index: usize = 0;
    var frame_index: usize = 0;

    var timer = time.Timer.new();
    const target_frame_ms: f32 = 1000.0 / 60.0;

    while (window.is_running) {

        timer.begin(.frame);
        timer.begin(.work);

        //
        // SECTION Input
        //

        timer.begin(.input);
        window.pollForInput(&input);
        timer.end();

        //
        // SECTION Update
        //

        timer.begin(.update);

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

        timer.end();

        //
        // SECTION Render
        //

        timer.begin(.clear_buffers);
        renderer.clearBuffers();
        timer.end();

        timer.begin(.animation);

        const req_group = assets.texture_groups.get(.commando_walk);
        const req_tex = req_group[frame_index];
        const temp_factor = 15;
        temp_frame_index = (temp_frame_index + 1) % (req_group.len * temp_factor);
        frame_index = temp_frame_index / temp_factor;

        renderer.drawRectTex(
            math.Rect2f{ .topleft = math.V2f{ .x = rect_topleft_x, .y = rect_topleft_y }, .dim = req_tex.dim.mulf(5) },
            req_tex,
        );

        timer.end();

        if (true) {
            timer.begin(.debug_atlases);
            renderer.drawWholeAtlas(math.V2f{.x = 500, .y = 200});
            timer.end();
        }

        {
            timer.begin(.debug_timings);

            var y_offset: f32 = 0;
            var iter = timer.getLastFrameSections().iterator();
            while (iter.next()) |entry| {
                const section = entry.value;
                if (section.ms) |duration| {
                    var buf: [64]u8 = undefined;
                    var buf_index: usize = 0;
                    {
                        var nest_level = section.nest_level;
                        while (nest_level > 0) : (nest_level -= 1) {
                            const str = try std.fmt.bufPrint(buf[buf_index..], "    ", .{});
                            buf_index += str.len;
                        }
                    }
                    const text = try std.fmt.bufPrint(buf[buf_index..], "{s}: {d:.3}", .{@tagName(entry.key), duration});
                    renderer.drawTextline(buf[0..buf_index + text.len], math.V2f{.x = 0, .y = y_offset}, math.Color{.r = 1, .g = 1, .b = 1, .a = 1});
                    y_offset += @intToFloat(f32, renderer.font.px_height_line);
                }
            }

            timer.end();
        }

        timer.begin(.display_pixels);
        window.displayPixels(renderer.draw_buffer.pixels, renderer.draw_buffer.dim);
        timer.end();

        timer.end(); // NOTE(khvorov) work

        timer.begin(.wait);
        {
            timer.begin(.sleep);
            const ms_remaining = target_frame_ms - timer.getMsFromSectionStart(.frame);
            timer.sleep(ms_remaining);
            timer.end();
        }

        {
            timer.begin(.spin);
            const time_so_far = timer.getMsFromSectionStart(.frame);
            var ms_remaining = target_frame_ms - time_so_far;
            while (ms_remaining > 0) {
                ms_remaining = target_frame_ms - timer.getMsFromSectionStart(.frame);
            }
            timer.end();
        }
        timer.end(); // NOTE(khvorov) wait

        timer.end(); // NOTE(khvorov) frame
    }
}
