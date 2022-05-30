const assert = @import("std").debug.assert;
const mem = @import("mem.zig");
const win = @import("windows_bindings.zig");
const output_windows_error = @import("log_windows.zig").output_windows_error;
const log = @import("log.zig");

pub fn read_entire_file(comptime filename: []const u8, allocator: mem.Allocator) ![]u8 {
    errdefer output_windows_error();

    const handle = win.CreateFileW(
        win.L(filename),
        win.GENERIC_READ,
        win.FILE_SHARE_READ,
        null,
        win.OPEN_EXISTING,
        win.FILE_ATTRIBUTE_NORMAL,
        null,
    );
    if (handle == win.INVALID_HANDLE_VALUE) return error.CreateFileW;

    var file_size: win.LARGE_INTEGER = undefined;
    if (win.GetFileSizeEx(handle, &file_size) == 0) return error.GetFileSizeEx;

    const buffer = try allocator.alloc(u8, @intCast(usize, file_size));
    var bytes_read: win.DWORD = undefined;
    if (win.ReadFile(handle, buffer.ptr, @intCast(u32, file_size), &bytes_read, null) == win.FALSE) return error.ReadFile;
    assert(bytes_read == file_size);

    return buffer;
}
