const wnd = @import("window.zig");
const mem = @import("mem.zig");
const rdr = @import("renderer.zig");

pub fn main() !void {
    var virtual_arena: mem.VirtualArena = undefined;
    virtual_arena.init(1 * mem.GIGABYTE, 1 * mem.MEGABYTE);
    const virtual_arena_allocator = virtual_arena.allocator();

    var window: wnd.Window = undefined;
    window.init(1000, 1000);

    var renderer: rdr.Renderer = undefined;
    renderer.init(7680, 4320, virtual_arena_allocator);

    while (window.is_running) {

        window.waitForInput();

        renderer.clearBuffers(window.width, window.height);

        window.displayPixels(renderer.pixels, renderer.width, renderer.height);
    }
}
