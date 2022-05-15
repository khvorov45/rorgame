const windows = @import("window_windows.zig");
const builtin = @import("builtin");

pub const platform = if (builtin.os.tag == .windows) windows else @panic("missing window implementation");

pub const Window = struct {
    is_running: bool = false,
    width: i32 = 0,
    height: i32 = 0,
    platform: platform.PlatformWindow = platform.PlatformWindow{},
};
