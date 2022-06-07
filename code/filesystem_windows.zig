const assert = @import("std").debug.assert;

const win = @import("windows_bindings.zig");
const mem = @import("mem.zig");
const log = @import("log.zig");
const outputWindowsError = @import("log_windows.zig").outputWindowsError;

pub fn readEntireFile(comptime filename: []const u8, allocator: mem.Allocator) ![]u8 {
    errdefer {
        outputWindowsError();
        log.err("failed to read {s}", .{filename});
    }

    const handle = win.CreateFileW(
        win.L(filename),
        win.GENERIC_READ,
        win.FILE_SHARE_READ,
        null,
        win.OPEN_EXISTING,
        win.FILE_ATTRIBUTE_NORMAL,
        null,
    );
    defer _ = win.CloseHandle(handle);
    if (handle == win.INVALID_HANDLE_VALUE) return error.CreateFileW;

    var file_size: win.LARGE_INTEGER = undefined;
    if (win.GetFileSizeEx(handle, &file_size) == 0) return error.GetFileSizeEx;

    const buffer = try allocator.alloc(u8, @intCast(usize, file_size));
    var bytes_read: win.DWORD = undefined;
    if (win.ReadFile(handle, buffer.ptr, @intCast(u32, file_size), &bytes_read, null) == win.FALSE) return error.ReadFile;
    if (bytes_read != file_size) return error.ReadFileIncomplete;

    return buffer;
}

pub fn writeEntireFileToExeDir(comptime filename: []const u8) !void {
    errdefer {
        outputWindowsError();
        log.err("failed to write {s} to exe dir", .{filename});
    }

    const exe_filename_buffer_size = 4096;
    var exe_filename_buffer: [4096]win.WCHAR = undefined;
    const exe_filename_result = win.GetModuleFileNameW(null, @ptrCast(win.LPWSTR, &exe_filename_buffer[0]), exe_filename_buffer_size);
    if (exe_filename_result == 0 or win.GetLastError() == .INSUFFICIENT_BUFFER) return error.GetModuleFileNameW;

    const filename_wide = win.L(filename);
    _ = filename_wide;

    var char_index = exe_filename_result;
    while (char_index >= 0) : (char_index -= 1) {
        const backslash = @intCast(win.WCHAR, '\\');
        if (exe_filename_buffer[char_index] == backslash) {
            break;
        }
    }

    char_index += 1;
    for (filename_wide) |char| {
        exe_filename_buffer[char_index] = char;
        char_index += 1;
    }
    exe_filename_buffer[char_index] = 0;

    const handle = win.CreateFileW(
        @ptrCast(win.LPCWSTR, &exe_filename_buffer[0]),
        win.GENERIC_WRITE,
        win.FILE_SHARE_WRITE,
        null,
        win.CREATE_ALWAYS,
        win.FILE_ATTRIBUTE_NORMAL,
        null,
    );
    defer _ = win.CloseHandle(handle);
    if (handle == win.INVALID_HANDLE_VALUE) return error.CreateFileW;

    const file_content = [_]u8{ 't', 'e', 's' };
    var bytes_written: win.DWORD = undefined;
    if (win.WriteFile(handle, &file_content[0], file_content.len, &bytes_written, null) == win.FALSE) return error.WriteFile;
    if (bytes_written != file_content.len) return error.WriteFileIncomplete;
}
