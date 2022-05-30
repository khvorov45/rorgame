const std = @import("std");

const math = @import("math.zig");
const wnd = @import("window.zig");
const mem = @import("mem.zig");
const rdr = @import("renderer.zig");
const log = @import("log.zig");
const builtin = @import("builtin");

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

    var renderer = rdr.Renderer.new(window.dim, virtual_arena_allocator) catch |err| {
        std.debug.panic("failed to create renderer: {}", .{err});
    };

    while (window.is_running) {
        //
        // SECTION Input
        //

        window.pollForInput();

        //
        // SECTION Update
        //

        //
        // SECTION Render
        //

        renderer.clearBuffers();

        renderer.drawRect(
            math.Rect2i{ .topleft = math.V2i{ .x = 50, .y = 50 }, .dim = math.V2i{ .x = 150, .y = 150 } },
            math.Color{ .r = 1, .g = 0, .b = 0, .a = 1 },
            math.Rect2i{ .topleft = math.V2i{ .x = 0, .y = 0 }, .dim = renderer.atlas.dim },
        );

        window.displayPixels(renderer.draw_buffer.pixels, renderer.draw_buffer.dim);
    }

    platform.exit();
}
