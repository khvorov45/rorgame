const std = @import("std");
const panic = std.debug.panic;

const mem = @import("mem.zig");
const math = @import("math.zig");
const fs = @import("filesystem.zig");
const ase = @import("ase.zig");
const log = @import("log.zig");

pub const Texture = struct {
    pixels: []u32,
    dim: math.V2i,
};

pub const Assets = struct {
    atlas: Texture,

    pub fn fromSources(allocator: mem.Allocator) !Assets {
        const commando_ase = try fs.readEntireFile("assets/commando.ase", allocator);
        const commando_textures = try ase.parse(commando_ase, allocator);

        // TODO(khvorov) Build the atlas
        const result = Assets{ .atlas = commando_textures[0] };
        return result;
    }
};
