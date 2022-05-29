const std = @import("std");
const builtin = @import("builtin");

const platform = if (builtin.os.tag == .windows) @import("log_windows.zig") else @panic("unimplemented log");

pub fn output_debug_string(comptime format: []const u8, args: anytype) void {
    const size = 0x1000;
    const terminator = "\n\x00";
    const trunc_msg = "(msg truncated)" ++ terminator;
    var buf: [size + trunc_msg.len]u8 = undefined;
    const msg = std.fmt.bufPrint(buf[0..size], format ++ terminator, args) catch |err| switch (err) {
        std.fmt.BufPrintError.NoSpaceLeft => blk: {
            std.mem.copy(u8, buf[size..], trunc_msg);
            break :blk &buf;
        },
    };
    platform.output_debug_string(msg[0 .. msg.len - 1 :0]);
}

pub fn debug(comptime format: []const u8, args: anytype) void {
    output_debug_string("DEBUG: " ++ format, args);
}

pub fn err(comptime format: []const u8, args: anytype) void {
    output_debug_string("ERROR: " ++ format, args);
}
