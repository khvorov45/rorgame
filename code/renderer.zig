const mem = @import("mem.zig");

pub const Renderer = struct {
    pixels: []u32,
    width: i32,
    height: i32,
    max_width: i32,
    max_height: i32,

    pub fn init(renderer: *Renderer, max_width: i32, max_height: i32, allocator: mem.Allocator) void {

        renderer.pixels = allocator.alloc(u32, @intCast(usize, max_width * max_height)) catch unreachable;

        renderer.width = 0;
        renderer.height = 0;
        renderer.max_width = max_width;
        renderer.max_height = max_height;
    }

    pub fn clearBuffers(renderer: *Renderer, width_req: i32, height_req: i32) void {
        renderer.width = @minimum(width_req, renderer.max_width);
        renderer.height = @minimum(height_req, renderer.max_height);
        const lastPxIndex = @intCast(usize, renderer.width * renderer.height - 1);
        for (renderer.pixels[0..lastPxIndex]) |*pixel| {
            pixel.* = 0xFF0000FF;
        }
    }
};
