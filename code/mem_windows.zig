const win = @import("windows_bindings.zig");

pub fn reserve(size: usize, ptr: *[*]u8, size_actual: *usize) void {
    ptr.* = @ptrCast([*]u8, win.VirtualAlloc(null, @intCast(usize, size), win.MEM_RESERVE, win.PAGE_READWRITE));
    size_actual.* = size;
}

pub fn commit(ptr: [*]u8, size: usize, size_actual: *usize) void {
    _ = win.VirtualAlloc(ptr, @intCast(usize, size), win.MEM_COMMIT, win.PAGE_READWRITE);
    size_actual.* = size;
}
