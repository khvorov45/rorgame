const win = @import("windows_bindings.zig");
const Window = @import("window.zig").Window;

pub const PlatformWindow = struct {
    hwnd: win.HWND,
    bmi: win.BITMAPINFO,
    hdc: win.HDC,
};

pub fn init(window: *Window, width: i32, height: i32) void {

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

    window.platform.hwnd = win.CreateWindowExW(
        win.WS_EX_APPWINDOW, 
        class_name, win.L("rorgame"),
        win.WS_OVERLAPPEDWINDOW,
        win.CW_USEDEFAULT, win.CW_USEDEFAULT, width, height,
        null, null, null, null,
    );

    window.platform.hdc = win.GetDC(window.platform.hwnd);
    window.platform.bmi = win.BITMAPINFO{.bmiHeader = win.BITMAPINFOHEADER{}};

    // NOTE(khvorov) to avoid a white flash
    _ = win.ShowWindow(window.platform.hwnd, win.SW_SHOWMINIMIZED);
    _ = win.ShowWindow(window.platform.hwnd, win.SW_SHOWNORMAL);

    _ = win.SetWindowLongPtrW(window.platform.hwnd, win.GWLP_USERDATA, @bitCast(win.LONG_PTR, @ptrToInt(window)));

    window.is_running = true;
    window.width = width;
    window.height = height;
}

fn wndProc(hwnd: win.HWND, msg: win.UINT, wparam: win.WPARAM, lparam: win.LPARAM) callconv(win.WINAPI) win.LRESULT {
    var window = @intToPtr(?*Window, @bitCast(usize, win.GetWindowLongPtrW(hwnd, win.GWLP_USERDATA)));
    var result: win.LRESULT = undefined;
    
    if (window != null) {
        switch (msg) {
        win.WM_CLOSE, win.WM_DESTROY => {
            window.?.is_running = false;
        },
        
        else => {}
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
        }
        }
    }
}

pub fn displayPixels(window: *Window, pixels: []u32, pixels_width: i32, pixels_height: i32) void {
    window.platform.bmi.bmiHeader.biWidth = pixels_width;
    window.platform.bmi.bmiHeader.biHeight = -pixels_height; // NOTE(khvorov) Negative = top-down
    _ = win.StretchDIBits(
        window.platform.hdc,
        0, 0, window.width, window.height,
        0, 0, pixels_width, pixels_height,
        &pixels[0], &window.platform.bmi,
        win.DIB_RGB_COLORS, win.SRCCOPY
    );
}
