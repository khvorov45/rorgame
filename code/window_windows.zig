const math = @import("math.zig");
const win = @import("windows_bindings.zig");

pub const PlatformWindow = struct {
    hwnd: win.HWND,
    bmi: win.BITMAPINFO,
    hdc: win.HDC,
};

pub const Window = struct {
    is_running: bool,
    dim: math.V2i,
    platform: PlatformWindow,

    pub fn init(window: *Window, dim: math.V2i) void {
        const class_name = win.L("rorgameClass");
        const module = win.GetModuleHandleW(null);
        const instance = @ptrCast(win.HINSTANCE, module);

        const windowClass = win.WNDCLASSEXW{
            .style = win.CS_VREDRAW | win.CS_HREDRAW,
            .lpfnWndProc = wndProc,
            .hInstance = instance,
            .hCursor = win.LoadCursorA(null, win.IDC_ARROW),
            .hbrBackground = @ptrCast(win.HBRUSH, win.GetStockObject(win.BLACK_BRUSH)),
            .lpszClassName = class_name,
        };
        _ = win.RegisterClassExW(&windowClass);

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
        );

        const hdc = win.GetDC(hwnd);
        const bmi = win.BITMAPINFO{ .bmiHeader = win.BITMAPINFOHEADER{} };

        // NOTE(khvorov) to avoid a white flash
        _ = win.ShowWindow(hwnd, win.SW_SHOWMINIMIZED);
        _ = win.ShowWindow(hwnd, win.SW_SHOWNORMAL);

        _ = win.SetWindowLongPtrW(hwnd, win.GWLP_USERDATA, @bitCast(win.LONG_PTR, @ptrToInt(window)));

        const platform = PlatformWindow{ .hwnd = hwnd, .bmi = bmi, .hdc = hdc };
        window.* = Window{ .is_running = true, .dim = dim, .platform = platform };
    }

    fn wndProc(hwnd: win.HWND, msg: win.UINT, wparam: win.WPARAM, lparam: win.LPARAM) callconv(win.WINAPI) win.LRESULT {
        var window = @intToPtr(?*Window, @bitCast(usize, win.GetWindowLongPtrW(hwnd, win.GWLP_USERDATA)));
        var result: win.LRESULT = undefined;

        if (window != null) {
            switch (msg) {
                win.WM_CLOSE, win.WM_DESTROY => {
                    window.?.is_running = false;
                },

                else => {},
            }
        }

        result = win.DefWindowProcW(hwnd, msg, wparam, lparam);
        return result;
    }

    pub fn pollForInput(window: *Window) void {
        var msg: win.MSG = undefined;
        while (win.PeekMessageW(&msg, window.platform.hwnd, 0, 0, win.PM_REMOVE) == win.TRUE) {
            switch (msg.message) {
                else => {
                    _ = win.TranslateMessage(&msg);
                    _ = win.DispatchMessageW(&msg);
                },
            }
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
