const win = @import("windows_bindings.zig");

pub fn reserve(size: usize) struct { ptr: [*]u8, size_actual: usize } {
    const ptr = @ptrCast([*]u8, win.VirtualAlloc(null, @intCast(usize, size), win.MEM_RESERVE, win.PAGE_READWRITE));
    const size_actual = size;
    return .{ .ptr = ptr, .size_actual = size_actual };
}

pub fn commit(ptr: [*]u8, size: usize) usize {
    _ = win.VirtualAlloc(ptr, @intCast(usize, size), win.MEM_COMMIT, win.PAGE_READWRITE);
    return size;
}
