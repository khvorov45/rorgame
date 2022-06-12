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

    var renderer = try rdr.Renderer.new(window.dim, assets.atlas, virtual_arena_allocator);

    var input = Input.new();

    var rect_topleft_x: f32 = 0;
    var rect_topleft_y: f32 = 0;
    var temp_frame_index: usize = 0;
    var frame_index: usize = 0;

    while (window.is_running) {
        std.debug.assert(virtual_arena.temp_count == 0);

        //
        // SECTION Input
        //

        window.pollForInput(&input);

        //
        // SECTION Update
        //

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

        rect_topleft_x += 0;
        rect_topleft_y += 0;

        //
        // SECTION Render
        //

        renderer.clearBuffers();

        if (true) {
            const whole_atlas = math.Rect2f{
                .topleft = math.V2f{ .x = 1, .y = 1 },
                .dim = assets.atlas.dim.sub(math.V2i{ .x = 2, .y = 2 }).to(math.V2f),
            };

            const screen_rect = math.Rect2f{
                .topleft = math.V2f{ .x = rect_topleft_x, .y = rect_topleft_y },
                .dim = whole_atlas.dim.mulf(5),
            };

            renderer.drawRect(
                screen_rect,
                math.Color{ .r = 0, .g = 1, .b = 1, .a = 1 },
                whole_atlas,
            );

            renderer.drawRectOutline(screen_rect, math.Color{ .r = 0, .g = 1, .b = 1, .a = 0.5 });
        } else {
            const req_group = assets.texture_groups.get(.commando_walk);
            const req_tex = req_group[frame_index];
            const temp_factor = 50;
            temp_frame_index = (temp_frame_index + 1) % (req_group.len * temp_factor);
            frame_index = temp_frame_index / temp_factor;

            renderer.drawRect(
                math.Rect2f{ .topleft = math.V2f{ .x = rect_topleft_x, .y = rect_topleft_y }, .dim = req_tex.dim.mulf(5) },
                math.Color{ .r = 1, .g = 0, .b = 0, .a = 1 },
                req_tex,
            );
        }

        window.displayPixels(renderer.draw_buffer.pixels, renderer.draw_buffer.dim);
    }
}
