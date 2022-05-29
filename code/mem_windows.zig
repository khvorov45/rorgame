const log = @import("log.zig");
const win = @import("windows_bindings.zig");
const output_windows_error = @import("log_windows.zig").output_windows_error;

pub const ReserveResult = struct {
    ptr: [*]u8,
    size_actual: usize,
};

pub fn reserve(size: usize) !ReserveResult {
    var result: error{System}!ReserveResult = undefined;
    const ptr = win.VirtualAlloc(null, @intCast(usize, size), win.MEM_RESERVE, win.PAGE_READWRITE);
    if (ptr == null) {
        output_windows_error();
        log.err(
            "VirtualAlloc failed to reserve {} bytes ({} KB {} MB {} GB)",
            .{ size, size / 1024, size / 1024 / 1024, size / 1024 / 1024 / 1024 },
        );
        result = error.System;
    } else {
        result = .{ .ptr = @ptrCast([*]u8, ptr), .size_actual = size };
    }
    return result;
}

pub fn commit(ptr: [*]u8, size: usize) usize {
    _ = win.VirtualAlloc(ptr, @intCast(usize, size), win.MEM_COMMIT, win.PAGE_READWRITE);
    return size;
}
