const windows = @import("window_windows.zig");
const builtin = @import("builtin");

const platform = if (builtin.os.tag == .windows) windows else @panic("missing window implementation");

pub const Window = struct {
    is_running: bool,
    width: i32,
    height: i32,
    platform: platform.PlatformWindow,

    pub fn init(window: *Window, width: i32, height: i32) void {
        platform.init(window, width, height);
    }

    pub fn pollForInput(window: *Window) void {
        platform.pollForInput(window);
    }

    pub fn displayPixels(window: *Window, pixels: []u32, px_width: i32, px_height: i32) void {
        platform.displayPixels(window, pixels, px_width, px_height);
    }
};
