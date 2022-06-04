const assert = @import("std").debug.assert;
const log = @import("log.zig");
const win = @import("windows_bindings.zig");
const outputWindowsError = @import("log_windows.zig").outputWindowsError;

pub const ReserveResult = struct {
    ptr: [*]u8,
    size_actual: usize,
};

pub fn reserve(size: usize) !ReserveResult {
    const ptr = win.VirtualAlloc(null, @intCast(usize, size), win.MEM_RESERVE, win.PAGE_READWRITE);
    if (ptr == null) {
        outputWindowsError();
        log.err(
            "VirtualAlloc failed to reserve {} bytes ({} KB {} MB {} GB)",
            .{ size, size / 1024, size / 1024 / 1024, size / 1024 / 1024 / 1024 },
        );
        return error.System;
    } else {
        return ReserveResult{ .ptr = @ptrCast([*]u8, ptr), .size_actual = size };
    }
}

pub fn commit(ptr: [*]u8, size: usize) !usize {
    const base = win.VirtualAlloc(ptr, @intCast(usize, size), win.MEM_COMMIT, win.PAGE_READWRITE);
    if (base == null) {
        outputWindowsError();
        log.err(
            "VirtualAlloc failed to commit {} bytes ({} KB {} MB {} GB)",
            .{ size, size / 1024, size / 1024 / 1024, size / 1024 / 1024 / 1024 },
        );
        return error.System;
    } else {
        assert(@ptrToInt(base) == @ptrToInt(ptr));
        return size;
    }
}
