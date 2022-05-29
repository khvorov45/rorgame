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
        window.pollForInput();

        renderer.clearBuffers();

        window.displayPixels(renderer.pixels, renderer.dim);
    }

    platform.exit();
}
