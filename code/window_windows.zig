const math = @import("math.zig");
const log = @import("log.zig");
const win = @import("windows_bindings.zig");
const inp = @import("input.zig");
const Input = inp.Input;
const KeyID = inp.KeyID;
const outputWindowsError = @import("log_windows.zig").outputWindowsError;

pub const PlatformWindow = struct {
    hwnd: win.HWND,
    bmi: win.BITMAPINFO,
    hdc: win.HDC,
};

pub const Window = struct {
    is_running: bool,
    dim: math.V2i,
    platform: PlatformWindow,

    pub fn init(window: *Window, dim: math.V2i) !void {
        errdefer outputWindowsError();

        const class_name = win.L("rorgameClass");
        const module = win.GetModuleHandleW(null) orelse return error.GetModuleHandleW;
        const instance = @ptrCast(win.HINSTANCE, module);

        const windowClass = win.WNDCLASSEXW{
            .style = win.CS_VREDRAW | win.CS_HREDRAW,
            .lpfnWndProc = wndProc,
            .hInstance = instance,
            .hCursor = win.LoadCursorA(null, win.IDC_ARROW),
            .hbrBackground = @ptrCast(win.HBRUSH, win.GetStockObject(win.BLACK_BRUSH)),
            .lpszClassName = class_name,
        };
        if (win.RegisterClassExW(&windowClass) == 0) return error.RegisterClassExW;

        const hwnd = win.CreateWindowExW(
            win.WS_EX_APPWINDOW,
            class_name,
            win.L("rorgame"),
            win.WS_OVERLAPPEDWINDOW,
            win.CW_USEDEFAULT,
            win.CW_USEDEFAULT,
            dim.x,
            dim.y,
            null,
            null,
            null,
            null,
        ) orelse return error.CreateWindowExW;

        const hdc = win.GetDC(hwnd) orelse return error.GetDC;
        const bmi = win.BITMAPINFO{ .bmiHeader = win.BITMAPINFOHEADER{} };

        // NOTE(khvorov) to avoid a white flash
        _ = win.ShowWindow(hwnd, win.SW_SHOWMINIMIZED);
        _ = win.ShowWindow(hwnd, win.SW_SHOWNORMAL);

        win.SetLastError(.SUCCESS);
        const set_result = win.SetWindowLongPtrW(hwnd, win.GWLP_USERDATA, @bitCast(win.LONG_PTR, @ptrToInt(window)));
        if (set_result == 0 and win.GetLastError() != .SUCCESS) return error.SetWindowLongPtrW;

        const platform = PlatformWindow{ .hwnd = hwnd, .bmi = bmi, .hdc = hdc };
        window.* = Window{ .is_running = true, .dim = dim, .platform = platform };
    }    

    pub fn pollForInput(window: *Window, input: *Input) void {
        input.clearHalfTransitionCounts();

        var msg: win.MSG = undefined;
        while (win.PeekMessageW(&msg, window.platform.hwnd, 0, 0, win.PM_REMOVE) == win.TRUE) {
            switch (msg.message) {
                win.WM_KEYDOWN, win.WM_KEYUP => {
                    const maybe_key: ?KeyID = switch (msg.wParam) {
                        win.VK_F5 => .f5,
                        win.VK_LEFT => .left,
                        win.VK_RIGHT => .right,
                        else => null,
                    };
                    if (maybe_key) |key| {
                        const down = msg.message == win.WM_KEYDOWN;
                        input.keyEvent(key, down);
                    }
                },
                else => {},
            }

            _ = win.TranslateMessage(&msg);
            _ = win.DispatchMessageW(&msg);
        }
    }

    pub fn displayPixels(window: *Window, pixels: []u32, pixels_dim: math.V2i) void {
        window.platform.bmi.bmiHeader.biWidth = pixels_dim.x;
        window.platform.bmi.bmiHeader.biHeight = -pixels_dim.y; // NOTE(khvorov) Negative = top-down
        _ = win.StretchDIBits(
            window.platform.hdc,
            0,
            0,
            window.dim.x,
            window.dim.y,
            0,
            0,
            pixels_dim.x,
            pixels_dim.y,
            &pixels[0],
            &window.platform.bmi,
            win.DIB_RGB_COLORS,
            win.SRCCOPY,
        );
    }
};

fn wndProc(hwnd: win.HWND, msg: win.UINT, wparam: win.WPARAM, lparam: win.LPARAM) callconv(win.WINAPI) win.LRESULT {
    var maybe_window = @intToPtr(?*Window, @bitCast(usize, win.GetWindowLongPtrW(hwnd, win.GWLP_USERDATA)));

    if (maybe_window) |window| {
        switch (msg) {
            win.WM_CLOSE, win.WM_DESTROY => window.is_running = false,
            else => {},
        }
    }

    return win.DefWindowProcW(hwnd, msg, wparam, lparam);
}