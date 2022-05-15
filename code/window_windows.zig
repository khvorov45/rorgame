const win = @import("windows_bindings.zig");
const Window = @import("window.zig").Window;

pub const PlatformWindow = struct {
    hwnd: win.HWND = undefined,
};

pub fn init(window: *Window, width: i32, height: i32) void {
    window.platform.hwnd = win.CreateWindowExW(
        win.WS_EX_APPWINDOW, 
        win.L("rorgameClass"), win.L("rorgame"),
        win.WS_OVERLAPPEDWINDOW,
        win.CW_USEDEFAULT, win.CW_USEDEFAULT, width, height,
        null, null, null, null,
    );

    window.is_running = true;
}

