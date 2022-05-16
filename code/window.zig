const windows = @import("window_windows.zig");
const builtin = @import("builtin");

pub const platform = if (builtin.os.tag == .windows) windows else @panic("missing window implementation");

pub const Window = struct {
    is_running: bool,
    width: i32,
    height: i32,
    platform: platform.PlatformWindow,
};
