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

    var rect_topleft_x: f32 = 500;
    var rect_topleft_y: f32 = 600;
    var temp_frame_index: usize = 0;
    var frame_index: usize = 0;

    var timer = time.Timer.new();
    const target_frame_ms: f32 = 1000.0 / 60.0;

    var last_clock_before_display = time.getCurrentClock();

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

        if (input.pressed(.p)) {
            timer.cycle_buffers = !timer.cycle_buffers;
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
            renderer.drawWholeAtlas(math.V2f{ .x = 500, .y = 200 });
            timer.end();
        }

        timer.begin(.debug_timings);
        try displayTimings(&timer, &renderer, target_frame_ms, &input);
        timer.end();

        timer.end(); // NOTE(khvorov) work

        //
        // SECTION Wait
        //

        timer.begin(.wait);
        {
            timer.begin(.sleep);
            const ms_remaining = target_frame_ms - time.getMsFrom(last_clock_before_display);
            timer.sleep(ms_remaining);
            timer.end();
        }

        {
            timer.begin(.spin);
            var ms_remaining = target_frame_ms - time.getMsFrom(last_clock_before_display);
            while (ms_remaining > 0) {
                ms_remaining = target_frame_ms - time.getMsFrom(last_clock_before_display);
            }
            timer.end();
        }
        timer.end(); // NOTE(khvorov) wait

        timer.begin(.display_pixels);
        last_clock_before_display = time.getCurrentClock();
        window.displayPixels(renderer.draw_buffer.pixels, renderer.draw_buffer.dim);
        timer.end();

        timer.end(); // NOTE(khvorov) frame
    }
}

fn displayTimings(timer: *time.Timer, renderer: *rdr.Renderer, target_frame_ms: f32, input: *Input) !void {
    const topleft = math.V2f{ .x = 0, .y = 0 };
    const height: f32 = 200;
    const width_per_column: f32 = 20;
    const outline_thickness = 1;

    const colors = [_]math.Color{
        math.Color.fromRGB255(154, 199, 223),
        math.Color.fromRGB255(85, 169, 226),
        math.Color.fromRGB255(175, 222, 133),
        math.Color.fromRGB255(110, 213, 103),
        math.Color.fromRGB255(250, 136, 135),
        math.Color.fromRGB255(232, 50, 52),
        math.Color.fromRGB255(253, 188, 104),
        math.Color.fromRGB255(255, 140, 26),
        math.Color.fromRGB255(195, 168, 209),
        math.Color.fromRGB255(153, 111, 198),
        math.Color.fromRGB255(255, 255, 133),
        math.Color.fromRGB255(218, 135, 90),
    };

    var sections_x_offset: f32 = 0;
    var sections_index = timer.getNextSectionsIndex(timer.sections_index);
    var sections_to_print: ?*time.SectionsBuf = null;
    while (sections_index != timer.sections_index) : (sections_index = timer.getNextSectionsIndex(sections_index)) {
        const sections = &timer.sections[sections_index];
        var iter = sections.iterator();
        var entry_y_offsets = [_]f32{0} ** 10;

        var color_indices = [_]usize{0} ** 10;
        var column_count: i32 = 0;

        while (iter.next()) |entry| {
            if (entry.key != .frame) {
                const section = entry.value;
                if (section.ms) |section_ms| {
                    const prop = section_ms / target_frame_ms;
                    const section_height = @round(prop * height);

                    const entry_y_offset = &entry_y_offsets[@intCast(usize, section.nest_level)];
                    const column_index = section.nest_level - 1;
                    const section_topleft = topleft.add(math.V2f{ .x = sections_x_offset + @intToFloat(f32, column_index) * width_per_column, .y = entry_y_offset.* });
                    entry_y_offset.* = entry_y_offset.* + section_height;

                    const this_color_index = &color_indices[@intCast(usize, section.nest_level)];
                    renderer.drawRectNoAA(
                        math.Rect2f{ .topleft = section_topleft, .dim = math.V2f{ .x = width_per_column, .y = section_height } },
                        colors[this_color_index.*],
                    );
                    this_color_index.* = (this_color_index.* + 1) % colors.len;

                    renderer.drawRectNoAA(
                        math.Rect2f{ .topleft = section_topleft.add(math.V2f{ .x = width_per_column - 1, .y = 0 }), .dim = math.V2f{ .x = outline_thickness, .y = section_height } },
                        math.Color{ .r = 0.5, .g = 0.5, .b = 0.5, .a = 1 },
                    );

                    column_count = @maximum(column_count, column_index + 1);
                }
            }
        }

        renderer.drawRectNoAA(
            math.Rect2f{
                .topleft = topleft.add(math.V2f{ .x = 0, .y = height }),
                .dim = math.V2f{ .x = @intToFloat(f32, renderer.draw_buffer.dim.x), .y = outline_thickness },
            },
            math.Color{ .r = 0.5, .g = 0.5, .b = 0.5, .a = 1 },
        );

        const bounding_rect = math.Rect2f{
            .topleft = topleft.add(math.V2f{ .x = sections_x_offset, .y = 0 }),
            .dim = math.V2f{ .x = @intToFloat(f32, column_count) * width_per_column, .y = height },
        };
        if (math.pointInRect(input.cursor_pos.to(math.V2f), bounding_rect)) {
            renderer.drawRectOutlineNoAA(bounding_rect, math.Color{.r = 1, .g = 1, .b = 0, .a = 0.5});
            sections_to_print = sections;
        }

        sections_x_offset += bounding_rect.dim.x;
    }

    if (sections_to_print) |sections| {
        try printSectionTimes(sections, renderer, math.V2f{ .x = 0, .y = height }, colors[0..]);
    }
}

fn printSectionTimes(sections: *time.SectionsBuf, renderer: *rdr.Renderer, topleft: math.V2f, colors: []const math.Color) !void {
    var y_offset: f32 = 0;
    var iter = sections.iterator();
    var color_indices = [_]usize{0} ** 10;

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

            const text = try std.fmt.bufPrint(buf[buf_index..], "{s}: {d:.3}", .{ @tagName(entry.key), duration });

            const this_color_index = &color_indices[@intCast(usize, section.nest_level)];
            renderer.drawTextline(
                buf[0 .. buf_index + text.len],
                math.V2f{ .x = topleft.x, .y = topleft.y + y_offset },
                colors[this_color_index.*],
            );
            this_color_index.* = (this_color_index.* + 1) % colors.len;

            y_offset += @intToFloat(f32, renderer.font.px_height_line);
        }
    }
}
