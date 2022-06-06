const std = @import("std");
const builtin = @import("builtin");

const math = @import("math.zig");
const wnd = @import("window.zig");
const mem = @import("mem.zig");
const rdr = @import("renderer.zig");
const log = @import("log.zig");
const fs = @import("filesystem.zig");
const Assets = @import("assets.zig").Assets;

const platform = if (builtin.os.tag == .windows) @import("rorgame_windows.zig") else @panic("unimplemented root");

pub fn panic(msg: []const u8, trace: ?*std.builtin.StackTrace) noreturn {
    _ = trace;
    @setCold(true);
    log.err("{s}", .{msg});
    @breakpoint();
    platform.panic_exit();
}

pub fn main() noreturn {
    var virtual_arena = mem.VirtualArena.new(1 * mem.GIGABYTE, 1 * mem.MEGABYTE) catch |err| {
        std.debug.panic("failed to allocate memory: {}", .{err});
    };
    const virtual_arena_allocator = virtual_arena.allocator();

    var window: wnd.Window = undefined;
    window.init(math.V2i{ .x = 1280, .y = 720 }) catch |err| {
        std.debug.panic("failed to init window: {}", .{err});
    };

    const assets = Assets.fromSources(virtual_arena_allocator) catch |err| {
        std.debug.panic("failed to pack assets: {}", .{err});
    };

    var renderer = rdr.Renderer.new(window.dim, assets.atlas, virtual_arena_allocator) catch |err| {
        std.debug.panic("failed to create renderer: {}", .{err});
    };

    var rect_topleft_x: f32 = 0;
    var rect_topleft_y: f32 = 0;

    while (window.is_running) {
        std.debug.assert(virtual_arena.temp_count == 0);

        //
        // SECTION Input
        //

        window.pollForInput();

        //
        // SECTION Update
        //

        rect_topleft_x += 0.2;
        rect_topleft_y += 0.1;

        //
        // SECTION Render
        //

        renderer.clearBuffers();

        renderer.drawRect(
            math.Rect2f{ .topleft = math.V2f{ .x = rect_topleft_x, .y = rect_topleft_y }, .dim = assets.commando.dim.mulf(10) },
            math.Color{ .r = 1, .g = 0, .b = 0, .a = 1 },
            assets.commando,
        );

        renderer.drawRect(
            math.Rect2f{ .topleft = math.V2f{ .x = @round(rect_topleft_x), .y = @round(rect_topleft_y + assets.commando.dim.y * 10 + 10) }, .dim = assets.commando.dim.mulf(10) },
            math.Color{ .r = 1, .g = 0, .b = 0, .a = 1 },
            assets.commando,
        );

        window.displayPixels(renderer.draw_buffer.pixels, renderer.draw_buffer.dim);
    }

    platform.exit();
}
