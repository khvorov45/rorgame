const std = @import("std");
const panic = std.debug.panic;

const mem = @import("mem.zig");
const fs = @import("filesystem.zig");
const ase = @import("ase.zig");
const log = @import("log.zig");

pub fn pack(allocator: mem.Allocator) void {
    const commando_ase = fs.readEntireFile("assets/commando.ase", allocator) catch |err| {
        panic("failed to read file: {}", .{err});
    };

    _ = ase.parse(commando_ase) catch |err| {
        panic("failed to parse ase: {}", .{err});
    };
}
