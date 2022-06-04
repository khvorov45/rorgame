const std = @import("std");
const win = @import("windows_bindings.zig");
const err = @import("log.zig").err;

pub fn outputDebugString(msg: [:0]u8) void {
    win.OutputDebugStringA(msg);
}

pub fn outputWindowsError() void {
    const err_code = win.GetLastError();
    // 614 is the length of the longest windows error desciption
    var buf_wstr: [614]win.WCHAR = undefined;
    var buf_utf8: [614]u8 = undefined;
    const len = win.FormatMessageW(
        win.FORMAT_MESSAGE_FROM_SYSTEM | win.FORMAT_MESSAGE_IGNORE_INSERTS,
        null,
        err_code,
        0,
        &buf_wstr,
        buf_wstr.len,
        null,
    );
    _ = std.unicode.utf16leToUtf8(&buf_utf8, buf_wstr[0..len]) catch unreachable;
    // NOTE(khvorov) ends on a newline
    err("windows code: {}, msg: {s}", .{ @enumToInt(err_code), buf_utf8[0 .. len - 1] });
}
