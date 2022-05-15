const builtin = @import("builtin");
const CallingConvention = @import("std").builtin.CallingConvention;
const WINAPI: CallingConvention = if (builtin.cpu.arch == .i386) .Stdcall else .C;

pub const L = @import("std").unicode.utf8ToUtf16LeStringLiteral;

pub extern "user32" fn CreateWindowExW(
    dwExStyle: DWORD,
    lpClassName: LPCWSTR, lpWindowName: LPCWSTR,
    dwStyle: DWORD,
    X: i32, Y: i32, nWidth: i32, nHeight: i32,
    hWindParent: ?HWND, hMenu: ?HMENU, hInstance: ?HINSTANCE, lpParam: ?LPVOID
) callconv(WINAPI) HWND;

pub const BOOL = i32;
pub const BOOLEAN = BYTE;
pub const BYTE = u8;
pub const CHAR = u8;
pub const UCHAR = u8;
pub const FLOAT = f32;
pub const HANDLE = *anyopaque;
pub const HCRYPTPROV = ULONG_PTR;
pub const ATOM = u16;
pub const HBRUSH = *opaque {};
pub const HCURSOR = *opaque {};
pub const HICON = *opaque {};
pub const HINSTANCE = *opaque {};
pub const HMENU = *opaque {};
pub const HMODULE = *opaque {};
pub const HWND = *opaque {};
pub const HDC = *opaque {};
pub const HGLRC = *opaque {};
pub const FARPROC = *opaque {};
pub const INT = c_int;
pub const LPCSTR = [*:0]const CHAR;
pub const LPCVOID = *const anyopaque;
pub const LPSTR = [*:0]CHAR;
pub const LPVOID = *anyopaque;
pub const LPWSTR = [*:0]WCHAR;
pub const LPCWSTR = [*:0]const WCHAR;
pub const PVOID = *anyopaque;
pub const PWSTR = [*:0]WCHAR;
pub const SIZE_T = usize;
pub const UINT = c_uint;
pub const ULONG_PTR = usize;
pub const LONG_PTR = isize;
pub const DWORD_PTR = ULONG_PTR;
pub const WCHAR = u16;
pub const WORD = u16;
pub const DWORD = u32;
pub const DWORD64 = u64;
pub const LARGE_INTEGER = i64;
pub const ULARGE_INTEGER = u64;
pub const USHORT = u16;
pub const SHORT = i16;
pub const ULONG = u32;
pub const LONG = i32;
pub const ULONGLONG = u64;
pub const LONGLONG = i64;
pub const HLOCAL = HANDLE;
pub const LANGID = c_ushort;

pub const WPARAM = usize;
pub const LPARAM = LONG_PTR;
pub const LRESULT = LONG_PTR;

pub const va_list = *opaque {};

pub const TRUE = 1;
pub const FALSE = 0;

pub const WS_OVERLAPPED = 0x00000000;
pub const WS_POPUP = 0x80000000;
pub const WS_CHILD = 0x40000000;
pub const WS_MINIMIZE = 0x20000000;
pub const WS_VISIBLE = 0x10000000;
pub const WS_DISABLED = 0x08000000;
pub const WS_CLIPSIBLINGS = 0x04000000;
pub const WS_CLIPCHILDREN = 0x02000000;
pub const WS_MAXIMIZE = 0x01000000;
pub const WS_CAPTION = WS_BORDER | WS_DLGFRAME;
pub const WS_BORDER = 0x00800000;
pub const WS_DLGFRAME = 0x00400000;
pub const WS_VSCROLL = 0x00200000;
pub const WS_HSCROLL = 0x00100000;
pub const WS_SYSMENU = 0x00080000;
pub const WS_THICKFRAME = 0x00040000;
pub const WS_GROUP = 0x00020000;
pub const WS_TABSTOP = 0x00010000;
pub const WS_MINIMIZEBOX = 0x00020000;
pub const WS_MAXIMIZEBOX = 0x00010000;
pub const WS_TILED = WS_OVERLAPPED;
pub const WS_ICONIC = WS_MINIMIZE;
pub const WS_SIZEBOX = WS_THICKFRAME;
pub const WS_TILEDWINDOW = WS_OVERLAPPEDWINDOW;
pub const WS_OVERLAPPEDWINDOW = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
pub const WS_POPUPWINDOW = WS_POPUP | WS_BORDER | WS_SYSMENU;
pub const WS_CHILDWINDOW = WS_CHILD;

pub const WS_EX_DLGMODALFRAME = 0x00000001;
pub const WS_EX_NOPARENTNOTIFY = 0x00000004;
pub const WS_EX_TOPMOST = 0x00000008;
pub const WS_EX_ACCEPTFILES = 0x00000010;
pub const WS_EX_TRANSPARENT = 0x00000020;
pub const WS_EX_MDICHILD = 0x00000040;
pub const WS_EX_TOOLWINDOW = 0x00000080;
pub const WS_EX_WINDOWEDGE = 0x00000100;
pub const WS_EX_CLIENTEDGE = 0x00000200;
pub const WS_EX_CONTEXTHELP = 0x00000400;
pub const WS_EX_RIGHT = 0x00001000;
pub const WS_EX_LEFT = 0x00000000;
pub const WS_EX_RTLREADING = 0x00002000;
pub const WS_EX_LTRREADING = 0x00000000;
pub const WS_EX_LEFTSCROLLBAR = 0x00004000;
pub const WS_EX_RIGHTSCROLLBAR = 0x00000000;
pub const WS_EX_CONTROLPARENT = 0x00010000;
pub const WS_EX_STATICEDGE = 0x00020000;
pub const WS_EX_APPWINDOW = 0x00040000;
pub const WS_EX_LAYERED = 0x00080000;
pub const WS_EX_OVERLAPPEDWINDOW = WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE;
pub const WS_EX_PALETTEWINDOW = WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST;

pub const CW_USEDEFAULT = @bitCast(i32, @as(u32, 0x80000000));
