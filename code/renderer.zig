const panic = @import("std").debug.panic;

const math = @import("math.zig");
const mem = @import("mem.zig");

pub const Renderer = struct {
    pixels: []u32,
    dim: math.V2i,

    pub fn new(dim: math.V2i, allocator: mem.Allocator) !Renderer {
        const result = Renderer{
            .pixels = try allocator.alloc(u32, @intCast(usize, dim.x * dim.y)),
            .dim = dim,
        };
        return result;
    }

    pub fn clearBuffers(renderer: *Renderer) void {
        for (renderer.pixels) |*pixel| {
            pixel.* = 0xFF0000FF;
        }
    }
};
