const win = @import("windows_bindings.zig");

pub fn output_debug_string(msg: [:0]u8) void {
    win.OutputDebugStringA(msg);
}
