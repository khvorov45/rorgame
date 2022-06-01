const std = @import("std");
const builtin = @import("builtin");

const math = @import("math.zig");
const wnd = @import("window.zig");
const mem = @import("mem.zig");
const rdr = @import("renderer.zig");
const log = @import("log.zig");
const fs = @import("filesystem.zig");

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

    _ = fs.read_entire_file("assets/sGManIdle_0.png", virtual_arena_allocator) catch |err| {
        std.debug.panic("failed to read file: {}", .{err});
    };

    var rect_topleft_x: f32 = 50;

    while (window.is_running) {
        //
        // SECTION Input
        //

        window.pollForInput();

        //
        // SECTION Update
        //

        rect_topleft_x += 0.01;

        //
        // SECTION Render
        //

        renderer.clearBuffers();

        renderer.drawRect(
            math.Rect2f{ .topleft = math.V2f{ .x = rect_topleft_x, .y = 50 }, .dim = math.V2f{ .x = 400, .y = 400 } },
            math.Color{ .r = 1, .g = 0, .b = 0, .a = 1 },
            math.Rect2f{ .topleft = math.V2f{ .x = 0, .y = 0 }, .dim = renderer.atlas.dim.to(math.V2f) },
        );

        window.displayPixels(renderer.draw_buffer.pixels, renderer.draw_buffer.dim);
    }

    platform.exit();
}
