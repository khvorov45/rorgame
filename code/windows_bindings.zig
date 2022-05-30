const builtin = @import("builtin");
const CallingConvention = @import("std").builtin.CallingConvention;

pub const WINAPI: CallingConvention = if (builtin.cpu.arch == .i386) .Stdcall else .C;

pub const L = @import("std").unicode.utf8ToUtf16LeStringLiteral;

pub extern "user32" fn CreateWindowExW(
    dwExStyle: DWORD,
    lpClassName: LPCWSTR,
    lpWindowName: LPCWSTR,
    dwStyle: DWORD,
    X: i32,
    Y: i32,
    nWidth: i32,
    nHeight: i32,
    hWindParent: ?HWND,
    hMenu: ?HMENU,
    hInstance: ?HINSTANCE,
    lpParam: ?LPVOID,
) callconv(WINAPI) ?HWND;

pub extern "user32" fn RegisterClassExW(unnamedParam1: *const WNDCLASSEXW) callconv(WINAPI) ATOM;
pub extern "user32" fn DefWindowProcW(hWnd: HWND, Msg: UINT, wParam: WPARAM, lParam: LPARAM) callconv(WINAPI) LRESULT;
pub extern "kernel32" fn GetModuleHandleW(lpModuleName: ?LPCWSTR) callconv(WINAPI) ?HMODULE;
pub extern "user32" fn ShowWindow(hWnd: HWND, nCmdShow: i32) callconv(WINAPI) BOOL;
pub extern "user32" fn LoadCursorA(hInstance: ?HINSTANCE, lpCursorName: LPCSTR) callconv(WINAPI) HCURSOR;
pub extern "gdi32" fn GetStockObject(i: i32) callconv(WINAPI) HGDIOBJ;
pub extern "user32" fn GetMessageW(lpMsg: *MSG, hWnd: ?HWND, wMsgFilterMin: UINT, wMsgFilterMax: UINT) callconv(WINAPI) BOOL;
pub extern "user32" fn TranslateMessage(lpMsg: *const MSG) callconv(WINAPI) BOOL;
pub extern "user32" fn DispatchMessageW(lpMsg: *const MSG) callconv(WINAPI) LRESULT;
pub extern "user32" fn SetWindowLongPtrW(hWnd: HWND, nIndex: i32, dwNewLong: LONG_PTR) callconv(WINAPI) LONG_PTR;
pub extern "user32" fn GetWindowLongPtrW(hWnd: HWND, nIndex: i32) callconv(WINAPI) LONG_PTR;
pub extern "user32" fn PeekMessageW(lpMsg: *MSG, hWnd: ?HWND, wMsgFilterMin: UINT, wMsgFilterMax: UINT, wRemoveMsg: UINT) callconv(WINAPI) BOOL;
pub extern "kernel32" fn VirtualAlloc(lpAddress: ?LPVOID, dwSize: SIZE_T, flAllocationType: DWORD, flProtect: DWORD) callconv(WINAPI) ?LPVOID;
pub extern "user32" fn GetDC(hWnd: ?HWND) callconv(WINAPI) ?HDC;
pub extern "kernel32" fn OutputDebugStringA(lpOutputString: LPCSTR) callconv(WINAPI) void;
pub extern "kernel32" fn ExitProcess(exit_code: UINT) callconv(WINAPI) noreturn;
pub extern "kernel32" fn GetLastError() callconv(WINAPI) Win32Error;
pub extern "kernel32" fn FormatMessageW(
    dwFlags: DWORD,
    lpSource: ?LPVOID,
    dwMessageId: Win32Error,
    dwLanguageId: DWORD,
    lpBuffer: [*]u16,
    nSize: DWORD,
    Arguments: ?*va_list,
) callconv(WINAPI) DWORD;

pub extern "gdi32" fn StretchDIBits(
    hdc: HDC,
    xDest: i32,
    yDest: i32,
    DestWidth: i32,
    DestHeight: i32,
    xSrc: i32,
    ySrc: i32,
    SrcWidth: i32,
    SrcHeight: i32,
    lpBits: LPCVOID,
    lpbmi: *const BITMAPINFO,
    iUsage: UINT,
    rop: DWORD,
) callconv(WINAPI) i32;
pub extern "kernel32" fn SetLastError(dwErrCode: Win32Error) callconv(WINAPI) void;
pub extern "kernel32" fn ReadFileEx(
    hFile: HANDLE,
    lpBuffer: LPVOID,
    nNumberOfBytesToRead: DWORD,
    lpOverlapped: LPOVERLAPPED,
    lpCompletionRoutine: LPOVERLAPPED_COMPLETION_ROUTINE,
) callconv(WINAPI) void;
pub extern "kernel32" fn ReadFile(
    hFile: HANDLE,
    lpBuffer: [*]u8,
    nNumberOfBytesToRead: DWORD,
    lpNumberOfBytesRead: ?*DWORD,
    lpOverlapped: ?*OVERLAPPED,
) callconv(WINAPI) BOOL;
pub extern "kernel32" fn CreateFileW(
    lpFileName: [*:0]const u16,
    dwDesiredAccess: DWORD,
    dwShareMode: DWORD,
    lpSecurityAttributes: ?*SECURITY_ATTRIBUTES,
    dwCreationDisposition: DWORD,
    dwFlagsAndAttributes: DWORD,
    hTemplateFile: ?HANDLE,
) callconv(WINAPI) HANDLE;
pub extern "kernel32" fn GetFileSizeEx(hFile: HANDLE, lpFileSize: *LARGE_INTEGER) callconv(WINAPI) BOOL;

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
pub const HGDIOBJ = *opaque {};
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
pub const INVALID_HANDLE_VALUE = @intToPtr(HANDLE, @bitCast(usize, @as(isize, -1)));

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

pub const WNDPROC = fn (hwnd: HWND, uMsg: UINT, wParam: WPARAM, lParam: LPARAM) callconv(WINAPI) LRESULT;
pub const LPOVERLAPPED_COMPLETION_ROUTINE = fn (
    dwErrorCode: DWORD,
    dwNumberOfBytesTransfered: DWORD,
    lpOverlapped: LPOVERLAPPED,
) callconv(WINAPI) void;

pub const CS_VREDRAW = 0x0001;
pub const CS_HREDRAW = 0x0002;
pub const CS_DBLCLKS = 0x0008;
pub const CS_OWNDC = 0x0020;
pub const CS_CLASSDC = 0x0040;
pub const CS_PARENTDC = 0x0080;
pub const CS_NOCLOSE = 0x0200;
pub const CS_SAVEBITS = 0x0800;
pub const CS_BYTEALIGNCLIENT = 0x1000;
pub const CS_BYTEALIGNWINDOW = 0x2000;
pub const CS_GLOBALCLASS = 0x4000;

pub const WNDCLASSEXW = extern struct {
    cbSize: UINT = @sizeOf(WNDCLASSEXW),
    style: UINT,
    lpfnWndProc: WNDPROC,
    cbClsExtra: i32 = 0,
    cbWndExtra: i32 = 0,
    hInstance: HINSTANCE,
    hIcon: ?HICON = null,
    hCursor: ?HCURSOR = null,
    hbrBackground: ?HBRUSH = null,
    lpszMenuName: ?LPCWSTR = null,
    lpszClassName: LPCWSTR,
    hIconSm: ?HICON = null,
};

pub const SECURITY_ATTRIBUTES = extern struct {
    nLength: DWORD,
    lpSecurityDescriptor: ?*anyopaque,
    bInheritHandle: BOOL,
};

pub const SW_HIDE = 0;
pub const SW_SHOWNORMAL = 1;
pub const SW_NORMAL = 1;
pub const SW_SHOWMINIMIZED = 2;
pub const SW_SHOWMAXIMIZED = 3;
pub const SW_MAXIMIZE = 3;
pub const SW_SHOWNOACTIVATE = 4;
pub const SW_SHOW = 5;
pub const SW_MINIMIZE = 6;
pub const SW_SHOWMINNOACTIVE = 7;
pub const SW_SHOWNA = 8;
pub const SW_RESTORE = 9;
pub const SW_SHOWDEFAULT = 10;
pub const SW_FORCEMINIMIZE = 11;
pub const SW_MAX = 11;

pub const IDC_ARROW = @intToPtr(LPCSTR, 32512);
pub const IDC_SIZENS = @intToPtr(LPCSTR, 32645);
pub const IDC_SIZEWE = @intToPtr(LPCSTR, 32644);
pub const IDC_HAND = @intToPtr(LPCSTR, 32649);

pub const WHITE_BRUSH = 0;
pub const LTGRAY_BRUSH = 1;
pub const GRAY_BRUSH = 2;
pub const DKGRAY_BRUSH = 3;
pub const BLACK_BRUSH = 4;
pub const NULL_BRUSH = 5;
pub const HOLLOW_BRUSH = NULL_BRUSH;
pub const WHITE_PEN = 6;
pub const BLACK_PEN = 7;
pub const NULL_PEN = 8;
pub const OEM_FIXED_FONT = 10;
pub const ANSI_FIXED_FONT = 11;
pub const ANSI_VAR_FONT = 12;
pub const SYSTEM_FONT = 13;
pub const DEVICE_DEFAULT_FONT = 14;
pub const DEFAULT_PALETTE = 15;
pub const SYSTEM_FIXED_FONT = 16;
pub const DEFAULT_GUI_FONT = 17;
pub const DC_BRUSH = 18;
pub const DC_PEN = 19;

pub const MSG = extern struct {
    hWnd: ?HWND,
    message: UINT,
    wParam: WPARAM,
    lParam: LPARAM,
    time: DWORD,
    pt: POINT,
    lPrivate: DWORD,
};

pub const POINT = extern struct {
    x: LONG,
    y: LONG,
};

pub const OVERLAPPED = extern struct {
    Internal: ULONG_PTR,
    InternalHigh: ULONG_PTR,
    DUMMYUNIONNAME: extern union {
        DUMMYSTRUCTNAME: extern struct {
            Offset: DWORD,
            OffsetHigh: DWORD,
        },
        Pointer: ?PVOID,
    },
    hEvent: ?HANDLE,
};

pub const LPOVERLAPPED = *OVERLAPPED;

pub const GWLP_WNDPROC = -4;
pub const GWLP_HINSTANCE = -6;
pub const GWLP_HWNDPARENT = -8;
pub const GWLP_USERDATA = -21;
pub const GWLP_ID = -12;

pub const WM_NULL = 0x0000;
pub const WM_CREATE = 0x0001;
pub const WM_DESTROY = 0x0002;
pub const WM_MOVE = 0x0003;
pub const WM_SIZE = 0x0005;
pub const WM_ACTIVATE = 0x0006;
pub const WM_SETFOCUS = 0x0007;
pub const WM_KILLFOCUS = 0x0008;
pub const WM_ENABLE = 0x000A;
pub const WM_SETREDRAW = 0x000B;
pub const WM_SETTEXT = 0x000C;
pub const WM_GETTEXT = 0x000D;
pub const WM_GETTEXTLENGTH = 0x000E;
pub const WM_PAINT = 0x000F;
pub const WM_CLOSE = 0x0010;
pub const WM_QUERYENDSESSION = 0x0011;
pub const WM_QUIT = 0x0012;
pub const WM_QUERYOPEN = 0x0013;
pub const WM_ERASEBKGND = 0x0014;
pub const WM_SYSCOLORCHANGE = 0x0015;
pub const WM_ENDSESSION = 0x0016;
pub const WM_SHOWWINDOW = 0x0018;
pub const WM_CTLCOLOR = 0x0019;
pub const WM_WININICHANGE = 0x001A;
pub const WM_DEVMODECHANGE = 0x001B;
pub const WM_ACTIVATEAPP = 0x001C;
pub const WM_FONTCHANGE = 0x001D;
pub const WM_TIMECHANGE = 0x001E;
pub const WM_CANCELMODE = 0x001F;
pub const WM_SETCURSOR = 0x0020;
pub const WM_MOUSEACTIVATE = 0x0021;
pub const WM_CHILDACTIVATE = 0x0022;
pub const WM_QUEUESYNC = 0x0023;
pub const WM_GETMINMAXINFO = 0x0024;
pub const WM_PAINTICON = 0x0026;
pub const WM_ICONERASEBKGND = 0x0027;
pub const WM_NEXTDLGCTL = 0x0028;
pub const WM_SPOOLERSTATUS = 0x002A;
pub const WM_DRAWITEM = 0x002B;
pub const WM_MEASUREITEM = 0x002C;
pub const WM_DELETEITEM = 0x002D;
pub const WM_VKEYTOITEM = 0x002E;
pub const WM_CHARTOITEM = 0x002F;
pub const WM_SETFONT = 0x0030;
pub const WM_GETFONT = 0x0031;
pub const WM_SETHOTKEY = 0x0032;
pub const WM_GETHOTKEY = 0x0033;
pub const WM_QUERYDRAGICON = 0x0037;
pub const WM_COMPAREITEM = 0x0039;
pub const WM_GETOBJECT = 0x003D;
pub const WM_COMPACTING = 0x0041;
pub const WM_COMMNOTIFY = 0x0044;
pub const WM_WINDOWPOSCHANGING = 0x0046;
pub const WM_WINDOWPOSCHANGED = 0x0047;
pub const WM_POWER = 0x0048;
pub const WM_COPYGLOBALDATA = 0x0049;
pub const WM_COPYDATA = 0x004A;
pub const WM_CANCELJOURNAL = 0x004B;
pub const WM_NOTIFY = 0x004E;
pub const WM_INPUTLANGCHANGEREQUEST = 0x0050;
pub const WM_INPUTLANGCHANGE = 0x0051;
pub const WM_TCARD = 0x0052;
pub const WM_HELP = 0x0053;
pub const WM_USERCHANGED = 0x0054;
pub const WM_NOTIFYFORMAT = 0x0055;
pub const WM_CONTEXTMENU = 0x007B;
pub const WM_STYLECHANGING = 0x007C;
pub const WM_STYLECHANGED = 0x007D;
pub const WM_DISPLAYCHANGE = 0x007E;
pub const WM_GETICON = 0x007F;
pub const WM_SETICON = 0x0080;
pub const WM_NCCREATE = 0x0081;
pub const WM_NCDESTROY = 0x0082;
pub const WM_NCCALCSIZE = 0x0083;
pub const WM_NCHITTEST = 0x0084;
pub const WM_NCPAINT = 0x0085;
pub const WM_NCACTIVATE = 0x0086;
pub const WM_GETDLGCODE = 0x0087;
pub const WM_SYNCPAINT = 0x0088;
pub const WM_NCMOUSEMOVE = 0x00A0;
pub const WM_NCLBUTTONDOWN = 0x00A1;
pub const WM_NCLBUTTONUP = 0x00A2;
pub const WM_NCLBUTTONDBLCLK = 0x00A3;
pub const WM_NCRBUTTONDOWN = 0x00A4;
pub const WM_NCRBUTTONUP = 0x00A5;
pub const WM_NCRBUTTONDBLCLK = 0x00A6;
pub const WM_NCMBUTTONDOWN = 0x00A7;
pub const WM_NCMBUTTONUP = 0x00A8;
pub const WM_NCMBUTTONDBLCLK = 0x00A9;
pub const WM_NCXBUTTONDOWN = 0x00AB;
pub const WM_NCXBUTTONUP = 0x00AC;
pub const WM_NCXBUTTONDBLCLK = 0x00AD;
pub const EM_GETSEL = 0x00B0;
pub const EM_SETSEL = 0x00B1;
pub const EM_GETRECT = 0x00B2;
pub const EM_SETRECT = 0x00B3;
pub const EM_SETRECTNP = 0x00B4;
pub const EM_SCROLL = 0x00B5;
pub const EM_LINESCROLL = 0x00B6;
pub const EM_SCROLLCARET = 0x00B7;
pub const EM_GETMODIFY = 0x00B8;
pub const EM_SETMODIFY = 0x00B9;
pub const EM_GETLINECOUNT = 0x00BA;
pub const EM_LINEINDEX = 0x00BB;
pub const EM_SETHANDLE = 0x00BC;
pub const EM_GETHANDLE = 0x00BD;
pub const EM_GETTHUMB = 0x00BE;
pub const EM_LINELENGTH = 0x00C1;
pub const EM_REPLACESEL = 0x00C2;
pub const EM_SETFONT = 0x00C3;
pub const EM_GETLINE = 0x00C4;
pub const EM_LIMITTEXT = 0x00C5;
pub const EM_SETLIMITTEXT = 0x00C5;
pub const EM_CANUNDO = 0x00C6;
pub const EM_UNDO = 0x00C7;
pub const EM_FMTLINES = 0x00C8;
pub const EM_LINEFROMCHAR = 0x00C9;
pub const EM_SETWORDBREAK = 0x00CA;
pub const EM_SETTABSTOPS = 0x00CB;
pub const EM_SETPASSWORDCHAR = 0x00CC;
pub const EM_EMPTYUNDOBUFFER = 0x00CD;
pub const EM_GETFIRSTVISIBLELINE = 0x00CE;
pub const EM_SETREADONLY = 0x00CF;
pub const EM_SETWORDBREAKPROC = 0x00D0;
pub const EM_GETWORDBREAKPROC = 0x00D1;
pub const EM_GETPASSWORDCHAR = 0x00D2;
pub const EM_SETMARGINS = 0x00D3;
pub const EM_GETMARGINS = 0x00D4;
pub const EM_GETLIMITTEXT = 0x00D5;
pub const EM_POSFROMCHAR = 0x00D6;
pub const EM_CHARFROMPOS = 0x00D7;
pub const EM_SETIMESTATUS = 0x00D8;
pub const EM_GETIMESTATUS = 0x00D9;
pub const SBM_SETPOS = 0x00E0;
pub const SBM_GETPOS = 0x00E1;
pub const SBM_SETRANGE = 0x00E2;
pub const SBM_GETRANGE = 0x00E3;
pub const SBM_ENABLE_ARROWS = 0x00E4;
pub const SBM_SETRANGEREDRAW = 0x00E6;
pub const SBM_SETSCROLLINFO = 0x00E9;
pub const SBM_GETSCROLLINFO = 0x00EA;
pub const SBM_GETSCROLLBARINFO = 0x00EB;
pub const BM_GETCHECK = 0x00F0;
pub const BM_SETCHECK = 0x00F1;
pub const BM_GETSTATE = 0x00F2;
pub const BM_SETSTATE = 0x00F3;
pub const BM_SETSTYLE = 0x00F4;
pub const BM_CLICK = 0x00F5;
pub const BM_GETIMAGE = 0x00F6;
pub const BM_SETIMAGE = 0x00F7;
pub const BM_SETDONTCLICK = 0x00F8;
pub const WM_INPUT = 0x00FF;
pub const WM_KEYDOWN = 0x0100;
pub const WM_KEYUP = 0x0101;
pub const WM_CHAR = 0x0102;
pub const WM_DEADCHAR = 0x0103;
pub const WM_SYSKEYDOWN = 0x0104;
pub const WM_SYSKEYUP = 0x0105;
pub const WM_SYSCHAR = 0x0106;
pub const WM_SYSDEADCHAR = 0x0107;
pub const WM_UNICHAR = 0x0109;
pub const WM_WNT_CONVERTREQUESTEX = 0x0109;
pub const WM_CONVERTREQUEST = 0x010A;
pub const WM_CONVERTRESULT = 0x010B;
pub const WM_INTERIM = 0x010C;
pub const WM_IME_STARTCOMPOSITION = 0x010D;
pub const WM_IME_ENDCOMPOSITION = 0x010E;
pub const WM_IME_COMPOSITION = 0x010F;
pub const WM_INITDIALOG = 0x0110;
pub const WM_COMMAND = 0x0111;
pub const WM_SYSCOMMAND = 0x0112;
pub const WM_TIMER = 0x0113;
pub const WM_HSCROLL = 0x0114;
pub const WM_VSCROLL = 0x0115;
pub const WM_INITMENU = 0x0116;
pub const WM_INITMENUPOPUP = 0x0117;
pub const WM_SYSTIMER = 0x0118;
pub const WM_MENUSELECT = 0x011F;
pub const WM_MENUCHAR = 0x0120;
pub const WM_ENTERIDLE = 0x0121;
pub const WM_MENURBUTTONUP = 0x0122;
pub const WM_MENUDRAG = 0x0123;
pub const WM_MENUGETOBJECT = 0x0124;
pub const WM_UNINITMENUPOPUP = 0x0125;
pub const WM_MENUCOMMAND = 0x0126;
pub const WM_CHANGEUISTATE = 0x0127;
pub const WM_UPDATEUISTATE = 0x0128;
pub const WM_QUERYUISTATE = 0x0129;
pub const WM_CTLCOLORMSGBOX = 0x0132;
pub const WM_CTLCOLOREDIT = 0x0133;
pub const WM_CTLCOLORLISTBOX = 0x0134;
pub const WM_CTLCOLORBTN = 0x0135;
pub const WM_CTLCOLORDLG = 0x0136;
pub const WM_CTLCOLORSCROLLBAR = 0x0137;
pub const WM_CTLCOLORSTATIC = 0x0138;
pub const WM_MOUSEMOVE = 0x0200;
pub const WM_LBUTTONDOWN = 0x0201;
pub const WM_LBUTTONUP = 0x0202;
pub const WM_LBUTTONDBLCLK = 0x0203;
pub const WM_RBUTTONDOWN = 0x0204;
pub const WM_RBUTTONUP = 0x0205;
pub const WM_RBUTTONDBLCLK = 0x0206;
pub const WM_MBUTTONDOWN = 0x0207;
pub const WM_MBUTTONUP = 0x0208;
pub const WM_MBUTTONDBLCLK = 0x0209;
pub const WM_MOUSEWHEEL = 0x020A;
pub const WM_XBUTTONDOWN = 0x020B;
pub const WM_XBUTTONUP = 0x020C;
pub const WM_XBUTTONDBLCLK = 0x020D;
pub const WM_MOUSEHWHEEL = 0x020E;
pub const WM_PARENTNOTIFY = 0x0210;
pub const WM_ENTERMENULOOP = 0x0211;
pub const WM_EXITMENULOOP = 0x0212;
pub const WM_NEXTMENU = 0x0213;
pub const WM_SIZING = 0x0214;
pub const WM_CAPTURECHANGED = 0x0215;
pub const WM_MOVING = 0x0216;
pub const WM_POWERBROADCAST = 0x0218;
pub const WM_DEVICECHANGE = 0x0219;
pub const WM_MDICREATE = 0x0220;
pub const WM_MDIDESTROY = 0x0221;
pub const WM_MDIACTIVATE = 0x0222;
pub const WM_MDIRESTORE = 0x0223;
pub const WM_MDINEXT = 0x0224;
pub const WM_MDIMAXIMIZE = 0x0225;
pub const WM_MDITILE = 0x0226;
pub const WM_MDICASCADE = 0x0227;
pub const WM_MDIICONARRANGE = 0x0228;
pub const WM_MDIGETACTIVE = 0x0229;
pub const WM_MDISETMENU = 0x0230;
pub const WM_ENTERSIZEMOVE = 0x0231;
pub const WM_EXITSIZEMOVE = 0x0232;
pub const WM_DROPFILES = 0x0233;
pub const WM_MDIREFRESHMENU = 0x0234;
pub const WM_IME_REPORT = 0x0280;
pub const WM_IME_SETCONTEXT = 0x0281;
pub const WM_IME_NOTIFY = 0x0282;
pub const WM_IME_CONTROL = 0x0283;
pub const WM_IME_COMPOSITIONFULL = 0x0284;
pub const WM_IME_SELECT = 0x0285;
pub const WM_IME_CHAR = 0x0286;
pub const WM_IME_REQUEST = 0x0288;
pub const WM_IMEKEYDOWN = 0x0290;
pub const WM_IME_KEYDOWN = 0x0290;
pub const WM_IMEKEYUP = 0x0291;
pub const WM_IME_KEYUP = 0x0291;
pub const WM_NCMOUSEHOVER = 0x02A0;
pub const WM_MOUSEHOVER = 0x02A1;
pub const WM_NCMOUSELEAVE = 0x02A2;
pub const WM_MOUSELEAVE = 0x02A3;
pub const WM_CUT = 0x0300;
pub const WM_COPY = 0x0301;
pub const WM_PASTE = 0x0302;
pub const WM_CLEAR = 0x0303;
pub const WM_UNDO = 0x0304;
pub const WM_RENDERFORMAT = 0x0305;
pub const WM_RENDERALLFORMATS = 0x0306;
pub const WM_DESTROYCLIPBOARD = 0x0307;
pub const WM_DRAWCLIPBOARD = 0x0308;
pub const WM_PAINTCLIPBOARD = 0x0309;
pub const WM_VSCROLLCLIPBOARD = 0x030A;
pub const WM_SIZECLIPBOARD = 0x030B;
pub const WM_ASKCBFORMATNAME = 0x030C;
pub const WM_CHANGECBCHAIN = 0x030D;
pub const WM_HSCROLLCLIPBOARD = 0x030E;
pub const WM_QUERYNEWPALETTE = 0x030F;
pub const WM_PALETTEISCHANGING = 0x0310;
pub const WM_PALETTECHANGED = 0x0311;
pub const WM_HOTKEY = 0x0312;
pub const WM_PRINT = 0x0317;
pub const WM_PRINTCLIENT = 0x0318;
pub const WM_APPCOMMAND = 0x0319;
pub const WM_RCRESULT = 0x0381;
pub const WM_HOOKRCRESULT = 0x0382;
pub const WM_GLOBALRCCHANGE = 0x0383;
pub const WM_PENMISCINFO = 0x0383;
pub const WM_SKB = 0x0384;
pub const WM_HEDITCTL = 0x0385;
pub const WM_PENCTL = 0x0385;
pub const WM_PENMISC = 0x0386;
pub const WM_CTLINIT = 0x0387;
pub const WM_PENEVENT = 0x0388;
pub const WM_CARET_CREATE = 0x03E0;
pub const WM_CARET_DESTROY = 0x03E1;
pub const WM_CARET_BLINK = 0x03E2;
pub const WM_FDINPUT = 0x03F0;
pub const WM_FDOUTPUT = 0x03F1;
pub const WM_FDEXCEPT = 0x03F2;
pub const DDM_SETFMT = 0x0400;
pub const DM_GETDEFID = 0x0400;
pub const NIN_SELECT = 0x0400;
pub const TBM_GETPOS = 0x0400;
pub const WM_PSD_PAGESETUPDLG = 0x0400;
pub const WM_USER = 0x0400;
pub const CBEM_INSERTITEMA = 0x0401;
pub const DDM_DRAW = 0x0401;
pub const DM_SETDEFID = 0x0401;
pub const HKM_SETHOTKEY = 0x0401;
pub const PBM_SETRANGE = 0x0401;
pub const RB_INSERTBANDA = 0x0401;
pub const SB_SETTEXTA = 0x0401;
pub const TB_ENABLEBUTTON = 0x0401;
pub const TBM_GETRANGEMIN = 0x0401;
pub const TTM_ACTIVATE = 0x0401;
pub const WM_CHOOSEFONT_GETLOGFONT = 0x0401;
pub const WM_PSD_FULLPAGERECT = 0x0401;
pub const CBEM_SETIMAGELIST = 0x0402;
pub const DDM_CLOSE = 0x0402;
pub const DM_REPOSITION = 0x0402;
pub const HKM_GETHOTKEY = 0x0402;
pub const PBM_SETPOS = 0x0402;
pub const RB_DELETEBAND = 0x0402;
pub const SB_GETTEXTA = 0x0402;
pub const TB_CHECKBUTTON = 0x0402;
pub const TBM_GETRANGEMAX = 0x0402;
pub const WM_PSD_MINMARGINRECT = 0x0402;
pub const CBEM_GETIMAGELIST = 0x0403;
pub const DDM_BEGIN = 0x0403;
pub const HKM_SETRULES = 0x0403;
pub const PBM_DELTAPOS = 0x0403;
pub const RB_GETBARINFO = 0x0403;
pub const SB_GETTEXTLENGTHA = 0x0403;
pub const TBM_GETTIC = 0x0403;
pub const TB_PRESSBUTTON = 0x0403;
pub const TTM_SETDELAYTIME = 0x0403;
pub const WM_PSD_MARGINRECT = 0x0403;
pub const CBEM_GETITEMA = 0x0404;
pub const DDM_END = 0x0404;
pub const PBM_SETSTEP = 0x0404;
pub const RB_SETBARINFO = 0x0404;
pub const SB_SETPARTS = 0x0404;
pub const TB_HIDEBUTTON = 0x0404;
pub const TBM_SETTIC = 0x0404;
pub const TTM_ADDTOOLA = 0x0404;
pub const WM_PSD_GREEKTEXTRECT = 0x0404;
pub const CBEM_SETITEMA = 0x0405;
pub const PBM_STEPIT = 0x0405;
pub const TB_INDETERMINATE = 0x0405;
pub const TBM_SETPOS = 0x0405;
pub const TTM_DELTOOLA = 0x0405;
pub const WM_PSD_ENVSTAMPRECT = 0x0405;
pub const CBEM_GETCOMBOCONTROL = 0x0406;
pub const PBM_SETRANGE32 = 0x0406;
pub const RB_SETBANDINFOA = 0x0406;
pub const SB_GETPARTS = 0x0406;
pub const TB_MARKBUTTON = 0x0406;
pub const TBM_SETRANGE = 0x0406;
pub const TTM_NEWTOOLRECTA = 0x0406;
pub const WM_PSD_YAFULLPAGERECT = 0x0406;
pub const CBEM_GETEDITCONTROL = 0x0407;
pub const PBM_GETRANGE = 0x0407;
pub const RB_SETPARENT = 0x0407;
pub const SB_GETBORDERS = 0x0407;
pub const TBM_SETRANGEMIN = 0x0407;
pub const TTM_RELAYEVENT = 0x0407;
pub const CBEM_SETEXSTYLE = 0x0408;
pub const PBM_GETPOS = 0x0408;
pub const RB_HITTEST = 0x0408;
pub const SB_SETMINHEIGHT = 0x0408;
pub const TBM_SETRANGEMAX = 0x0408;
pub const TTM_GETTOOLINFOA = 0x0408;
pub const CBEM_GETEXSTYLE = 0x0409;
pub const CBEM_GETEXTENDEDSTYLE = 0x0409;
pub const PBM_SETBARCOLOR = 0x0409;
pub const RB_GETRECT = 0x0409;
pub const SB_SIMPLE = 0x0409;
pub const TB_ISBUTTONENABLED = 0x0409;
pub const TBM_CLEARTICS = 0x0409;
pub const TTM_SETTOOLINFOA = 0x0409;
pub const CBEM_HASEDITCHANGED = 0x040A;
pub const RB_INSERTBANDW = 0x040A;
pub const SB_GETRECT = 0x040A;
pub const TB_ISBUTTONCHECKED = 0x040A;
pub const TBM_SETSEL = 0x040A;
pub const TTM_HITTESTA = 0x040A;
pub const WIZ_QUERYNUMPAGES = 0x040A;
pub const CBEM_INSERTITEMW = 0x040B;
pub const RB_SETBANDINFOW = 0x040B;
pub const SB_SETTEXTW = 0x040B;
pub const TB_ISBUTTONPRESSED = 0x040B;
pub const TBM_SETSELSTART = 0x040B;
pub const TTM_GETTEXTA = 0x040B;
pub const WIZ_NEXT = 0x040B;
pub const CBEM_SETITEMW = 0x040C;
pub const RB_GETBANDCOUNT = 0x040C;
pub const SB_GETTEXTLENGTHW = 0x040C;
pub const TB_ISBUTTONHIDDEN = 0x040C;
pub const TBM_SETSELEND = 0x040C;
pub const TTM_UPDATETIPTEXTA = 0x040C;
pub const WIZ_PREV = 0x040C;
pub const CBEM_GETITEMW = 0x040D;
pub const RB_GETROWCOUNT = 0x040D;
pub const SB_GETTEXTW = 0x040D;
pub const TB_ISBUTTONINDETERMINATE = 0x040D;
pub const TTM_GETTOOLCOUNT = 0x040D;
pub const CBEM_SETEXTENDEDSTYLE = 0x040E;
pub const RB_GETROWHEIGHT = 0x040E;
pub const SB_ISSIMPLE = 0x040E;
pub const TB_ISBUTTONHIGHLIGHTED = 0x040E;
pub const TBM_GETPTICS = 0x040E;
pub const TTM_ENUMTOOLSA = 0x040E;
pub const SB_SETICON = 0x040F;
pub const TBM_GETTICPOS = 0x040F;
pub const TTM_GETCURRENTTOOLA = 0x040F;
pub const RB_IDTOINDEX = 0x0410;
pub const SB_SETTIPTEXTA = 0x0410;
pub const TBM_GETNUMTICS = 0x0410;
pub const TTM_WINDOWFROMPOINT = 0x0410;
pub const RB_GETTOOLTIPS = 0x0411;
pub const SB_SETTIPTEXTW = 0x0411;
pub const TBM_GETSELSTART = 0x0411;
pub const TB_SETSTATE = 0x0411;
pub const TTM_TRACKACTIVATE = 0x0411;
pub const RB_SETTOOLTIPS = 0x0412;
pub const SB_GETTIPTEXTA = 0x0412;
pub const TB_GETSTATE = 0x0412;
pub const TBM_GETSELEND = 0x0412;
pub const TTM_TRACKPOSITION = 0x0412;
pub const RB_SETBKCOLOR = 0x0413;
pub const SB_GETTIPTEXTW = 0x0413;
pub const TB_ADDBITMAP = 0x0413;
pub const TBM_CLEARSEL = 0x0413;
pub const TTM_SETTIPBKCOLOR = 0x0413;
pub const RB_GETBKCOLOR = 0x0414;
pub const SB_GETICON = 0x0414;
pub const TB_ADDBUTTONSA = 0x0414;
pub const TBM_SETTICFREQ = 0x0414;
pub const TTM_SETTIPTEXTCOLOR = 0x0414;
pub const RB_SETTEXTCOLOR = 0x0415;
pub const TB_INSERTBUTTONA = 0x0415;
pub const TBM_SETPAGESIZE = 0x0415;
pub const TTM_GETDELAYTIME = 0x0415;
pub const RB_GETTEXTCOLOR = 0x0416;
pub const TB_DELETEBUTTON = 0x0416;
pub const TBM_GETPAGESIZE = 0x0416;
pub const TTM_GETTIPBKCOLOR = 0x0416;
pub const RB_SIZETORECT = 0x0417;
pub const TB_GETBUTTON = 0x0417;
pub const TBM_SETLINESIZE = 0x0417;
pub const TTM_GETTIPTEXTCOLOR = 0x0417;
pub const RB_BEGINDRAG = 0x0418;
pub const TB_BUTTONCOUNT = 0x0418;
pub const TBM_GETLINESIZE = 0x0418;
pub const TTM_SETMAXTIPWIDTH = 0x0418;
pub const RB_ENDDRAG = 0x0419;
pub const TB_COMMANDTOINDEX = 0x0419;
pub const TBM_GETTHUMBRECT = 0x0419;
pub const TTM_GETMAXTIPWIDTH = 0x0419;
pub const RB_DRAGMOVE = 0x041A;
pub const TBM_GETCHANNELRECT = 0x041A;
pub const TB_SAVERESTOREA = 0x041A;
pub const TTM_SETMARGIN = 0x041A;
pub const RB_GETBARHEIGHT = 0x041B;
pub const TB_CUSTOMIZE = 0x041B;
pub const TBM_SETTHUMBLENGTH = 0x041B;
pub const TTM_GETMARGIN = 0x041B;
pub const RB_GETBANDINFOW = 0x041C;
pub const TB_ADDSTRINGA = 0x041C;
pub const TBM_GETTHUMBLENGTH = 0x041C;
pub const TTM_POP = 0x041C;
pub const RB_GETBANDINFOA = 0x041D;
pub const TB_GETITEMRECT = 0x041D;
pub const TBM_SETTOOLTIPS = 0x041D;
pub const TTM_UPDATE = 0x041D;
pub const RB_MINIMIZEBAND = 0x041E;
pub const TB_BUTTONSTRUCTSIZE = 0x041E;
pub const TBM_GETTOOLTIPS = 0x041E;
pub const TTM_GETBUBBLESIZE = 0x041E;
pub const RB_MAXIMIZEBAND = 0x041F;
pub const TBM_SETTIPSIDE = 0x041F;
pub const TB_SETBUTTONSIZE = 0x041F;
pub const TTM_ADJUSTRECT = 0x041F;
pub const TBM_SETBUDDY = 0x0420;
pub const TB_SETBITMAPSIZE = 0x0420;
pub const TTM_SETTITLEA = 0x0420;
pub const MSG_FTS_JUMP_VA = 0x0421;
pub const TB_AUTOSIZE = 0x0421;
pub const TBM_GETBUDDY = 0x0421;
pub const TTM_SETTITLEW = 0x0421;
pub const RB_GETBANDBORDERS = 0x0422;
pub const MSG_FTS_JUMP_QWORD = 0x0423;
pub const RB_SHOWBAND = 0x0423;
pub const TB_GETTOOLTIPS = 0x0423;
pub const MSG_REINDEX_REQUEST = 0x0424;
pub const TB_SETTOOLTIPS = 0x0424;
pub const MSG_FTS_WHERE_IS_IT = 0x0425;
pub const RB_SETPALETTE = 0x0425;
pub const TB_SETPARENT = 0x0425;
pub const RB_GETPALETTE = 0x0426;
pub const RB_MOVEBAND = 0x0427;
pub const TB_SETROWS = 0x0427;
pub const TB_GETROWS = 0x0428;
pub const TB_GETBITMAPFLAGS = 0x0429;
pub const TB_SETCMDID = 0x042A;
pub const RB_PUSHCHEVRON = 0x042B;
pub const TB_CHANGEBITMAP = 0x042B;
pub const TB_GETBITMAP = 0x042C;
pub const MSG_GET_DEFFONT = 0x042D;
pub const TB_GETBUTTONTEXTA = 0x042D;
pub const TB_REPLACEBITMAP = 0x042E;
pub const TB_SETINDENT = 0x042F;
pub const TB_SETIMAGELIST = 0x0430;
pub const TB_GETIMAGELIST = 0x0431;
pub const TB_LOADIMAGES = 0x0432;
pub const EM_CANPASTE = 0x0432;
pub const TTM_ADDTOOLW = 0x0432;
pub const EM_DISPLAYBAND = 0x0433;
pub const TB_GETRECT = 0x0433;
pub const TTM_DELTOOLW = 0x0433;
pub const EM_EXGETSEL = 0x0434;
pub const TB_SETHOTIMAGELIST = 0x0434;
pub const TTM_NEWTOOLRECTW = 0x0434;
pub const EM_EXLIMITTEXT = 0x0435;
pub const TB_GETHOTIMAGELIST = 0x0435;
pub const TTM_GETTOOLINFOW = 0x0435;
pub const EM_EXLINEFROMCHAR = 0x0436;
pub const TB_SETDISABLEDIMAGELIST = 0x0436;
pub const TTM_SETTOOLINFOW = 0x0436;
pub const EM_EXSETSEL = 0x0437;
pub const TB_GETDISABLEDIMAGELIST = 0x0437;
pub const TTM_HITTESTW = 0x0437;
pub const EM_FINDTEXT = 0x0438;
pub const TB_SETSTYLE = 0x0438;
pub const TTM_GETTEXTW = 0x0438;
pub const EM_FORMATRANGE = 0x0439;
pub const TB_GETSTYLE = 0x0439;
pub const TTM_UPDATETIPTEXTW = 0x0439;
pub const EM_GETCHARFORMAT = 0x043A;
pub const TB_GETBUTTONSIZE = 0x043A;
pub const TTM_ENUMTOOLSW = 0x043A;
pub const EM_GETEVENTMASK = 0x043B;
pub const TB_SETBUTTONWIDTH = 0x043B;
pub const TTM_GETCURRENTTOOLW = 0x043B;
pub const EM_GETOLEINTERFACE = 0x043C;
pub const TB_SETMAXTEXTROWS = 0x043C;
pub const EM_GETPARAFORMAT = 0x043D;
pub const TB_GETTEXTROWS = 0x043D;
pub const EM_GETSELTEXT = 0x043E;
pub const TB_GETOBJECT = 0x043E;
pub const EM_HIDESELECTION = 0x043F;
pub const TB_GETBUTTONINFOW = 0x043F;
pub const EM_PASTESPECIAL = 0x0440;
pub const TB_SETBUTTONINFOW = 0x0440;
pub const EM_REQUESTRESIZE = 0x0441;
pub const TB_GETBUTTONINFOA = 0x0441;
pub const EM_SELECTIONTYPE = 0x0442;
pub const TB_SETBUTTONINFOA = 0x0442;
pub const EM_SETBKGNDCOLOR = 0x0443;
pub const TB_INSERTBUTTONW = 0x0443;
pub const EM_SETCHARFORMAT = 0x0444;
pub const TB_ADDBUTTONSW = 0x0444;
pub const EM_SETEVENTMASK = 0x0445;
pub const TB_HITTEST = 0x0445;
pub const EM_SETOLECALLBACK = 0x0446;
pub const TB_SETDRAWTEXTFLAGS = 0x0446;
pub const EM_SETPARAFORMAT = 0x0447;
pub const TB_GETHOTITEM = 0x0447;
pub const EM_SETTARGETDEVICE = 0x0448;
pub const TB_SETHOTITEM = 0x0448;
pub const EM_STREAMIN = 0x0449;
pub const TB_SETANCHORHIGHLIGHT = 0x0449;
pub const EM_STREAMOUT = 0x044A;
pub const TB_GETANCHORHIGHLIGHT = 0x044A;
pub const EM_GETTEXTRANGE = 0x044B;
pub const TB_GETBUTTONTEXTW = 0x044B;
pub const EM_FINDWORDBREAK = 0x044C;
pub const TB_SAVERESTOREW = 0x044C;
pub const EM_SETOPTIONS = 0x044D;
pub const TB_ADDSTRINGW = 0x044D;
pub const EM_GETOPTIONS = 0x044E;
pub const TB_MAPACCELERATORA = 0x044E;
pub const EM_FINDTEXTEX = 0x044F;
pub const TB_GETINSERTMARK = 0x044F;
pub const EM_GETWORDBREAKPROCEX = 0x0450;
pub const TB_SETINSERTMARK = 0x0450;
pub const EM_SETWORDBREAKPROCEX = 0x0451;
pub const TB_INSERTMARKHITTEST = 0x0451;
pub const EM_SETUNDOLIMIT = 0x0452;
pub const TB_MOVEBUTTON = 0x0452;
pub const TB_GETMAXSIZE = 0x0453;
pub const EM_REDO = 0x0454;
pub const TB_SETEXTENDEDSTYLE = 0x0454;
pub const EM_CANREDO = 0x0455;
pub const TB_GETEXTENDEDSTYLE = 0x0455;
pub const EM_GETUNDONAME = 0x0456;
pub const TB_GETPADDING = 0x0456;
pub const EM_GETREDONAME = 0x0457;
pub const TB_SETPADDING = 0x0457;
pub const EM_STOPGROUPTYPING = 0x0458;
pub const TB_SETINSERTMARKCOLOR = 0x0458;
pub const EM_SETTEXTMODE = 0x0459;
pub const TB_GETINSERTMARKCOLOR = 0x0459;
pub const EM_GETTEXTMODE = 0x045A;
pub const TB_MAPACCELERATORW = 0x045A;
pub const EM_AUTOURLDETECT = 0x045B;
pub const TB_GETSTRINGW = 0x045B;
pub const EM_GETAUTOURLDETECT = 0x045C;
pub const TB_GETSTRINGA = 0x045C;
pub const EM_SETPALETTE = 0x045D;
pub const EM_GETTEXTEX = 0x045E;
pub const EM_GETTEXTLENGTHEX = 0x045F;
pub const EM_SHOWSCROLLBAR = 0x0460;
pub const EM_SETTEXTEX = 0x0461;
pub const TAPI_REPLY = 0x0463;
pub const ACM_OPENA = 0x0464;
pub const BFFM_SETSTATUSTEXTA = 0x0464;
pub const CDM_GETSPEC = 0x0464;
pub const EM_SETPUNCTUATION = 0x0464;
pub const IPM_CLEARADDRESS = 0x0464;
pub const WM_CAP_UNICODE_START = 0x0464;
pub const ACM_PLAY = 0x0465;
pub const BFFM_ENABLEOK = 0x0465;
pub const CDM_GETFILEPATH = 0x0465;
pub const EM_GETPUNCTUATION = 0x0465;
pub const IPM_SETADDRESS = 0x0465;
pub const PSM_SETCURSEL = 0x0465;
pub const UDM_SETRANGE = 0x0465;
pub const WM_CHOOSEFONT_SETLOGFONT = 0x0465;
pub const ACM_STOP = 0x0466;
pub const BFFM_SETSELECTIONA = 0x0466;
pub const CDM_GETFOLDERPATH = 0x0466;
pub const EM_SETWORDWRAPMODE = 0x0466;
pub const IPM_GETADDRESS = 0x0466;
pub const PSM_REMOVEPAGE = 0x0466;
pub const UDM_GETRANGE = 0x0466;
pub const WM_CAP_SET_CALLBACK_ERRORW = 0x0466;
pub const WM_CHOOSEFONT_SETFLAGS = 0x0466;
pub const ACM_OPENW = 0x0467;
pub const BFFM_SETSELECTIONW = 0x0467;
pub const CDM_GETFOLDERIDLIST = 0x0467;
pub const EM_GETWORDWRAPMODE = 0x0467;
pub const IPM_SETRANGE = 0x0467;
pub const PSM_ADDPAGE = 0x0467;
pub const UDM_SETPOS = 0x0467;
pub const WM_CAP_SET_CALLBACK_STATUSW = 0x0467;
pub const BFFM_SETSTATUSTEXTW = 0x0468;
pub const CDM_SETCONTROLTEXT = 0x0468;
pub const EM_SETIMECOLOR = 0x0468;
pub const IPM_SETFOCUS = 0x0468;
pub const PSM_CHANGED = 0x0468;
pub const UDM_GETPOS = 0x0468;
pub const CDM_HIDECONTROL = 0x0469;
pub const EM_GETIMECOLOR = 0x0469;
pub const IPM_ISBLANK = 0x0469;
pub const PSM_RESTARTWINDOWS = 0x0469;
pub const UDM_SETBUDDY = 0x0469;
pub const CDM_SETDEFEXT = 0x046A;
pub const EM_SETIMEOPTIONS = 0x046A;
pub const PSM_REBOOTSYSTEM = 0x046A;
pub const UDM_GETBUDDY = 0x046A;
pub const EM_GETIMEOPTIONS = 0x046B;
pub const PSM_CANCELTOCLOSE = 0x046B;
pub const UDM_SETACCEL = 0x046B;
pub const EM_CONVPOSITION = 0x046C;
pub const PSM_QUERYSIBLINGS = 0x046C;
pub const UDM_GETACCEL = 0x046C;
pub const MCIWNDM_GETZOOM = 0x046D;
pub const PSM_UNCHANGED = 0x046D;
pub const UDM_SETBASE = 0x046D;
pub const PSM_APPLY = 0x046E;
pub const UDM_GETBASE = 0x046E;
pub const PSM_SETTITLEA = 0x046F;
pub const UDM_SETRANGE32 = 0x046F;
pub const PSM_SETWIZBUTTONS = 0x0470;
pub const UDM_GETRANGE32 = 0x0470;
pub const WM_CAP_DRIVER_GET_NAMEW = 0x0470;
pub const PSM_PRESSBUTTON = 0x0471;
pub const UDM_SETPOS32 = 0x0471;
pub const WM_CAP_DRIVER_GET_VERSIONW = 0x0471;
pub const PSM_SETCURSELID = 0x0472;
pub const UDM_GETPOS32 = 0x0472;
pub const PSM_SETFINISHTEXTA = 0x0473;
pub const PSM_GETTABCONTROL = 0x0474;
pub const PSM_ISDIALOGMESSAGE = 0x0475;
pub const MCIWNDM_REALIZE = 0x0476;
pub const PSM_GETCURRENTPAGEHWND = 0x0476;
pub const MCIWNDM_SETTIMEFORMATA = 0x0477;
pub const PSM_INSERTPAGE = 0x0477;
pub const EM_SETLANGOPTIONS = 0x0478;
pub const MCIWNDM_GETTIMEFORMATA = 0x0478;
pub const PSM_SETTITLEW = 0x0478;
pub const WM_CAP_FILE_SET_CAPTURE_FILEW = 0x0478;
pub const EM_GETLANGOPTIONS = 0x0479;
pub const MCIWNDM_VALIDATEMEDIA = 0x0479;
pub const PSM_SETFINISHTEXTW = 0x0479;
pub const WM_CAP_FILE_GET_CAPTURE_FILEW = 0x0479;
pub const EM_GETIMECOMPMODE = 0x047A;
pub const EM_FINDTEXTW = 0x047B;
pub const MCIWNDM_PLAYTO = 0x047B;
pub const WM_CAP_FILE_SAVEASW = 0x047B;
pub const EM_FINDTEXTEXW = 0x047C;
pub const MCIWNDM_GETFILENAMEA = 0x047C;
pub const EM_RECONVERSION = 0x047D;
pub const MCIWNDM_GETDEVICEA = 0x047D;
pub const PSM_SETHEADERTITLEA = 0x047D;
pub const WM_CAP_FILE_SAVEDIBW = 0x047D;
pub const EM_SETIMEMODEBIAS = 0x047E;
pub const MCIWNDM_GETPALETTE = 0x047E;
pub const PSM_SETHEADERTITLEW = 0x047E;
pub const EM_GETIMEMODEBIAS = 0x047F;
pub const MCIWNDM_SETPALETTE = 0x047F;
pub const PSM_SETHEADERSUBTITLEA = 0x047F;
pub const MCIWNDM_GETERRORA = 0x0480;
pub const PSM_SETHEADERSUBTITLEW = 0x0480;
pub const PSM_HWNDTOINDEX = 0x0481;
pub const PSM_INDEXTOHWND = 0x0482;
pub const MCIWNDM_SETINACTIVETIMER = 0x0483;
pub const PSM_PAGETOINDEX = 0x0483;
pub const PSM_INDEXTOPAGE = 0x0484;
pub const DL_BEGINDRAG = 0x0485;
pub const MCIWNDM_GETINACTIVETIMER = 0x0485;
pub const PSM_IDTOINDEX = 0x0485;
pub const DL_DRAGGING = 0x0486;
pub const PSM_INDEXTOID = 0x0486;
pub const DL_DROPPED = 0x0487;
pub const PSM_GETRESULT = 0x0487;
pub const DL_CANCELDRAG = 0x0488;
pub const PSM_RECALCPAGESIZES = 0x0488;
pub const MCIWNDM_GET_SOURCE = 0x048C;
pub const MCIWNDM_PUT_SOURCE = 0x048D;
pub const MCIWNDM_GET_DEST = 0x048E;
pub const MCIWNDM_PUT_DEST = 0x048F;
pub const MCIWNDM_CAN_PLAY = 0x0490;
pub const MCIWNDM_CAN_WINDOW = 0x0491;
pub const MCIWNDM_CAN_RECORD = 0x0492;
pub const MCIWNDM_CAN_SAVE = 0x0493;
pub const MCIWNDM_CAN_EJECT = 0x0494;
pub const MCIWNDM_CAN_CONFIG = 0x0495;
pub const IE_GETINK = 0x0496;
pub const MCIWNDM_PALETTEKICK = 0x0496;
pub const IE_SETINK = 0x0497;
pub const IE_GETPENTIP = 0x0498;
pub const IE_SETPENTIP = 0x0499;
pub const IE_GETERASERTIP = 0x049A;
pub const IE_SETERASERTIP = 0x049B;
pub const IE_GETBKGND = 0x049C;
pub const IE_SETBKGND = 0x049D;
pub const IE_GETGRIDORIGIN = 0x049E;
pub const IE_SETGRIDORIGIN = 0x049F;
pub const IE_GETGRIDPEN = 0x04A0;
pub const IE_SETGRIDPEN = 0x04A1;
pub const IE_GETGRIDSIZE = 0x04A2;
pub const IE_SETGRIDSIZE = 0x04A3;
pub const IE_GETMODE = 0x04A4;
pub const IE_SETMODE = 0x04A5;
pub const IE_GETINKRECT = 0x04A6;
pub const WM_CAP_SET_MCI_DEVICEW = 0x04A6;
pub const WM_CAP_GET_MCI_DEVICEW = 0x04A7;
pub const WM_CAP_PAL_OPENW = 0x04B4;
pub const WM_CAP_PAL_SAVEW = 0x04B5;
pub const IE_GETAPPDATA = 0x04B8;
pub const IE_SETAPPDATA = 0x04B9;
pub const IE_GETDRAWOPTS = 0x04BA;
pub const IE_SETDRAWOPTS = 0x04BB;
pub const IE_GETFORMAT = 0x04BC;
pub const IE_SETFORMAT = 0x04BD;
pub const IE_GETINKINPUT = 0x04BE;
pub const IE_SETINKINPUT = 0x04BF;
pub const IE_GETNOTIFY = 0x04C0;
pub const IE_SETNOTIFY = 0x04C1;
pub const IE_GETRECOG = 0x04C2;
pub const IE_SETRECOG = 0x04C3;
pub const IE_GETSECURITY = 0x04C4;
pub const IE_SETSECURITY = 0x04C5;
pub const IE_GETSEL = 0x04C6;
pub const IE_SETSEL = 0x04C7;
pub const EM_SETBIDIOPTIONS = 0x04C8;
pub const IE_DOCOMMAND = 0x04C8;
pub const MCIWNDM_NOTIFYMODE = 0x04C8;
pub const EM_GETBIDIOPTIONS = 0x04C9;
pub const IE_GETCOMMAND = 0x04C9;
pub const EM_SETTYPOGRAPHYOPTIONS = 0x04CA;
pub const IE_GETCOUNT = 0x04CA;
pub const EM_GETTYPOGRAPHYOPTIONS = 0x04CB;
pub const IE_GETGESTURE = 0x04CB;
pub const MCIWNDM_NOTIFYMEDIA = 0x04CB;
pub const EM_SETEDITSTYLE = 0x04CC;
pub const IE_GETMENU = 0x04CC;
pub const EM_GETEDITSTYLE = 0x04CD;
pub const IE_GETPAINTDC = 0x04CD;
pub const MCIWNDM_NOTIFYERROR = 0x04CD;
pub const IE_GETPDEVENT = 0x04CE;
pub const IE_GETSELCOUNT = 0x04CF;
pub const IE_GETSELITEMS = 0x04D0;
pub const IE_GETSTYLE = 0x04D1;
pub const MCIWNDM_SETTIMEFORMATW = 0x04DB;
pub const EM_OUTLINE = 0x04DC;
pub const MCIWNDM_GETTIMEFORMATW = 0x04DC;
pub const EM_GETSCROLLPOS = 0x04DD;
pub const EM_SETSCROLLPOS = 0x04DE;
pub const EM_SETFONTSIZE = 0x04DF;
pub const EM_GETZOOM = 0x04E0;
pub const MCIWNDM_GETFILENAMEW = 0x04E0;
pub const EM_SETZOOM = 0x04E1;
pub const MCIWNDM_GETDEVICEW = 0x04E1;
pub const EM_GETVIEWKIND = 0x04E2;
pub const EM_SETVIEWKIND = 0x04E3;
pub const EM_GETPAGE = 0x04E4;
pub const MCIWNDM_GETERRORW = 0x04E4;
pub const EM_SETPAGE = 0x04E5;
pub const EM_GETHYPHENATEINFO = 0x04E6;
pub const EM_SETHYPHENATEINFO = 0x04E7;
pub const EM_GETPAGEROTATE = 0x04EB;
pub const EM_SETPAGEROTATE = 0x04EC;
pub const EM_GETCTFMODEBIAS = 0x04ED;
pub const EM_SETCTFMODEBIAS = 0x04EE;
pub const EM_GETCTFOPENSTATUS = 0x04F0;
pub const EM_SETCTFOPENSTATUS = 0x04F1;
pub const EM_GETIMECOMPTEXT = 0x04F2;
pub const EM_ISIME = 0x04F3;
pub const EM_GETIMEPROPERTY = 0x04F4;
pub const EM_GETQUERYRTFOBJ = 0x050D;
pub const EM_SETQUERYRTFOBJ = 0x050E;
pub const FM_GETFOCUS = 0x0600;
pub const FM_GETDRIVEINFOA = 0x0601;
pub const FM_GETSELCOUNT = 0x0602;
pub const FM_GETSELCOUNTLFN = 0x0603;
pub const FM_GETFILESELA = 0x0604;
pub const FM_GETFILESELLFNA = 0x0605;
pub const FM_REFRESH_WINDOWS = 0x0606;
pub const FM_RELOAD_EXTENSIONS = 0x0607;
pub const FM_GETDRIVEINFOW = 0x0611;
pub const FM_GETFILESELW = 0x0614;
pub const FM_GETFILESELLFNW = 0x0615;
pub const WLX_WM_SAS = 0x0659;
pub const SM_GETSELCOUNT = 0x07E8;
pub const UM_GETSELCOUNT = 0x07E8;
pub const WM_CPL_LAUNCH = 0x07E8;
pub const SM_GETSERVERSELA = 0x07E9;
pub const UM_GETUSERSELA = 0x07E9;
pub const WM_CPL_LAUNCHED = 0x07E9;
pub const SM_GETSERVERSELW = 0x07EA;
pub const UM_GETUSERSELW = 0x07EA;
pub const SM_GETCURFOCUSA = 0x07EB;
pub const UM_GETGROUPSELA = 0x07EB;
pub const SM_GETCURFOCUSW = 0x07EC;
pub const UM_GETGROUPSELW = 0x07EC;
pub const SM_GETOPTIONS = 0x07ED;
pub const UM_GETCURFOCUSA = 0x07ED;
pub const UM_GETCURFOCUSW = 0x07EE;
pub const UM_GETOPTIONS = 0x07EF;
pub const UM_GETOPTIONS2 = 0x07F0;
pub const LVM_GETBKCOLOR = 0x1000;
pub const LVM_SETBKCOLOR = 0x1001;
pub const LVM_GETIMAGELIST = 0x1002;
pub const LVM_SETIMAGELIST = 0x1003;
pub const LVM_GETITEMCOUNT = 0x1004;
pub const LVM_GETITEMA = 0x1005;
pub const LVM_SETITEMA = 0x1006;
pub const LVM_INSERTITEMA = 0x1007;
pub const LVM_DELETEITEM = 0x1008;
pub const LVM_DELETEALLITEMS = 0x1009;
pub const LVM_GETCALLBACKMASK = 0x100A;
pub const LVM_SETCALLBACKMASK = 0x100B;
pub const LVM_GETNEXTITEM = 0x100C;
pub const LVM_FINDITEMA = 0x100D;
pub const LVM_GETITEMRECT = 0x100E;
pub const LVM_SETITEMPOSITION = 0x100F;
pub const LVM_GETITEMPOSITION = 0x1010;
pub const LVM_GETSTRINGWIDTHA = 0x1011;
pub const LVM_HITTEST = 0x1012;
pub const LVM_ENSUREVISIBLE = 0x1013;
pub const LVM_SCROLL = 0x1014;
pub const LVM_REDRAWITEMS = 0x1015;
pub const LVM_ARRANGE = 0x1016;
pub const LVM_EDITLABELA = 0x1017;
pub const LVM_GETEDITCONTROL = 0x1018;
pub const LVM_GETCOLUMNA = 0x1019;
pub const LVM_SETCOLUMNA = 0x101A;
pub const LVM_INSERTCOLUMNA = 0x101B;
pub const LVM_DELETECOLUMN = 0x101C;
pub const LVM_GETCOLUMNWIDTH = 0x101D;
pub const LVM_SETCOLUMNWIDTH = 0x101E;
pub const LVM_GETHEADER = 0x101F;
pub const LVM_CREATEDRAGIMAGE = 0x1021;
pub const LVM_GETVIEWRECT = 0x1022;
pub const LVM_GETTEXTCOLOR = 0x1023;
pub const LVM_SETTEXTCOLOR = 0x1024;
pub const LVM_GETTEXTBKCOLOR = 0x1025;
pub const LVM_SETTEXTBKCOLOR = 0x1026;
pub const LVM_GETTOPINDEX = 0x1027;
pub const LVM_GETCOUNTPERPAGE = 0x1028;
pub const LVM_GETORIGIN = 0x1029;
pub const LVM_UPDATE = 0x102A;
pub const LVM_SETITEMSTATE = 0x102B;
pub const LVM_GETITEMSTATE = 0x102C;
pub const LVM_GETITEMTEXTA = 0x102D;
pub const LVM_SETITEMTEXTA = 0x102E;
pub const LVM_SETITEMCOUNT = 0x102F;
pub const LVM_SORTITEMS = 0x1030;
pub const LVM_SETITEMPOSITION32 = 0x1031;
pub const LVM_GETSELECTEDCOUNT = 0x1032;
pub const LVM_GETITEMSPACING = 0x1033;
pub const LVM_GETISEARCHSTRINGA = 0x1034;
pub const LVM_SETICONSPACING = 0x1035;
pub const LVM_SETEXTENDEDLISTVIEWSTYLE = 0x1036;
pub const LVM_GETEXTENDEDLISTVIEWSTYLE = 0x1037;
pub const LVM_GETSUBITEMRECT = 0x1038;
pub const LVM_SUBITEMHITTEST = 0x1039;
pub const LVM_SETCOLUMNORDERARRAY = 0x103A;
pub const LVM_GETCOLUMNORDERARRAY = 0x103B;
pub const LVM_SETHOTITEM = 0x103C;
pub const LVM_GETHOTITEM = 0x103D;
pub const LVM_SETHOTCURSOR = 0x103E;
pub const LVM_GETHOTCURSOR = 0x103F;
pub const LVM_APPROXIMATEVIEWRECT = 0x1040;
pub const LVM_SETWORKAREAS = 0x1041;
pub const LVM_GETSELECTIONMARK = 0x1042;
pub const LVM_SETSELECTIONMARK = 0x1043;
pub const LVM_SETBKIMAGEA = 0x1044;
pub const LVM_GETBKIMAGEA = 0x1045;
pub const LVM_GETWORKAREAS = 0x1046;
pub const LVM_SETHOVERTIME = 0x1047;
pub const LVM_GETHOVERTIME = 0x1048;
pub const LVM_GETNUMBEROFWORKAREAS = 0x1049;
pub const LVM_SETTOOLTIPS = 0x104A;
pub const LVM_GETITEMW = 0x104B;
pub const LVM_SETITEMW = 0x104C;
pub const LVM_INSERTITEMW = 0x104D;
pub const LVM_GETTOOLTIPS = 0x104E;
pub const LVM_FINDITEMW = 0x1053;
pub const LVM_GETSTRINGWIDTHW = 0x1057;
pub const LVM_GETCOLUMNW = 0x105F;
pub const LVM_SETCOLUMNW = 0x1060;
pub const LVM_INSERTCOLUMNW = 0x1061;
pub const LVM_GETITEMTEXTW = 0x1073;
pub const LVM_SETITEMTEXTW = 0x1074;
pub const LVM_GETISEARCHSTRINGW = 0x1075;
pub const LVM_EDITLABELW = 0x1076;
pub const LVM_GETBKIMAGEW = 0x108B;
pub const LVM_SETSELECTEDCOLUMN = 0x108C;
pub const LVM_SETTILEWIDTH = 0x108D;
pub const LVM_SETVIEW = 0x108E;
pub const LVM_GETVIEW = 0x108F;
pub const LVM_INSERTGROUP = 0x1091;
pub const LVM_SETGROUPINFO = 0x1093;
pub const LVM_GETGROUPINFO = 0x1095;
pub const LVM_REMOVEGROUP = 0x1096;
pub const LVM_MOVEGROUP = 0x1097;
pub const LVM_MOVEITEMTOGROUP = 0x109A;
pub const LVM_SETGROUPMETRICS = 0x109B;
pub const LVM_GETGROUPMETRICS = 0x109C;
pub const LVM_ENABLEGROUPVIEW = 0x109D;
pub const LVM_SORTGROUPS = 0x109E;
pub const LVM_INSERTGROUPSORTED = 0x109F;
pub const LVM_REMOVEALLGROUPS = 0x10A0;
pub const LVM_HASGROUP = 0x10A1;
pub const LVM_SETTILEVIEWINFO = 0x10A2;
pub const LVM_GETTILEVIEWINFO = 0x10A3;
pub const LVM_SETTILEINFO = 0x10A4;
pub const LVM_GETTILEINFO = 0x10A5;
pub const LVM_SETINSERTMARK = 0x10A6;
pub const LVM_GETINSERTMARK = 0x10A7;
pub const LVM_INSERTMARKHITTEST = 0x10A8;
pub const LVM_GETINSERTMARKRECT = 0x10A9;
pub const LVM_SETINSERTMARKCOLOR = 0x10AA;
pub const LVM_GETINSERTMARKCOLOR = 0x10AB;
pub const LVM_SETINFOTIP = 0x10AD;
pub const LVM_GETSELECTEDCOLUMN = 0x10AE;
pub const LVM_ISGROUPVIEWENABLED = 0x10AF;
pub const LVM_GETOUTLINECOLOR = 0x10B0;
pub const LVM_SETOUTLINECOLOR = 0x10B1;
pub const LVM_CANCELEDITLABEL = 0x10B3;
pub const LVM_MAPINDEXTOID = 0x10B4;
pub const LVM_MAPIDTOINDEX = 0x10B5;
pub const LVM_ISITEMVISIBLE = 0x10B6;
pub const OCM__BASE = 0x2000;
pub const LVM_SETUNICODEFORMAT = 0x2005;
pub const LVM_GETUNICODEFORMAT = 0x2006;
pub const OCM_CTLCOLOR = 0x2019;
pub const OCM_DRAWITEM = 0x202B;
pub const OCM_MEASUREITEM = 0x202C;
pub const OCM_DELETEITEM = 0x202D;
pub const OCM_VKEYTOITEM = 0x202E;
pub const OCM_CHARTOITEM = 0x202F;
pub const OCM_COMPAREITEM = 0x2039;
pub const OCM_NOTIFY = 0x204E;
pub const OCM_COMMAND = 0x2111;
pub const OCM_HSCROLL = 0x2114;
pub const OCM_VSCROLL = 0x2115;
pub const OCM_CTLCOLORMSGBOX = 0x2132;
pub const OCM_CTLCOLOREDIT = 0x2133;
pub const OCM_CTLCOLORLISTBOX = 0x2134;
pub const OCM_CTLCOLORBTN = 0x2135;
pub const OCM_CTLCOLORDLG = 0x2136;
pub const OCM_CTLCOLORSCROLLBAR = 0x2137;
pub const OCM_CTLCOLORSTATIC = 0x2138;
pub const OCM_PARENTNOTIFY = 0x2210;
pub const WM_APP = 0x8000;
pub const WM_RASDIALEVENT = 0xCCCD;

pub const PM_NOREMOVE = 0x0000;
pub const PM_REMOVE = 0x0001;
pub const PM_NOYIELD = 0x0002;

pub const MEM_COMMIT = 0x1000;
pub const MEM_RESERVE = 0x2000;
pub const MEM_FREE = 0x10000;
pub const MEM_RESET = 0x80000;
pub const MEM_RESET_UNDO = 0x1000000;
pub const MEM_LARGE_PAGES = 0x20000000;
pub const MEM_PHYSICAL = 0x400000;
pub const MEM_TOP_DOWN = 0x100000;
pub const MEM_WRITE_WATCH = 0x200000;

pub const PAGE_EXECUTE = 0x10;
pub const PAGE_EXECUTE_READ = 0x20;
pub const PAGE_EXECUTE_READWRITE = 0x40;
pub const PAGE_EXECUTE_WRITECOPY = 0x80;
pub const PAGE_NOACCESS = 0x01;
pub const PAGE_READONLY = 0x02;
pub const PAGE_READWRITE = 0x04;
pub const PAGE_WRITECOPY = 0x08;
pub const PAGE_TARGETS_INVALID = 0x40000000;
pub const PAGE_TARGETS_NO_UPDATE = 0x40000000; // Same as PAGE_TARGETS_INVALID
pub const PAGE_GUARD = 0x100;
pub const PAGE_NOCACHE = 0x200;
pub const PAGE_WRITECOMBINE = 0x400;

pub const BITMAPINFO = extern struct {
    bmiHeader: BITMAPINFOHEADER,
    bmiColors: [1]RGBQUAD = [1]RGBQUAD{RGBQUAD{}},
};

pub const BITMAPINFOHEADER = extern struct {
    biSize: DWORD = @sizeOf(BITMAPINFOHEADER),
    biWidth: LONG = 0,
    biHeight: LONG = 0,
    biPlanes: WORD = 1,
    biBitCount: WORD = 32,
    biCompression: DWORD = BI_RGB,
    biSizeImage: DWORD = 0,
    biXPelsPerMeter: LONG = 0,
    biYPelsPerMeter: LONG = 0,
    biClrUsed: DWORD = 0,
    biClrImportant: DWORD = 0,
};

pub const RGBQUAD = extern struct {
    rgbBlue: BYTE = 0,
    rgbGreen: BYTE = 0,
    rgbRed: BYTE = 0,
    rgbReserved: BYTE = 0,
};

pub const BI_RGB = 0;
pub const BI_RLE8 = 1;
pub const BI_RLE4 = 2;
pub const BI_BITFIELDS = 3;
pub const BI_JPEG = 4;
pub const BI_PNG = 5;

pub const DIB_RGB_COLORS = 0;
pub const DIB_PAL_COLORS = 1;

pub const SRCCOPY = 0x00CC0020;
pub const SRCPAINT = 0x00EE0086;
pub const SRCAND = 0x008800C6;
pub const SRCINVERT = 0x00660046;
pub const SRCERASE = 0x00440328;
pub const NOTSRCCOPY = 0x00330008;
pub const NOTSRCERASE = 0x001100A6;
pub const MERGECOPY = 0x00C000CA;
pub const MERGEPAINT = 0x00BB0226;
pub const PATCOPY = 0x00F00021;
pub const PATPAINT = 0x00FB0A09;
pub const PATINVERT = 0x005A0049;
pub const DSTINVERT = 0x00550009;
pub const BLACKNESS = 0x00000042;
pub const WHITENESS = 0x00FF0062;

/// Codes are from https://docs.microsoft.com/en-us/openspecs/windows_protocols/ms-erref/18d8fbe8-a967-4f1c-ae50-99ca8e491d2d
pub const Win32Error = enum(u16) {
    /// The operation completed successfully.
    SUCCESS = 0,
    /// Incorrect function.
    INVALID_FUNCTION = 1,
    /// The system cannot find the file specified.
    FILE_NOT_FOUND = 2,
    /// The system cannot find the path specified.
    PATH_NOT_FOUND = 3,
    /// The system cannot open the file.
    TOO_MANY_OPEN_FILES = 4,
    /// Access is denied.
    ACCESS_DENIED = 5,
    /// The handle is invalid.
    INVALID_HANDLE = 6,
    /// The storage control blocks were destroyed.
    ARENA_TRASHED = 7,
    /// Not enough storage is available to process this command.
    NOT_ENOUGH_MEMORY = 8,
    /// The storage control block address is invalid.
    INVALID_BLOCK = 9,
    /// The environment is incorrect.
    BAD_ENVIRONMENT = 10,
    /// An attempt was made to load a program with an incorrect format.
    BAD_FORMAT = 11,
    /// The access code is invalid.
    INVALID_ACCESS = 12,
    /// The data is invalid.
    INVALID_DATA = 13,
    /// Not enough storage is available to complete this operation.
    OUTOFMEMORY = 14,
    /// The system cannot find the drive specified.
    INVALID_DRIVE = 15,
    /// The directory cannot be removed.
    CURRENT_DIRECTORY = 16,
    /// The system cannot move the file to a different disk drive.
    NOT_SAME_DEVICE = 17,
    /// There are no more files.
    NO_MORE_FILES = 18,
    /// The media is write protected.
    WRITE_PROTECT = 19,
    /// The system cannot find the device specified.
    BAD_UNIT = 20,
    /// The device is not ready.
    NOT_READY = 21,
    /// The device does not recognize the command.
    BAD_COMMAND = 22,
    /// Data error (cyclic redundancy check).
    CRC = 23,
    /// The program issued a command but the command length is incorrect.
    BAD_LENGTH = 24,
    /// The drive cannot locate a specific area or track on the disk.
    SEEK = 25,
    /// The specified disk or diskette cannot be accessed.
    NOT_DOS_DISK = 26,
    /// The drive cannot find the sector requested.
    SECTOR_NOT_FOUND = 27,
    /// The printer is out of paper.
    OUT_OF_PAPER = 28,
    /// The system cannot write to the specified device.
    WRITE_FAULT = 29,
    /// The system cannot read from the specified device.
    READ_FAULT = 30,
    /// A device attached to the system is not functioning.
    GEN_FAILURE = 31,
    /// The process cannot access the file because it is being used by another process.
    SHARING_VIOLATION = 32,
    /// The process cannot access the file because another process has locked a portion of the file.
    LOCK_VIOLATION = 33,
    /// The wrong diskette is in the drive.
    /// Insert %2 (Volume Serial Number: %3) into drive %1.
    WRONG_DISK = 34,
    /// Too many files opened for sharing.
    SHARING_BUFFER_EXCEEDED = 36,
    /// Reached the end of the file.
    HANDLE_EOF = 38,
    /// The disk is full.
    HANDLE_DISK_FULL = 39,
    /// The request is not supported.
    NOT_SUPPORTED = 50,
    /// Windows cannot find the network path.
    /// Verify that the network path is correct and the destination computer is not busy or turned off.
    /// If Windows still cannot find the network path, contact your network administrator.
    REM_NOT_LIST = 51,
    /// You were not connected because a duplicate name exists on the network.
    /// If joining a domain, go to System in Control Panel to change the computer name and try again.
    /// If joining a workgroup, choose another workgroup name.
    DUP_NAME = 52,
    /// The network path was not found.
    BAD_NETPATH = 53,
    /// The network is busy.
    NETWORK_BUSY = 54,
    /// The specified network resource or device is no longer available.
    DEV_NOT_EXIST = 55,
    /// The network BIOS command limit has been reached.
    TOO_MANY_CMDS = 56,
    /// A network adapter hardware error occurred.
    ADAP_HDW_ERR = 57,
    /// The specified server cannot perform the requested operation.
    BAD_NET_RESP = 58,
    /// An unexpected network error occurred.
    UNEXP_NET_ERR = 59,
    /// The remote adapter is not compatible.
    BAD_REM_ADAP = 60,
    /// The printer queue is full.
    PRINTQ_FULL = 61,
    /// Space to store the file waiting to be printed is not available on the server.
    NO_SPOOL_SPACE = 62,
    /// Your file waiting to be printed was deleted.
    PRINT_CANCELLED = 63,
    /// The specified network name is no longer available.
    NETNAME_DELETED = 64,
    /// Network access is denied.
    NETWORK_ACCESS_DENIED = 65,
    /// The network resource type is not correct.
    BAD_DEV_TYPE = 66,
    /// The network name cannot be found.
    BAD_NET_NAME = 67,
    /// The name limit for the local computer network adapter card was exceeded.
    TOO_MANY_NAMES = 68,
    /// The network BIOS session limit was exceeded.
    TOO_MANY_SESS = 69,
    /// The remote server has been paused or is in the process of being started.
    SHARING_PAUSED = 70,
    /// No more connections can be made to this remote computer at this time because there are already as many connections as the computer can accept.
    REQ_NOT_ACCEP = 71,
    /// The specified printer or disk device has been paused.
    REDIR_PAUSED = 72,
    /// The file exists.
    FILE_EXISTS = 80,
    /// The directory or file cannot be created.
    CANNOT_MAKE = 82,
    /// Fail on INT 24.
    FAIL_I24 = 83,
    /// Storage to process this request is not available.
    OUT_OF_STRUCTURES = 84,
    /// The local device name is already in use.
    ALREADY_ASSIGNED = 85,
    /// The specified network password is not correct.
    INVALID_PASSWORD = 86,
    /// The parameter is incorrect.
    INVALID_PARAMETER = 87,
    /// A write fault occurred on the network.
    NET_WRITE_FAULT = 88,
    /// The system cannot start another process at this time.
    NO_PROC_SLOTS = 89,
    /// Cannot create another system semaphore.
    TOO_MANY_SEMAPHORES = 100,
    /// The exclusive semaphore is owned by another process.
    EXCL_SEM_ALREADY_OWNED = 101,
    /// The semaphore is set and cannot be closed.
    SEM_IS_SET = 102,
    /// The semaphore cannot be set again.
    TOO_MANY_SEM_REQUESTS = 103,
    /// Cannot request exclusive semaphores at interrupt time.
    INVALID_AT_INTERRUPT_TIME = 104,
    /// The previous ownership of this semaphore has ended.
    SEM_OWNER_DIED = 105,
    /// Insert the diskette for drive %1.
    SEM_USER_LIMIT = 106,
    /// The program stopped because an alternate diskette was not inserted.
    DISK_CHANGE = 107,
    /// The disk is in use or locked by another process.
    DRIVE_LOCKED = 108,
    /// The pipe has been ended.
    BROKEN_PIPE = 109,
    /// The system cannot open the device or file specified.
    OPEN_FAILED = 110,
    /// The file name is too long.
    BUFFER_OVERFLOW = 111,
    /// There is not enough space on the disk.
    DISK_FULL = 112,
    /// No more internal file identifiers available.
    NO_MORE_SEARCH_HANDLES = 113,
    /// The target internal file identifier is incorrect.
    INVALID_TARGET_HANDLE = 114,
    /// The IOCTL call made by the application program is not correct.
    INVALID_CATEGORY = 117,
    /// The verify-on-write switch parameter value is not correct.
    INVALID_VERIFY_SWITCH = 118,
    /// The system does not support the command requested.
    BAD_DRIVER_LEVEL = 119,
    /// This function is not supported on this system.
    CALL_NOT_IMPLEMENTED = 120,
    /// The semaphore timeout period has expired.
    SEM_TIMEOUT = 121,
    /// The data area passed to a system call is too small.
    INSUFFICIENT_BUFFER = 122,
    /// The filename, directory name, or volume label syntax is incorrect.
    INVALID_NAME = 123,
    /// The system call level is not correct.
    INVALID_LEVEL = 124,
    /// The disk has no volume label.
    NO_VOLUME_LABEL = 125,
    /// The specified module could not be found.
    MOD_NOT_FOUND = 126,
    /// The specified procedure could not be found.
    PROC_NOT_FOUND = 127,
    /// There are no child processes to wait for.
    WAIT_NO_CHILDREN = 128,
    /// The %1 application cannot be run in Win32 mode.
    CHILD_NOT_COMPLETE = 129,
    /// Attempt to use a file handle to an open disk partition for an operation other than raw disk I/O.
    DIRECT_ACCESS_HANDLE = 130,
    /// An attempt was made to move the file pointer before the beginning of the file.
    NEGATIVE_SEEK = 131,
    /// The file pointer cannot be set on the specified device or file.
    SEEK_ON_DEVICE = 132,
    /// A JOIN or SUBST command cannot be used for a drive that contains previously joined drives.
    IS_JOIN_TARGET = 133,
    /// An attempt was made to use a JOIN or SUBST command on a drive that has already been joined.
    IS_JOINED = 134,
    /// An attempt was made to use a JOIN or SUBST command on a drive that has already been substituted.
    IS_SUBSTED = 135,
    /// The system tried to delete the JOIN of a drive that is not joined.
    NOT_JOINED = 136,
    /// The system tried to delete the substitution of a drive that is not substituted.
    NOT_SUBSTED = 137,
    /// The system tried to join a drive to a directory on a joined drive.
    JOIN_TO_JOIN = 138,
    /// The system tried to substitute a drive to a directory on a substituted drive.
    SUBST_TO_SUBST = 139,
    /// The system tried to join a drive to a directory on a substituted drive.
    JOIN_TO_SUBST = 140,
    /// The system tried to SUBST a drive to a directory on a joined drive.
    SUBST_TO_JOIN = 141,
    /// The system cannot perform a JOIN or SUBST at this time.
    BUSY_DRIVE = 142,
    /// The system cannot join or substitute a drive to or for a directory on the same drive.
    SAME_DRIVE = 143,
    /// The directory is not a subdirectory of the root directory.
    DIR_NOT_ROOT = 144,
    /// The directory is not empty.
    DIR_NOT_EMPTY = 145,
    /// The path specified is being used in a substitute.
    IS_SUBST_PATH = 146,
    /// Not enough resources are available to process this command.
    IS_JOIN_PATH = 147,
    /// The path specified cannot be used at this time.
    PATH_BUSY = 148,
    /// An attempt was made to join or substitute a drive for which a directory on the drive is the target of a previous substitute.
    IS_SUBST_TARGET = 149,
    /// System trace information was not specified in your CONFIG.SYS file, or tracing is disallowed.
    SYSTEM_TRACE = 150,
    /// The number of specified semaphore events for DosMuxSemWait is not correct.
    INVALID_EVENT_COUNT = 151,
    /// DosMuxSemWait did not execute; too many semaphores are already set.
    TOO_MANY_MUXWAITERS = 152,
    /// The DosMuxSemWait list is not correct.
    INVALID_LIST_FORMAT = 153,
    /// The volume label you entered exceeds the label character limit of the target file system.
    LABEL_TOO_LONG = 154,
    /// Cannot create another thread.
    TOO_MANY_TCBS = 155,
    /// The recipient process has refused the signal.
    SIGNAL_REFUSED = 156,
    /// The segment is already discarded and cannot be locked.
    DISCARDED = 157,
    /// The segment is already unlocked.
    NOT_LOCKED = 158,
    /// The address for the thread ID is not correct.
    BAD_THREADID_ADDR = 159,
    /// One or more arguments are not correct.
    BAD_ARGUMENTS = 160,
    /// The specified path is invalid.
    BAD_PATHNAME = 161,
    /// A signal is already pending.
    SIGNAL_PENDING = 162,
    /// No more threads can be created in the system.
    MAX_THRDS_REACHED = 164,
    /// Unable to lock a region of a file.
    LOCK_FAILED = 167,
    /// The requested resource is in use.
    BUSY = 170,
    /// Device's command support detection is in progress.
    DEVICE_SUPPORT_IN_PROGRESS = 171,
    /// A lock request was not outstanding for the supplied cancel region.
    CANCEL_VIOLATION = 173,
    /// The file system does not support atomic changes to the lock type.
    ATOMIC_LOCKS_NOT_SUPPORTED = 174,
    /// The system detected a segment number that was not correct.
    INVALID_SEGMENT_NUMBER = 180,
    /// The operating system cannot run %1.
    INVALID_ORDINAL = 182,
    /// Cannot create a file when that file already exists.
    ALREADY_EXISTS = 183,
    /// The flag passed is not correct.
    INVALID_FLAG_NUMBER = 186,
    /// The specified system semaphore name was not found.
    SEM_NOT_FOUND = 187,
    /// The operating system cannot run %1.
    INVALID_STARTING_CODESEG = 188,
    /// The operating system cannot run %1.
    INVALID_STACKSEG = 189,
    /// The operating system cannot run %1.
    INVALID_MODULETYPE = 190,
    /// Cannot run %1 in Win32 mode.
    INVALID_EXE_SIGNATURE = 191,
    /// The operating system cannot run %1.
    EXE_MARKED_INVALID = 192,
    /// %1 is not a valid Win32 application.
    BAD_EXE_FORMAT = 193,
    /// The operating system cannot run %1.
    ITERATED_DATA_EXCEEDS_64k = 194,
    /// The operating system cannot run %1.
    INVALID_MINALLOCSIZE = 195,
    /// The operating system cannot run this application program.
    DYNLINK_FROM_INVALID_RING = 196,
    /// The operating system is not presently configured to run this application.
    IOPL_NOT_ENABLED = 197,
    /// The operating system cannot run %1.
    INVALID_SEGDPL = 198,
    /// The operating system cannot run this application program.
    AUTODATASEG_EXCEEDS_64k = 199,
    /// The code segment cannot be greater than or equal to 64K.
    RING2SEG_MUST_BE_MOVABLE = 200,
    /// The operating system cannot run %1.
    RELOC_CHAIN_XEEDS_SEGLIM = 201,
    /// The operating system cannot run %1.
    INFLOOP_IN_RELOC_CHAIN = 202,
    /// The system could not find the environment option that was entered.
    ENVVAR_NOT_FOUND = 203,
    /// No process in the command subtree has a signal handler.
    NO_SIGNAL_SENT = 205,
    /// The filename or extension is too long.
    FILENAME_EXCED_RANGE = 206,
    /// The ring 2 stack is in use.
    RING2_STACK_IN_USE = 207,
    /// The global filename characters, * or ?, are entered incorrectly or too many global filename characters are specified.
    META_EXPANSION_TOO_LONG = 208,
    /// The signal being posted is not correct.
    INVALID_SIGNAL_NUMBER = 209,
    /// The signal handler cannot be set.
    THREAD_1_INACTIVE = 210,
    /// The segment is locked and cannot be reallocated.
    LOCKED = 212,
    /// Too many dynamic-link modules are attached to this program or dynamic-link module.
    TOO_MANY_MODULES = 214,
    /// Cannot nest calls to LoadModule.
    NESTING_NOT_ALLOWED = 215,
    /// This version of %1 is not compatible with the version of Windows you're running.
    /// Check your computer's system information and then contact the software publisher.
    EXE_MACHINE_TYPE_MISMATCH = 216,
    /// The image file %1 is signed, unable to modify.
    EXE_CANNOT_MODIFY_SIGNED_BINARY = 217,
    /// The image file %1 is strong signed, unable to modify.
    EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY = 218,
    /// This file is checked out or locked for editing by another user.
    FILE_CHECKED_OUT = 220,
    /// The file must be checked out before saving changes.
    CHECKOUT_REQUIRED = 221,
    /// The file type being saved or retrieved has been blocked.
    BAD_FILE_TYPE = 222,
    /// The file size exceeds the limit allowed and cannot be saved.
    FILE_TOO_LARGE = 223,
    /// Access Denied. Before opening files in this location, you must first add the web site to your trusted sites list, browse to the web site, and select the option to login automatically.
    FORMS_AUTH_REQUIRED = 224,
    /// Operation did not complete successfully because the file contains a virus or potentially unwanted software.
    VIRUS_INFECTED = 225,
    /// This file contains a virus or potentially unwanted software and cannot be opened.
    /// Due to the nature of this virus or potentially unwanted software, the file has been removed from this location.
    VIRUS_DELETED = 226,
    /// The pipe is local.
    PIPE_LOCAL = 229,
    /// The pipe state is invalid.
    BAD_PIPE = 230,
    /// All pipe instances are busy.
    PIPE_BUSY = 231,
    /// The pipe is being closed.
    NO_DATA = 232,
    /// No process is on the other end of the pipe.
    PIPE_NOT_CONNECTED = 233,
    /// More data is available.
    MORE_DATA = 234,
    /// The session was canceled.
    VC_DISCONNECTED = 240,
    /// The specified extended attribute name was invalid.
    INVALID_EA_NAME = 254,
    /// The extended attributes are inconsistent.
    EA_LIST_INCONSISTENT = 255,
    /// The wait operation timed out.
    IMEOUT = 258,
    /// No more data is available.
    NO_MORE_ITEMS = 259,
    /// The copy functions cannot be used.
    CANNOT_COPY = 266,
    /// The directory name is invalid.
    DIRECTORY = 267,
    /// The extended attributes did not fit in the buffer.
    EAS_DIDNT_FIT = 275,
    /// The extended attribute file on the mounted file system is corrupt.
    EA_FILE_CORRUPT = 276,
    /// The extended attribute table file is full.
    EA_TABLE_FULL = 277,
    /// The specified extended attribute handle is invalid.
    INVALID_EA_HANDLE = 278,
    /// The mounted file system does not support extended attributes.
    EAS_NOT_SUPPORTED = 282,
    /// Attempt to release mutex not owned by caller.
    NOT_OWNER = 288,
    /// Too many posts were made to a semaphore.
    TOO_MANY_POSTS = 298,
    /// Only part of a ReadProcessMemory or WriteProcessMemory request was completed.
    PARTIAL_COPY = 299,
    /// The oplock request is denied.
    OPLOCK_NOT_GRANTED = 300,
    /// An invalid oplock acknowledgment was received by the system.
    INVALID_OPLOCK_PROTOCOL = 301,
    /// The volume is too fragmented to complete this operation.
    DISK_TOO_FRAGMENTED = 302,
    /// The file cannot be opened because it is in the process of being deleted.
    DELETE_PENDING = 303,
    /// Short name settings may not be changed on this volume due to the global registry setting.
    INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING = 304,
    /// Short names are not enabled on this volume.
    SHORT_NAMES_NOT_ENABLED_ON_VOLUME = 305,
    /// The security stream for the given volume is in an inconsistent state. Please run CHKDSK on the volume.
    SECURITY_STREAM_IS_INCONSISTENT = 306,
    /// A requested file lock operation cannot be processed due to an invalid byte range.
    INVALID_LOCK_RANGE = 307,
    /// The subsystem needed to support the image type is not present.
    IMAGE_SUBSYSTEM_NOT_PRESENT = 308,
    /// The specified file already has a notification GUID associated with it.
    NOTIFICATION_GUID_ALREADY_DEFINED = 309,
    /// An invalid exception handler routine has been detected.
    INVALID_EXCEPTION_HANDLER = 310,
    /// Duplicate privileges were specified for the token.
    DUPLICATE_PRIVILEGES = 311,
    /// No ranges for the specified operation were able to be processed.
    NO_RANGES_PROCESSED = 312,
    /// Operation is not allowed on a file system internal file.
    NOT_ALLOWED_ON_SYSTEM_FILE = 313,
    /// The physical resources of this disk have been exhausted.
    DISK_RESOURCES_EXHAUSTED = 314,
    /// The token representing the data is invalid.
    INVALID_TOKEN = 315,
    /// The device does not support the command feature.
    DEVICE_FEATURE_NOT_SUPPORTED = 316,
    /// The system cannot find message text for message number 0x%1 in the message file for %2.
    MR_MID_NOT_FOUND = 317,
    /// The scope specified was not found.
    SCOPE_NOT_FOUND = 318,
    /// The Central Access Policy specified is not defined on the target machine.
    UNDEFINED_SCOPE = 319,
    /// The Central Access Policy obtained from Active Directory is invalid.
    INVALID_CAP = 320,
    /// The device is unreachable.
    DEVICE_UNREACHABLE = 321,
    /// The target device has insufficient resources to complete the operation.
    DEVICE_NO_RESOURCES = 322,
    /// A data integrity checksum error occurred. Data in the file stream is corrupt.
    DATA_CHECKSUM_ERROR = 323,
    /// An attempt was made to modify both a KERNEL and normal Extended Attribute (EA) in the same operation.
    INTERMIXED_KERNEL_EA_OPERATION = 324,
    /// Device does not support file-level TRIM.
    FILE_LEVEL_TRIM_NOT_SUPPORTED = 326,
    /// The command specified a data offset that does not align to the device's granularity/alignment.
    OFFSET_ALIGNMENT_VIOLATION = 327,
    /// The command specified an invalid field in its parameter list.
    INVALID_FIELD_IN_PARAMETER_LIST = 328,
    /// An operation is currently in progress with the device.
    OPERATION_IN_PROGRESS = 329,
    /// An attempt was made to send down the command via an invalid path to the target device.
    BAD_DEVICE_PATH = 330,
    /// The command specified a number of descriptors that exceeded the maximum supported by the device.
    TOO_MANY_DESCRIPTORS = 331,
    /// Scrub is disabled on the specified file.
    SCRUB_DATA_DISABLED = 332,
    /// The storage device does not provide redundancy.
    NOT_REDUNDANT_STORAGE = 333,
    /// An operation is not supported on a resident file.
    RESIDENT_FILE_NOT_SUPPORTED = 334,
    /// An operation is not supported on a compressed file.
    COMPRESSED_FILE_NOT_SUPPORTED = 335,
    /// An operation is not supported on a directory.
    DIRECTORY_NOT_SUPPORTED = 336,
    /// The specified copy of the requested data could not be read.
    NOT_READ_FROM_COPY = 337,
    /// No action was taken as a system reboot is required.
    FAIL_NOACTION_REBOOT = 350,
    /// The shutdown operation failed.
    FAIL_SHUTDOWN = 351,
    /// The restart operation failed.
    FAIL_RESTART = 352,
    /// The maximum number of sessions has been reached.
    MAX_SESSIONS_REACHED = 353,
    /// The thread is already in background processing mode.
    THREAD_MODE_ALREADY_BACKGROUND = 400,
    /// The thread is not in background processing mode.
    THREAD_MODE_NOT_BACKGROUND = 401,
    /// The process is already in background processing mode.
    PROCESS_MODE_ALREADY_BACKGROUND = 402,
    /// The process is not in background processing mode.
    PROCESS_MODE_NOT_BACKGROUND = 403,
    /// Attempt to access invalid address.
    INVALID_ADDRESS = 487,
    /// User profile cannot be loaded.
    USER_PROFILE_LOAD = 500,
    /// Arithmetic result exceeded 32 bits.
    ARITHMETIC_OVERFLOW = 534,
    /// There is a process on other end of the pipe.
    PIPE_CONNECTED = 535,
    /// Waiting for a process to open the other end of the pipe.
    PIPE_LISTENING = 536,
    /// Application verifier has found an error in the current process.
    VERIFIER_STOP = 537,
    /// An error occurred in the ABIOS subsystem.
    ABIOS_ERROR = 538,
    /// A warning occurred in the WX86 subsystem.
    WX86_WARNING = 539,
    /// An error occurred in the WX86 subsystem.
    WX86_ERROR = 540,
    /// An attempt was made to cancel or set a timer that has an associated APC and the subject thread is not the thread that originally set the timer with an associated APC routine.
    TIMER_NOT_CANCELED = 541,
    /// Unwind exception code.
    UNWIND = 542,
    /// An invalid or unaligned stack was encountered during an unwind operation.
    BAD_STACK = 543,
    /// An invalid unwind target was encountered during an unwind operation.
    INVALID_UNWIND_TARGET = 544,
    /// Invalid Object Attributes specified to NtCreatePort or invalid Port Attributes specified to NtConnectPort
    INVALID_PORT_ATTRIBUTES = 545,
    /// Length of message passed to NtRequestPort or NtRequestWaitReplyPort was longer than the maximum message allowed by the port.
    PORT_MESSAGE_TOO_LONG = 546,
    /// An attempt was made to lower a quota limit below the current usage.
    INVALID_QUOTA_LOWER = 547,
    /// An attempt was made to attach to a device that was already attached to another device.
    DEVICE_ALREADY_ATTACHED = 548,
    /// An attempt was made to execute an instruction at an unaligned address and the host system does not support unaligned instruction references.
    INSTRUCTION_MISALIGNMENT = 549,
    /// Profiling not started.
    PROFILING_NOT_STARTED = 550,
    /// Profiling not stopped.
    PROFILING_NOT_STOPPED = 551,
    /// The passed ACL did not contain the minimum required information.
    COULD_NOT_INTERPRET = 552,
    /// The number of active profiling objects is at the maximum and no more may be started.
    PROFILING_AT_LIMIT = 553,
    /// Used to indicate that an operation cannot continue without blocking for I/O.
    CANT_WAIT = 554,
    /// Indicates that a thread attempted to terminate itself by default (called NtTerminateThread with NULL) and it was the last thread in the current process.
    CANT_TERMINATE_SELF = 555,
    /// If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter.
    /// In this case information is lost, however, the filter correctly handles the exception.
    UNEXPECTED_MM_CREATE_ERR = 556,
    /// If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter.
    /// In this case information is lost, however, the filter correctly handles the exception.
    UNEXPECTED_MM_MAP_ERROR = 557,
    /// If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter.
    /// In this case information is lost, however, the filter correctly handles the exception.
    UNEXPECTED_MM_EXTEND_ERR = 558,
    /// A malformed function table was encountered during an unwind operation.
    BAD_FUNCTION_TABLE = 559,
    /// Indicates that an attempt was made to assign protection to a file system file or directory and one of the SIDs in the security descriptor could not be translated into a GUID that could be stored by the file system.
    /// This causes the protection attempt to fail, which may cause a file creation attempt to fail.
    NO_GUID_TRANSLATION = 560,
    /// Indicates that an attempt was made to grow an LDT by setting its size, or that the size was not an even number of selectors.
    INVALID_LDT_SIZE = 561,
    /// Indicates that the starting value for the LDT information was not an integral multiple of the selector size.
    INVALID_LDT_OFFSET = 563,
    /// Indicates that the user supplied an invalid descriptor when trying to set up Ldt descriptors.
    INVALID_LDT_DESCRIPTOR = 564,
    /// Indicates a process has too many threads to perform the requested action.
    /// For example, assignment of a primary token may only be performed when a process has zero or one threads.
    TOO_MANY_THREADS = 565,
    /// An attempt was made to operate on a thread within a specific process, but the thread specified is not in the process specified.
    THREAD_NOT_IN_PROCESS = 566,
    /// Page file quota was exceeded.
    PAGEFILE_QUOTA_EXCEEDED = 567,
    /// The Netlogon service cannot start because another Netlogon service running in the domain conflicts with the specified role.
    LOGON_SERVER_CONFLICT = 568,
    /// The SAM database on a Windows Server is significantly out of synchronization with the copy on the Domain Controller. A complete synchronization is required.
    SYNCHRONIZATION_REQUIRED = 569,
    /// The NtCreateFile API failed. This error should never be returned to an application, it is a place holder for the Windows Lan Manager Redirector to use in its internal error mapping routines.
    NET_OPEN_FAILED = 570,
    /// {Privilege Failed} The I/O permissions for the process could not be changed.
    IO_PRIVILEGE_FAILED = 571,
    /// {Application Exit by CTRL+C} The application terminated as a result of a CTRL+C.
    CONTROL_C_EXIT = 572,
    /// {Missing System File} The required system file %hs is bad or missing.
    MISSING_SYSTEMFILE = 573,
    /// {Application Error} The exception %s (0x%08lx) occurred in the application at location 0x%08lx.
    UNHANDLED_EXCEPTION = 574,
    /// {Application Error} The application was unable to start correctly (0x%lx). Click OK to close the application.
    APP_INIT_FAILURE = 575,
    /// {Unable to Create Paging File} The creation of the paging file %hs failed (%lx). The requested size was %ld.
    PAGEFILE_CREATE_FAILED = 576,
    /// Windows cannot verify the digital signature for this file.
    /// A recent hardware or software change might have installed a file that is signed incorrectly or damaged, or that might be malicious software from an unknown source.
    INVALID_IMAGE_HASH = 577,
    /// {No Paging File Specified} No paging file was specified in the system configuration.
    NO_PAGEFILE = 578,
    /// {EXCEPTION} A real-mode application issued a floating-point instruction and floating-point hardware is not present.
    ILLEGAL_FLOAT_CONTEXT = 579,
    /// An event pair synchronization operation was performed using the thread specific client/server event pair object, but no event pair object was associated with the thread.
    NO_EVENT_PAIR = 580,
    /// A Windows Server has an incorrect configuration.
    DOMAIN_CTRLR_CONFIG_ERROR = 581,
    /// An illegal character was encountered.
    /// For a multi-byte character set this includes a lead byte without a succeeding trail byte.
    /// For the Unicode character set this includes the characters 0xFFFF and 0xFFFE.
    ILLEGAL_CHARACTER = 582,
    /// The Unicode character is not defined in the Unicode character set installed on the system.
    UNDEFINED_CHARACTER = 583,
    /// The paging file cannot be created on a floppy diskette.
    FLOPPY_VOLUME = 584,
    /// The system BIOS failed to connect a system interrupt to the device or bus for which the device is connected.
    BIOS_FAILED_TO_CONNECT_INTERRUPT = 585,
    /// This operation is only allowed for the Primary Domain Controller of the domain.
    BACKUP_CONTROLLER = 586,
    /// An attempt was made to acquire a mutant such that its maximum count would have been exceeded.
    MUTANT_LIMIT_EXCEEDED = 587,
    /// A volume has been accessed for which a file system driver is required that has not yet been loaded.
    FS_DRIVER_REQUIRED = 588,
    /// {Registry File Failure} The registry cannot load the hive (file): %hs or its log or alternate. It is corrupt, absent, or not writable.
    CANNOT_LOAD_REGISTRY_FILE = 589,
    /// {Unexpected Failure in DebugActiveProcess} An unexpected failure occurred while processing a DebugActiveProcess API request.
    /// You may choose OK to terminate the process, or Cancel to ignore the error.
    DEBUG_ATTACH_FAILED = 590,
    /// {Fatal System Error} The %hs system process terminated unexpectedly with a status of 0x%08x (0x%08x 0x%08x). The system has been shut down.
    SYSTEM_PROCESS_TERMINATED = 591,
    /// {Data Not Accepted} The TDI client could not handle the data received during an indication.
    DATA_NOT_ACCEPTED = 592,
    /// NTVDM encountered a hard error.
    VDM_HARD_ERROR = 593,
    /// {Cancel Timeout} The driver %hs failed to complete a cancelled I/O request in the allotted time.
    DRIVER_CANCEL_TIMEOUT = 594,
    /// {Reply Message Mismatch} An attempt was made to reply to an LPC message, but the thread specified by the client ID in the message was not waiting on that message.
    REPLY_MESSAGE_MISMATCH = 595,
    /// {Delayed Write Failed} Windows was unable to save all the data for the file %hs. The data has been lost.
    /// This error may be caused by a failure of your computer hardware or network connection. Please try to save this file elsewhere.
    LOST_WRITEBEHIND_DATA = 596,
    /// The parameter(s) passed to the server in the client/server shared memory window were invalid.
    /// Too much data may have been put in the shared memory window.
    CLIENT_SERVER_PARAMETERS_INVALID = 597,
    /// The stream is not a tiny stream.
    NOT_TINY_STREAM = 598,
    /// The request must be handled by the stack overflow code.
    STACK_OVERFLOW_READ = 599,
    /// Internal OFS status codes indicating how an allocation operation is handled.
    /// Either it is retried after the containing onode is moved or the extent stream is converted to a large stream.
    CONVERT_TO_LARGE = 600,
    /// The attempt to find the object found an object matching by ID on the volume but it is out of the scope of the handle used for the operation.
    FOUND_OUT_OF_SCOPE = 601,
    /// The bucket array must be grown. Retry transaction after doing so.
    ALLOCATE_BUCKET = 602,
    /// The user/kernel marshalling buffer has overflowed.
    MARSHALL_OVERFLOW = 603,
    /// The supplied variant structure contains invalid data.
    INVALID_VARIANT = 604,
    /// The specified buffer contains ill-formed data.
    BAD_COMPRESSION_BUFFER = 605,
    /// {Audit Failed} An attempt to generate a security audit failed.
    AUDIT_FAILED = 606,
    /// The timer resolution was not previously set by the current process.
    TIMER_RESOLUTION_NOT_SET = 607,
    /// There is insufficient account information to log you on.
    INSUFFICIENT_LOGON_INFO = 608,
    /// {Invalid DLL Entrypoint} The dynamic link library %hs is not written correctly.
    /// The stack pointer has been left in an inconsistent state.
    /// The entrypoint should be declared as WINAPI or STDCALL.
    /// Select YES to fail the DLL load. Select NO to continue execution.
    /// Selecting NO may cause the application to operate incorrectly.
    BAD_DLL_ENTRYPOINT = 609,
    /// {Invalid Service Callback Entrypoint} The %hs service is not written correctly.
    /// The stack pointer has been left in an inconsistent state.
    /// The callback entrypoint should be declared as WINAPI or STDCALL.
    /// Selecting OK will cause the service to continue operation.
    /// However, the service process may operate incorrectly.
    BAD_SERVICE_ENTRYPOINT = 610,
    /// There is an IP address conflict with another system on the network.
    IP_ADDRESS_CONFLICT1 = 611,
    /// There is an IP address conflict with another system on the network.
    IP_ADDRESS_CONFLICT2 = 612,
    /// {Low On Registry Space} The system has reached the maximum size allowed for the system part of the registry. Additional storage requests will be ignored.
    REGISTRY_QUOTA_LIMIT = 613,
    /// A callback return system service cannot be executed when no callback is active.
    NO_CALLBACK_ACTIVE = 614,
    /// The password provided is too short to meet the policy of your user account. Please choose a longer password.
    PWD_TOO_SHORT = 615,
    /// The policy of your user account does not allow you to change passwords too frequently.
    /// This is done to prevent users from changing back to a familiar, but potentially discovered, password.
    /// If you feel your password has been compromised then please contact your administrator immediately to have a new one assigned.
    PWD_TOO_RECENT = 616,
    /// You have attempted to change your password to one that you have used in the past.
    /// The policy of your user account does not allow this.
    /// Please select a password that you have not previously used.
    PWD_HISTORY_CONFLICT = 617,
    /// The specified compression format is unsupported.
    UNSUPPORTED_COMPRESSION = 618,
    /// The specified hardware profile configuration is invalid.
    INVALID_HW_PROFILE = 619,
    /// The specified Plug and Play registry device path is invalid.
    INVALID_PLUGPLAY_DEVICE_PATH = 620,
    /// The specified quota list is internally inconsistent with its descriptor.
    QUOTA_LIST_INCONSISTENT = 621,
    /// {Windows Evaluation Notification} The evaluation period for this installation of Windows has expired. This system will shutdown in 1 hour.
    /// To restore access to this installation of Windows, please upgrade this installation using a licensed distribution of this product.
    EVALUATION_EXPIRATION = 622,
    /// {Illegal System DLL Relocation} The system DLL %hs was relocated in memory. The application will not run properly.
    /// The relocation occurred because the DLL %hs occupied an address range reserved for Windows system DLLs.
    /// The vendor supplying the DLL should be contacted for a new DLL.
    ILLEGAL_DLL_RELOCATION = 623,
    /// {DLL Initialization Failed} The application failed to initialize because the window station is shutting down.
    DLL_INIT_FAILED_LOGOFF = 624,
    /// The validation process needs to continue on to the next step.
    VALIDATE_CONTINUE = 625,
    /// There are no more matches for the current index enumeration.
    NO_MORE_MATCHES = 626,
    /// The range could not be added to the range list because of a conflict.
    RANGE_LIST_CONFLICT = 627,
    /// The server process is running under a SID different than that required by client.
    SERVER_SID_MISMATCH = 628,
    /// A group marked use for deny only cannot be enabled.
    CANT_ENABLE_DENY_ONLY = 629,
    /// {EXCEPTION} Multiple floating point faults.
    FLOAT_MULTIPLE_FAULTS = 630,
    /// {EXCEPTION} Multiple floating point traps.
    FLOAT_MULTIPLE_TRAPS = 631,
    /// The requested interface is not supported.
    NOINTERFACE = 632,
    /// {System Standby Failed} The driver %hs does not support standby mode.
    /// Updating this driver may allow the system to go to standby mode.
    DRIVER_FAILED_SLEEP = 633,
    /// The system file %1 has become corrupt and has been replaced.
    CORRUPT_SYSTEM_FILE = 634,
    /// {Virtual Memory Minimum Too Low} Your system is low on virtual memory.
    /// Windows is increasing the size of your virtual memory paging file.
    /// During this process, memory requests for some applications may be denied. For more information, see Help.
    COMMITMENT_MINIMUM = 635,
    /// A device was removed so enumeration must be restarted.
    PNP_RESTART_ENUMERATION = 636,
    /// {Fatal System Error} The system image %s is not properly signed.
    /// The file has been replaced with the signed file. The system has been shut down.
    SYSTEM_IMAGE_BAD_SIGNATURE = 637,
    /// Device will not start without a reboot.
    PNP_REBOOT_REQUIRED = 638,
    /// There is not enough power to complete the requested operation.
    INSUFFICIENT_POWER = 639,
    /// ERROR_MULTIPLE_FAULT_VIOLATION
    MULTIPLE_FAULT_VIOLATION = 640,
    /// The system is in the process of shutting down.
    SYSTEM_SHUTDOWN = 641,
    /// An attempt to remove a processes DebugPort was made, but a port was not already associated with the process.
    PORT_NOT_SET = 642,
    /// This version of Windows is not compatible with the behavior version of directory forest, domain or domain controller.
    DS_VERSION_CHECK_FAILURE = 643,
    /// The specified range could not be found in the range list.
    RANGE_NOT_FOUND = 644,
    /// The driver was not loaded because the system is booting into safe mode.
    NOT_SAFE_MODE_DRIVER = 646,
    /// The driver was not loaded because it failed its initialization call.
    FAILED_DRIVER_ENTRY = 647,
    /// The "%hs" encountered an error while applying power or reading the device configuration.
    /// This may be caused by a failure of your hardware or by a poor connection.
    DEVICE_ENUMERATION_ERROR = 648,
    /// The create operation failed because the name contained at least one mount point which resolves to a volume to which the specified device object is not attached.
    MOUNT_POINT_NOT_RESOLVED = 649,
    /// The device object parameter is either not a valid device object or is not attached to the volume specified by the file name.
    INVALID_DEVICE_OBJECT_PARAMETER = 650,
    /// A Machine Check Error has occurred.
    /// Please check the system eventlog for additional information.
    MCA_OCCURED = 651,
    /// There was error [%2] processing the driver database.
    DRIVER_DATABASE_ERROR = 652,
    /// System hive size has exceeded its limit.
    SYSTEM_HIVE_TOO_LARGE = 653,
    /// The driver could not be loaded because a previous version of the driver is still in memory.
    DRIVER_FAILED_PRIOR_UNLOAD = 654,
    /// {Volume Shadow Copy Service} Please wait while the Volume Shadow Copy Service prepares volume %hs for hibernation.
    VOLSNAP_PREPARE_HIBERNATE = 655,
    /// The system has failed to hibernate (The error code is %hs).
    /// Hibernation will be disabled until the system is restarted.
    HIBERNATION_FAILURE = 656,
    /// The password provided is too long to meet the policy of your user account. Please choose a shorter password.
    PWD_TOO_LONG = 657,
    /// The requested operation could not be completed due to a file system limitation.
    FILE_SYSTEM_LIMITATION = 665,
    /// An assertion failure has occurred.
    ASSERTION_FAILURE = 668,
    /// An error occurred in the ACPI subsystem.
    ACPI_ERROR = 669,
    /// WOW Assertion Error.
    WOW_ASSERTION = 670,
    /// A device is missing in the system BIOS MPS table. This device will not be used.
    /// Please contact your system vendor for system BIOS update.
    PNP_BAD_MPS_TABLE = 671,
    /// A translator failed to translate resources.
    PNP_TRANSLATION_FAILED = 672,
    /// A IRQ translator failed to translate resources.
    PNP_IRQ_TRANSLATION_FAILED = 673,
    /// Driver %2 returned invalid ID for a child device (%3).
    PNP_INVALID_ID = 674,
    /// {Kernel Debugger Awakened} the system debugger was awakened by an interrupt.
    WAKE_SYSTEM_DEBUGGER = 675,
    /// {Handles Closed} Handles to objects have been automatically closed as a result of the requested operation.
    HANDLES_CLOSED = 676,
    /// {Too Much Information} The specified access control list (ACL) contained more information than was expected.
    EXTRANEOUS_INFORMATION = 677,
    /// This warning level status indicates that the transaction state already exists for the registry sub-tree, but that a transaction commit was previously aborted.
    /// The commit has NOT been completed, but has not been rolled back either (so it may still be committed if desired).
    RXACT_COMMIT_NECESSARY = 678,
    /// {Media Changed} The media may have changed.
    MEDIA_CHECK = 679,
    /// {GUID Substitution} During the translation of a global identifier (GUID) to a Windows security ID (SID), no administratively-defined GUID prefix was found.
    /// A substitute prefix was used, which will not compromise system security.
    /// However, this may provide a more restrictive access than intended.
    GUID_SUBSTITUTION_MADE = 680,
    /// The create operation stopped after reaching a symbolic link.
    STOPPED_ON_SYMLINK = 681,
    /// A long jump has been executed.
    LONGJUMP = 682,
    /// The Plug and Play query operation was not successful.
    PLUGPLAY_QUERY_VETOED = 683,
    /// A frame consolidation has been executed.
    UNWIND_CONSOLIDATE = 684,
    /// {Registry Hive Recovered} Registry hive (file): %hs was corrupted and it has been recovered. Some data might have been lost.
    REGISTRY_HIVE_RECOVERED = 685,
    /// The application is attempting to run executable code from the module %hs. This may be insecure.
    /// An alternative, %hs, is available. Should the application use the secure module %hs?
    DLL_MIGHT_BE_INSECURE = 686,
    /// The application is loading executable code from the module %hs.
    /// This is secure, but may be incompatible with previous releases of the operating system.
    /// An alternative, %hs, is available. Should the application use the secure module %hs?
    DLL_MIGHT_BE_INCOMPATIBLE = 687,
    /// Debugger did not handle the exception.
    DBG_EXCEPTION_NOT_HANDLED = 688,
    /// Debugger will reply later.
    DBG_REPLY_LATER = 689,
    /// Debugger cannot provide handle.
    DBG_UNABLE_TO_PROVIDE_HANDLE = 690,
    /// Debugger terminated thread.
    DBG_TERMINATE_THREAD = 691,
    /// Debugger terminated process.
    DBG_TERMINATE_PROCESS = 692,
    /// Debugger got control C.
    DBG_CONTROL_C = 693,
    /// Debugger printed exception on control C.
    DBG_PRINTEXCEPTION_C = 694,
    /// Debugger received RIP exception.
    DBG_RIPEXCEPTION = 695,
    /// Debugger received control break.
    DBG_CONTROL_BREAK = 696,
    /// Debugger command communication exception.
    DBG_COMMAND_EXCEPTION = 697,
    /// {Object Exists} An attempt was made to create an object and the object name already existed.
    OBJECT_NAME_EXISTS = 698,
    /// {Thread Suspended} A thread termination occurred while the thread was suspended.
    /// The thread was resumed, and termination proceeded.
    THREAD_WAS_SUSPENDED = 699,
    /// {Image Relocated} An image file could not be mapped at the address specified in the image file. Local fixups must be performed on this image.
    IMAGE_NOT_AT_BASE = 700,
    /// This informational level status indicates that a specified registry sub-tree transaction state did not yet exist and had to be created.
    RXACT_STATE_CREATED = 701,
    /// {Segment Load} A virtual DOS machine (VDM) is loading, unloading, or moving an MS-DOS or Win16 program segment image.
    /// An exception is raised so a debugger can load, unload or track symbols and breakpoints within these 16-bit segments.
    SEGMENT_NOTIFICATION = 702,
    /// {Invalid Current Directory} The process cannot switch to the startup current directory %hs.
    /// Select OK to set current directory to %hs, or select CANCEL to exit.
    BAD_CURRENT_DIRECTORY = 703,
    /// {Redundant Read} To satisfy a read request, the NT fault-tolerant file system successfully read the requested data from a redundant copy.
    /// This was done because the file system encountered a failure on a member of the fault-tolerant volume, but was unable to reassign the failing area of the device.
    FT_READ_RECOVERY_FROM_BACKUP = 704,
    /// {Redundant Write} To satisfy a write request, the NT fault-tolerant file system successfully wrote a redundant copy of the information.
    /// This was done because the file system encountered a failure on a member of the fault-tolerant volume, but was not able to reassign the failing area of the device.
    FT_WRITE_RECOVERY = 705,
    /// {Machine Type Mismatch} The image file %hs is valid, but is for a machine type other than the current machine.
    /// Select OK to continue, or CANCEL to fail the DLL load.
    IMAGE_MACHINE_TYPE_MISMATCH = 706,
    /// {Partial Data Received} The network transport returned partial data to its client. The remaining data will be sent later.
    RECEIVE_PARTIAL = 707,
    /// {Expedited Data Received} The network transport returned data to its client that was marked as expedited by the remote system.
    RECEIVE_EXPEDITED = 708,
    /// {Partial Expedited Data Received} The network transport returned partial data to its client and this data was marked as expedited by the remote system. The remaining data will be sent later.
    RECEIVE_PARTIAL_EXPEDITED = 709,
    /// {TDI Event Done} The TDI indication has completed successfully.
    EVENT_DONE = 710,
    /// {TDI Event Pending} The TDI indication has entered the pending state.
    EVENT_PENDING = 711,
    /// Checking file system on %wZ.
    CHECKING_FILE_SYSTEM = 712,
    /// {Fatal Application Exit} %hs.
    FATAL_APP_EXIT = 713,
    /// The specified registry key is referenced by a predefined handle.
    PREDEFINED_HANDLE = 714,
    /// {Page Unlocked} The page protection of a locked page was changed to 'No Access' and the page was unlocked from memory and from the process.
    WAS_UNLOCKED = 715,
    /// %hs
    SERVICE_NOTIFICATION = 716,
    /// {Page Locked} One of the pages to lock was already locked.
    WAS_LOCKED = 717,
    /// Application popup: %1 : %2
    LOG_HARD_ERROR = 718,
    /// ERROR_ALREADY_WIN32
    ALREADY_WIN32 = 719,
    /// {Machine Type Mismatch} The image file %hs is valid, but is for a machine type other than the current machine.
    IMAGE_MACHINE_TYPE_MISMATCH_EXE = 720,
    /// A yield execution was performed and no thread was available to run.
    NO_YIELD_PERFORMED = 721,
    /// The resumable flag to a timer API was ignored.
    TIMER_RESUME_IGNORED = 722,
    /// The arbiter has deferred arbitration of these resources to its parent.
    ARBITRATION_UNHANDLED = 723,
    /// The inserted CardBus device cannot be started because of a configuration error on "%hs".
    CARDBUS_NOT_SUPPORTED = 724,
    /// The CPUs in this multiprocessor system are not all the same revision level.
    /// To use all processors the operating system restricts itself to the features of the least capable processor in the system.
    /// Should problems occur with this system, contact the CPU manufacturer to see if this mix of processors is supported.
    MP_PROCESSOR_MISMATCH = 725,
    /// The system was put into hibernation.
    HIBERNATED = 726,
    /// The system was resumed from hibernation.
    RESUME_HIBERNATION = 727,
    /// Windows has detected that the system firmware (BIOS) was updated [previous firmware date = %2, current firmware date %3].
    FIRMWARE_UPDATED = 728,
    /// A device driver is leaking locked I/O pages causing system degradation.
    /// The system has automatically enabled tracking code in order to try and catch the culprit.
    DRIVERS_LEAKING_LOCKED_PAGES = 729,
    /// The system has awoken.
    WAKE_SYSTEM = 730,
    /// ERROR_WAIT_1
    WAIT_1 = 731,
    /// ERROR_WAIT_2
    WAIT_2 = 732,
    /// ERROR_WAIT_3
    WAIT_3 = 733,
    /// ERROR_WAIT_63
    WAIT_63 = 734,
    /// ERROR_ABANDONED_WAIT_0
    ABANDONED_WAIT_0 = 735,
    /// ERROR_ABANDONED_WAIT_63
    ABANDONED_WAIT_63 = 736,
    /// ERROR_USER_APC
    USER_APC = 737,
    /// ERROR_KERNEL_APC
    KERNEL_APC = 738,
    /// ERROR_ALERTED
    ALERTED = 739,
    /// The requested operation requires elevation.
    ELEVATION_REQUIRED = 740,
    /// A reparse should be performed by the Object Manager since the name of the file resulted in a symbolic link.
    REPARSE = 741,
    /// An open/create operation completed while an oplock break is underway.
    OPLOCK_BREAK_IN_PROGRESS = 742,
    /// A new volume has been mounted by a file system.
    VOLUME_MOUNTED = 743,
    /// This success level status indicates that the transaction state already exists for the registry sub-tree, but that a transaction commit was previously aborted. The commit has now been completed.
    RXACT_COMMITTED = 744,
    /// This indicates that a notify change request has been completed due to closing the handle which made the notify change request.
    NOTIFY_CLEANUP = 745,
    /// {Connect Failure on Primary Transport} An attempt was made to connect to the remote server %hs on the primary transport, but the connection failed.
    /// The computer WAS able to connect on a secondary transport.
    PRIMARY_TRANSPORT_CONNECT_FAILED = 746,
    /// Page fault was a transition fault.
    PAGE_FAULT_TRANSITION = 747,
    /// Page fault was a demand zero fault.
    PAGE_FAULT_DEMAND_ZERO = 748,
    /// Page fault was a demand zero fault.
    PAGE_FAULT_COPY_ON_WRITE = 749,
    /// Page fault was a demand zero fault.
    PAGE_FAULT_GUARD_PAGE = 750,
    /// Page fault was satisfied by reading from a secondary storage device.
    PAGE_FAULT_PAGING_FILE = 751,
    /// Cached page was locked during operation.
    CACHE_PAGE_LOCKED = 752,
    /// Crash dump exists in paging file.
    CRASH_DUMP = 753,
    /// Specified buffer contains all zeros.
    BUFFER_ALL_ZEROS = 754,
    /// A reparse should be performed by the Object Manager since the name of the file resulted in a symbolic link.
    REPARSE_OBJECT = 755,
    /// The device has succeeded a query-stop and its resource requirements have changed.
    RESOURCE_REQUIREMENTS_CHANGED = 756,
    /// The translator has translated these resources into the global space and no further translations should be performed.
    TRANSLATION_COMPLETE = 757,
    /// A process being terminated has no threads to terminate.
    NOTHING_TO_TERMINATE = 758,
    /// The specified process is not part of a job.
    PROCESS_NOT_IN_JOB = 759,
    /// The specified process is part of a job.
    PROCESS_IN_JOB = 760,
    /// {Volume Shadow Copy Service} The system is now ready for hibernation.
    VOLSNAP_HIBERNATE_READY = 761,
    /// A file system or file system filter driver has successfully completed an FsFilter operation.
    FSFILTER_OP_COMPLETED_SUCCESSFULLY = 762,
    /// The specified interrupt vector was already connected.
    INTERRUPT_VECTOR_ALREADY_CONNECTED = 763,
    /// The specified interrupt vector is still connected.
    INTERRUPT_STILL_CONNECTED = 764,
    /// An operation is blocked waiting for an oplock.
    WAIT_FOR_OPLOCK = 765,
    /// Debugger handled exception.
    DBG_EXCEPTION_HANDLED = 766,
    /// Debugger continued.
    DBG_CONTINUE = 767,
    /// An exception occurred in a user mode callback and the kernel callback frame should be removed.
    CALLBACK_POP_STACK = 768,
    /// Compression is disabled for this volume.
    COMPRESSION_DISABLED = 769,
    /// The data provider cannot fetch backwards through a result set.
    CANTFETCHBACKWARDS = 770,
    /// The data provider cannot scroll backwards through a result set.
    CANTSCROLLBACKWARDS = 771,
    /// The data provider requires that previously fetched data is released before asking for more data.
    ROWSNOTRELEASED = 772,
    /// The data provider was not able to interpret the flags set for a column binding in an accessor.
    BAD_ACCESSOR_FLAGS = 773,
    /// One or more errors occurred while processing the request.
    ERRORS_ENCOUNTERED = 774,
    /// The implementation is not capable of performing the request.
    NOT_CAPABLE = 775,
    /// The client of a component requested an operation which is not valid given the state of the component instance.
    REQUEST_OUT_OF_SEQUENCE = 776,
    /// A version number could not be parsed.
    VERSION_PARSE_ERROR = 777,
    /// The iterator's start position is invalid.
    BADSTARTPOSITION = 778,
    /// The hardware has reported an uncorrectable memory error.
    MEMORY_HARDWARE = 779,
    /// The attempted operation required self healing to be enabled.
    DISK_REPAIR_DISABLED = 780,
    /// The Desktop heap encountered an error while allocating session memory.
    /// There is more information in the system event log.
    INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE = 781,
    /// The system power state is transitioning from %2 to %3.
    SYSTEM_POWERSTATE_TRANSITION = 782,
    /// The system power state is transitioning from %2 to %3 but could enter %4.
    SYSTEM_POWERSTATE_COMPLEX_TRANSITION = 783,
    /// A thread is getting dispatched with MCA EXCEPTION because of MCA.
    MCA_EXCEPTION = 784,
    /// Access to %1 is monitored by policy rule %2.
    ACCESS_AUDIT_BY_POLICY = 785,
    /// Access to %1 has been restricted by your Administrator by policy rule %2.
    ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY = 786,
    /// A valid hibernation file has been invalidated and should be abandoned.
    ABANDON_HIBERFILE = 787,
    /// {Delayed Write Failed} Windows was unable to save all the data for the file %hs; the data has been lost.
    /// This error may be caused by network connectivity issues. Please try to save this file elsewhere.
    LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED = 788,
    /// {Delayed Write Failed} Windows was unable to save all the data for the file %hs; the data has been lost.
    /// This error was returned by the server on which the file exists. Please try to save this file elsewhere.
    LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR = 789,
    /// {Delayed Write Failed} Windows was unable to save all the data for the file %hs; the data has been lost.
    /// This error may be caused if the device has been removed or the media is write-protected.
    LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR = 790,
    /// The resources required for this device conflict with the MCFG table.
    BAD_MCFG_TABLE = 791,
    /// The volume repair could not be performed while it is online.
    /// Please schedule to take the volume offline so that it can be repaired.
    DISK_REPAIR_REDIRECTED = 792,
    /// The volume repair was not successful.
    DISK_REPAIR_UNSUCCESSFUL = 793,
    /// One of the volume corruption logs is full.
    /// Further corruptions that may be detected won't be logged.
    CORRUPT_LOG_OVERFULL = 794,
    /// One of the volume corruption logs is internally corrupted and needs to be recreated.
    /// The volume may contain undetected corruptions and must be scanned.
    CORRUPT_LOG_CORRUPTED = 795,
    /// One of the volume corruption logs is unavailable for being operated on.
    CORRUPT_LOG_UNAVAILABLE = 796,
    /// One of the volume corruption logs was deleted while still having corruption records in them.
    /// The volume contains detected corruptions and must be scanned.
    CORRUPT_LOG_DELETED_FULL = 797,
    /// One of the volume corruption logs was cleared by chkdsk and no longer contains real corruptions.
    CORRUPT_LOG_CLEARED = 798,
    /// Orphaned files exist on the volume but could not be recovered because no more new names could be created in the recovery directory. Files must be moved from the recovery directory.
    ORPHAN_NAME_EXHAUSTED = 799,
    /// The oplock that was associated with this handle is now associated with a different handle.
    OPLOCK_SWITCHED_TO_NEW_HANDLE = 800,
    /// An oplock of the requested level cannot be granted. An oplock of a lower level may be available.
    CANNOT_GRANT_REQUESTED_OPLOCK = 801,
    /// The operation did not complete successfully because it would cause an oplock to be broken.
    /// The caller has requested that existing oplocks not be broken.
    CANNOT_BREAK_OPLOCK = 802,
    /// The handle with which this oplock was associated has been closed. The oplock is now broken.
    OPLOCK_HANDLE_CLOSED = 803,
    /// The specified access control entry (ACE) does not contain a condition.
    NO_ACE_CONDITION = 804,
    /// The specified access control entry (ACE) contains an invalid condition.
    INVALID_ACE_CONDITION = 805,
    /// Access to the specified file handle has been revoked.
    FILE_HANDLE_REVOKED = 806,
    /// An image file was mapped at a different address from the one specified in the image file but fixups will still be automatically performed on the image.
    IMAGE_AT_DIFFERENT_BASE = 807,
    /// Access to the extended attribute was denied.
    EA_ACCESS_DENIED = 994,
    /// The I/O operation has been aborted because of either a thread exit or an application request.
    OPERATION_ABORTED = 995,
    /// Overlapped I/O event is not in a signaled state.
    IO_INCOMPLETE = 996,
    /// Overlapped I/O operation is in progress.
    IO_PENDING = 997,
    /// Invalid access to memory location.
    NOACCESS = 998,
    /// Error performing inpage operation.
    SWAPERROR = 999,
    /// Recursion too deep; the stack overflowed.
    STACK_OVERFLOW = 1001,
    /// The window cannot act on the sent message.
    INVALID_MESSAGE = 1002,
    /// Cannot complete this function.
    CAN_NOT_COMPLETE = 1003,
    /// Invalid flags.
    INVALID_FLAGS = 1004,
    /// The volume does not contain a recognized file system.
    /// Please make sure that all required file system drivers are loaded and that the volume is not corrupted.
    UNRECOGNIZED_VOLUME = 1005,
    /// The volume for a file has been externally altered so that the opened file is no longer valid.
    FILE_INVALID = 1006,
    /// The requested operation cannot be performed in full-screen mode.
    FULLSCREEN_MODE = 1007,
    /// An attempt was made to reference a token that does not exist.
    NO_TOKEN = 1008,
    /// The configuration registry database is corrupt.
    BADDB = 1009,
    /// The configuration registry key is invalid.
    BADKEY = 1010,
    /// The configuration registry key could not be opened.
    CANTOPEN = 1011,
    /// The configuration registry key could not be read.
    CANTREAD = 1012,
    /// The configuration registry key could not be written.
    CANTWRITE = 1013,
    /// One of the files in the registry database had to be recovered by use of a log or alternate copy. The recovery was successful.
    REGISTRY_RECOVERED = 1014,
    /// The registry is corrupted. The structure of one of the files containing registry data is corrupted, or the system's memory image of the file is corrupted, or the file could not be recovered because the alternate copy or log was absent or corrupted.
    REGISTRY_CORRUPT = 1015,
    /// An I/O operation initiated by the registry failed unrecoverably.
    /// The registry could not read in, or write out, or flush, one of the files that contain the system's image of the registry.
    REGISTRY_IO_FAILED = 1016,
    /// The system has attempted to load or restore a file into the registry, but the specified file is not in a registry file format.
    NOT_REGISTRY_FILE = 1017,
    /// Illegal operation attempted on a registry key that has been marked for deletion.
    KEY_DELETED = 1018,
    /// System could not allocate the required space in a registry log.
    NO_LOG_SPACE = 1019,
    /// Cannot create a symbolic link in a registry key that already has subkeys or values.
    KEY_HAS_CHILDREN = 1020,
    /// Cannot create a stable subkey under a volatile parent key.
    CHILD_MUST_BE_VOLATILE = 1021,
    /// A notify change request is being completed and the information is not being returned in the caller's buffer.
    /// The caller now needs to enumerate the files to find the changes.
    NOTIFY_ENUM_DIR = 1022,
    /// A stop control has been sent to a service that other running services are dependent on.
    DEPENDENT_SERVICES_RUNNING = 1051,
    /// The requested control is not valid for this service.
    INVALID_SERVICE_CONTROL = 1052,
    /// The service did not respond to the start or control request in a timely fashion.
    SERVICE_REQUEST_TIMEOUT = 1053,
    /// A thread could not be created for the service.
    SERVICE_NO_THREAD = 1054,
    /// The service database is locked.
    SERVICE_DATABASE_LOCKED = 1055,
    /// An instance of the service is already running.
    SERVICE_ALREADY_RUNNING = 1056,
    /// The account name is invalid or does not exist, or the password is invalid for the account name specified.
    INVALID_SERVICE_ACCOUNT = 1057,
    /// The service cannot be started, either because it is disabled or because it has no enabled devices associated with it.
    SERVICE_DISABLED = 1058,
    /// Circular service dependency was specified.
    CIRCULAR_DEPENDENCY = 1059,
    /// The specified service does not exist as an installed service.
    SERVICE_DOES_NOT_EXIST = 1060,
    /// The service cannot accept control messages at this time.
    SERVICE_CANNOT_ACCEPT_CTRL = 1061,
    /// The service has not been started.
    SERVICE_NOT_ACTIVE = 1062,
    /// The service process could not connect to the service controller.
    FAILED_SERVICE_CONTROLLER_CONNECT = 1063,
    /// An exception occurred in the service when handling the control request.
    EXCEPTION_IN_SERVICE = 1064,
    /// The database specified does not exist.
    DATABASE_DOES_NOT_EXIST = 1065,
    /// The service has returned a service-specific error code.
    SERVICE_SPECIFIC_ERROR = 1066,
    /// The process terminated unexpectedly.
    PROCESS_ABORTED = 1067,
    /// The dependency service or group failed to start.
    SERVICE_DEPENDENCY_FAIL = 1068,
    /// The service did not start due to a logon failure.
    SERVICE_LOGON_FAILED = 1069,
    /// After starting, the service hung in a start-pending state.
    SERVICE_START_HANG = 1070,
    /// The specified service database lock is invalid.
    INVALID_SERVICE_LOCK = 1071,
    /// The specified service has been marked for deletion.
    SERVICE_MARKED_FOR_DELETE = 1072,
    /// The specified service already exists.
    SERVICE_EXISTS = 1073,
    /// The system is currently running with the last-known-good configuration.
    ALREADY_RUNNING_LKG = 1074,
    /// The dependency service does not exist or has been marked for deletion.
    SERVICE_DEPENDENCY_DELETED = 1075,
    /// The current boot has already been accepted for use as the last-known-good control set.
    BOOT_ALREADY_ACCEPTED = 1076,
    /// No attempts to start the service have been made since the last boot.
    SERVICE_NEVER_STARTED = 1077,
    /// The name is already in use as either a service name or a service display name.
    DUPLICATE_SERVICE_NAME = 1078,
    /// The account specified for this service is different from the account specified for other services running in the same process.
    DIFFERENT_SERVICE_ACCOUNT = 1079,
    /// Failure actions can only be set for Win32 services, not for drivers.
    CANNOT_DETECT_DRIVER_FAILURE = 1080,
    /// This service runs in the same process as the service control manager.
    /// Therefore, the service control manager cannot take action if this service's process terminates unexpectedly.
    CANNOT_DETECT_PROCESS_ABORT = 1081,
    /// No recovery program has been configured for this service.
    NO_RECOVERY_PROGRAM = 1082,
    /// The executable program that this service is configured to run in does not implement the service.
    SERVICE_NOT_IN_EXE = 1083,
    /// This service cannot be started in Safe Mode.
    NOT_SAFEBOOT_SERVICE = 1084,
    /// The physical end of the tape has been reached.
    END_OF_MEDIA = 1100,
    /// A tape access reached a filemark.
    FILEMARK_DETECTED = 1101,
    /// The beginning of the tape or a partition was encountered.
    BEGINNING_OF_MEDIA = 1102,
    /// A tape access reached the end of a set of files.
    SETMARK_DETECTED = 1103,
    /// No more data is on the tape.
    NO_DATA_DETECTED = 1104,
    /// Tape could not be partitioned.
    PARTITION_FAILURE = 1105,
    /// When accessing a new tape of a multivolume partition, the current block size is incorrect.
    INVALID_BLOCK_LENGTH = 1106,
    /// Tape partition information could not be found when loading a tape.
    DEVICE_NOT_PARTITIONED = 1107,
    /// Unable to lock the media eject mechanism.
    UNABLE_TO_LOCK_MEDIA = 1108,
    /// Unable to unload the media.
    UNABLE_TO_UNLOAD_MEDIA = 1109,
    /// The media in the drive may have changed.
    MEDIA_CHANGED = 1110,
    /// The I/O bus was reset.
    BUS_RESET = 1111,
    /// No media in drive.
    NO_MEDIA_IN_DRIVE = 1112,
    /// No mapping for the Unicode character exists in the target multi-byte code page.
    NO_UNICODE_TRANSLATION = 1113,
    /// A dynamic link library (DLL) initialization routine failed.
    DLL_INIT_FAILED = 1114,
    /// A system shutdown is in progress.
    SHUTDOWN_IN_PROGRESS = 1115,
    /// Unable to abort the system shutdown because no shutdown was in progress.
    NO_SHUTDOWN_IN_PROGRESS = 1116,
    /// The request could not be performed because of an I/O device error.
    IO_DEVICE = 1117,
    /// No serial device was successfully initialized. The serial driver will unload.
    SERIAL_NO_DEVICE = 1118,
    /// Unable to open a device that was sharing an interrupt request (IRQ) with other devices.
    /// At least one other device that uses that IRQ was already opened.
    IRQ_BUSY = 1119,
    /// A serial I/O operation was completed by another write to the serial port. The IOCTL_SERIAL_XOFF_COUNTER reached zero.)
    MORE_WRITES = 1120,
    /// A serial I/O operation completed because the timeout period expired.
    /// The IOCTL_SERIAL_XOFF_COUNTER did not reach zero.)
    COUNTER_TIMEOUT = 1121,
    /// No ID address mark was found on the floppy disk.
    FLOPPY_ID_MARK_NOT_FOUND = 1122,
    /// Mismatch between the floppy disk sector ID field and the floppy disk controller track address.
    FLOPPY_WRONG_CYLINDER = 1123,
    /// The floppy disk controller reported an error that is not recognized by the floppy disk driver.
    FLOPPY_UNKNOWN_ERROR = 1124,
    /// The floppy disk controller returned inconsistent results in its registers.
    FLOPPY_BAD_REGISTERS = 1125,
    /// While accessing the hard disk, a recalibrate operation failed, even after retries.
    DISK_RECALIBRATE_FAILED = 1126,
    /// While accessing the hard disk, a disk operation failed even after retries.
    DISK_OPERATION_FAILED = 1127,
    /// While accessing the hard disk, a disk controller reset was needed, but even that failed.
    DISK_RESET_FAILED = 1128,
    /// Physical end of tape encountered.
    EOM_OVERFLOW = 1129,
    /// Not enough server storage is available to process this command.
    NOT_ENOUGH_SERVER_MEMORY = 1130,
    /// A potential deadlock condition has been detected.
    POSSIBLE_DEADLOCK = 1131,
    /// The base address or the file offset specified does not have the proper alignment.
    MAPPED_ALIGNMENT = 1132,
    /// An attempt to change the system power state was vetoed by another application or driver.
    SET_POWER_STATE_VETOED = 1140,
    /// The system BIOS failed an attempt to change the system power state.
    SET_POWER_STATE_FAILED = 1141,
    /// An attempt was made to create more links on a file than the file system supports.
    TOO_MANY_LINKS = 1142,
    /// The specified program requires a newer version of Windows.
    OLD_WIN_VERSION = 1150,
    /// The specified program is not a Windows or MS-DOS program.
    APP_WRONG_OS = 1151,
    /// Cannot start more than one instance of the specified program.
    SINGLE_INSTANCE_APP = 1152,
    /// The specified program was written for an earlier version of Windows.
    RMODE_APP = 1153,
    /// One of the library files needed to run this application is damaged.
    INVALID_DLL = 1154,
    /// No application is associated with the specified file for this operation.
    NO_ASSOCIATION = 1155,
    /// An error occurred in sending the command to the application.
    DDE_FAIL = 1156,
    /// One of the library files needed to run this application cannot be found.
    DLL_NOT_FOUND = 1157,
    /// The current process has used all of its system allowance of handles for Window Manager objects.
    NO_MORE_USER_HANDLES = 1158,
    /// The message can be used only with synchronous operations.
    MESSAGE_SYNC_ONLY = 1159,
    /// The indicated source element has no media.
    SOURCE_ELEMENT_EMPTY = 1160,
    /// The indicated destination element already contains media.
    DESTINATION_ELEMENT_FULL = 1161,
    /// The indicated element does not exist.
    ILLEGAL_ELEMENT_ADDRESS = 1162,
    /// The indicated element is part of a magazine that is not present.
    MAGAZINE_NOT_PRESENT = 1163,
    /// The indicated device requires reinitialization due to hardware errors.
    DEVICE_REINITIALIZATION_NEEDED = 1164,
    /// The device has indicated that cleaning is required before further operations are attempted.
    DEVICE_REQUIRES_CLEANING = 1165,
    /// The device has indicated that its door is open.
    DEVICE_DOOR_OPEN = 1166,
    /// The device is not connected.
    DEVICE_NOT_CONNECTED = 1167,
    /// Element not found.
    NOT_FOUND = 1168,
    /// There was no match for the specified key in the index.
    NO_MATCH = 1169,
    /// The property set specified does not exist on the object.
    SET_NOT_FOUND = 1170,
    /// The point passed to GetMouseMovePoints is not in the buffer.
    POINT_NOT_FOUND = 1171,
    /// The tracking (workstation) service is not running.
    NO_TRACKING_SERVICE = 1172,
    /// The Volume ID could not be found.
    NO_VOLUME_ID = 1173,
    /// Unable to remove the file to be replaced.
    UNABLE_TO_REMOVE_REPLACED = 1175,
    /// Unable to move the replacement file to the file to be replaced.
    /// The file to be replaced has retained its original name.
    UNABLE_TO_MOVE_REPLACEMENT = 1176,
    /// Unable to move the replacement file to the file to be replaced.
    /// The file to be replaced has been renamed using the backup name.
    UNABLE_TO_MOVE_REPLACEMENT_2 = 1177,
    /// The volume change journal is being deleted.
    JOURNAL_DELETE_IN_PROGRESS = 1178,
    /// The volume change journal is not active.
    JOURNAL_NOT_ACTIVE = 1179,
    /// A file was found, but it may not be the correct file.
    POTENTIAL_FILE_FOUND = 1180,
    /// The journal entry has been deleted from the journal.
    JOURNAL_ENTRY_DELETED = 1181,
    /// A system shutdown has already been scheduled.
    SHUTDOWN_IS_SCHEDULED = 1190,
    /// The system shutdown cannot be initiated because there are other users logged on to the computer.
    SHUTDOWN_USERS_LOGGED_ON = 1191,
    /// The specified device name is invalid.
    BAD_DEVICE = 1200,
    /// The device is not currently connected but it is a remembered connection.
    CONNECTION_UNAVAIL = 1201,
    /// The local device name has a remembered connection to another network resource.
    DEVICE_ALREADY_REMEMBERED = 1202,
    /// The network path was either typed incorrectly, does not exist, or the network provider is not currently available.
    /// Please try retyping the path or contact your network administrator.
    NO_NET_OR_BAD_PATH = 1203,
    /// The specified network provider name is invalid.
    BAD_PROVIDER = 1204,
    /// Unable to open the network connection profile.
    CANNOT_OPEN_PROFILE = 1205,
    /// The network connection profile is corrupted.
    BAD_PROFILE = 1206,
    /// Cannot enumerate a noncontainer.
    NOT_CONTAINER = 1207,
    /// An extended error has occurred.
    EXTENDED_ERROR = 1208,
    /// The format of the specified group name is invalid.
    INVALID_GROUPNAME = 1209,
    /// The format of the specified computer name is invalid.
    INVALID_COMPUTERNAME = 1210,
    /// The format of the specified event name is invalid.
    INVALID_EVENTNAME = 1211,
    /// The format of the specified domain name is invalid.
    INVALID_DOMAINNAME = 1212,
    /// The format of the specified service name is invalid.
    INVALID_SERVICENAME = 1213,
    /// The format of the specified network name is invalid.
    INVALID_NETNAME = 1214,
    /// The format of the specified share name is invalid.
    INVALID_SHARENAME = 1215,
    /// The format of the specified password is invalid.
    INVALID_PASSWORDNAME = 1216,
    /// The format of the specified message name is invalid.
    INVALID_MESSAGENAME = 1217,
    /// The format of the specified message destination is invalid.
    INVALID_MESSAGEDEST = 1218,
    /// Multiple connections to a server or shared resource by the same user, using more than one user name, are not allowed.
    /// Disconnect all previous connections to the server or shared resource and try again.
    SESSION_CREDENTIAL_CONFLICT = 1219,
    /// An attempt was made to establish a session to a network server, but there are already too many sessions established to that server.
    REMOTE_SESSION_LIMIT_EXCEEDED = 1220,
    /// The workgroup or domain name is already in use by another computer on the network.
    DUP_DOMAINNAME = 1221,
    /// The network is not present or not started.
    NO_NETWORK = 1222,
    /// The operation was canceled by the user.
    CANCELLED = 1223,
    /// The requested operation cannot be performed on a file with a user-mapped section open.
    USER_MAPPED_FILE = 1224,
    /// The remote computer refused the network connection.
    CONNECTION_REFUSED = 1225,
    /// The network connection was gracefully closed.
    GRACEFUL_DISCONNECT = 1226,
    /// The network transport endpoint already has an address associated with it.
    ADDRESS_ALREADY_ASSOCIATED = 1227,
    /// An address has not yet been associated with the network endpoint.
    ADDRESS_NOT_ASSOCIATED = 1228,
    /// An operation was attempted on a nonexistent network connection.
    CONNECTION_INVALID = 1229,
    /// An invalid operation was attempted on an active network connection.
    CONNECTION_ACTIVE = 1230,
    /// The network location cannot be reached.
    /// For information about network troubleshooting, see Windows Help.
    NETWORK_UNREACHABLE = 1231,
    /// The network location cannot be reached.
    /// For information about network troubleshooting, see Windows Help.
    HOST_UNREACHABLE = 1232,
    /// The network location cannot be reached.
    /// For information about network troubleshooting, see Windows Help.
    PROTOCOL_UNREACHABLE = 1233,
    /// No service is operating at the destination network endpoint on the remote system.
    PORT_UNREACHABLE = 1234,
    /// The request was aborted.
    REQUEST_ABORTED = 1235,
    /// The network connection was aborted by the local system.
    CONNECTION_ABORTED = 1236,
    /// The operation could not be completed. A retry should be performed.
    RETRY = 1237,
    /// A connection to the server could not be made because the limit on the number of concurrent connections for this account has been reached.
    CONNECTION_COUNT_LIMIT = 1238,
    /// Attempting to log in during an unauthorized time of day for this account.
    LOGIN_TIME_RESTRICTION = 1239,
    /// The account is not authorized to log in from this station.
    LOGIN_WKSTA_RESTRICTION = 1240,
    /// The network address could not be used for the operation requested.
    INCORRECT_ADDRESS = 1241,
    /// The service is already registered.
    ALREADY_REGISTERED = 1242,
    /// The specified service does not exist.
    SERVICE_NOT_FOUND = 1243,
    /// The operation being requested was not performed because the user has not been authenticated.
    NOT_AUTHENTICATED = 1244,
    /// The operation being requested was not performed because the user has not logged on to the network. The specified service does not exist.
    NOT_LOGGED_ON = 1245,
    /// Continue with work in progress.
    CONTINUE = 1246,
    /// An attempt was made to perform an initialization operation when initialization has already been completed.
    ALREADY_INITIALIZED = 1247,
    /// No more local devices.
    NO_MORE_DEVICES = 1248,
    /// The specified site does not exist.
    NO_SUCH_SITE = 1249,
    /// A domain controller with the specified name already exists.
    DOMAIN_CONTROLLER_EXISTS = 1250,
    /// This operation is supported only when you are connected to the server.
    ONLY_IF_CONNECTED = 1251,
    /// The group policy framework should call the extension even if there are no changes.
    OVERRIDE_NOCHANGES = 1252,
    /// The specified user does not have a valid profile.
    BAD_USER_PROFILE = 1253,
    /// This operation is not supported on a computer running Windows Server 2003 for Small Business Server.
    NOT_SUPPORTED_ON_SBS = 1254,
    /// The server machine is shutting down.
    SERVER_SHUTDOWN_IN_PROGRESS = 1255,
    /// The remote system is not available.
    /// For information about network troubleshooting, see Windows Help.
    HOST_DOWN = 1256,
    /// The security identifier provided is not from an account domain.
    NON_ACCOUNT_SID = 1257,
    /// The security identifier provided does not have a domain component.
    NON_DOMAIN_SID = 1258,
    /// AppHelp dialog canceled thus preventing the application from starting.
    APPHELP_BLOCK = 1259,
    /// This program is blocked by group policy.
    /// For more information, contact your system administrator.
    ACCESS_DISABLED_BY_POLICY = 1260,
    /// A program attempt to use an invalid register value.
    /// Normally caused by an uninitialized register. This error is Itanium specific.
    REG_NAT_CONSUMPTION = 1261,
    /// The share is currently offline or does not exist.
    CSCSHARE_OFFLINE = 1262,
    /// The Kerberos protocol encountered an error while validating the KDC certificate during smartcard logon.
    /// There is more information in the system event log.
    PKINIT_FAILURE = 1263,
    /// The Kerberos protocol encountered an error while attempting to utilize the smartcard subsystem.
    SMARTCARD_SUBSYSTEM_FAILURE = 1264,
    /// The system cannot contact a domain controller to service the authentication request. Please try again later.
    DOWNGRADE_DETECTED = 1265,
    /// The machine is locked and cannot be shut down without the force option.
    MACHINE_LOCKED = 1271,
    /// An application-defined callback gave invalid data when called.
    CALLBACK_SUPPLIED_INVALID_DATA = 1273,
    /// The group policy framework should call the extension in the synchronous foreground policy refresh.
    SYNC_FOREGROUND_REFRESH_REQUIRED = 1274,
    /// This driver has been blocked from loading.
    DRIVER_BLOCKED = 1275,
    /// A dynamic link library (DLL) referenced a module that was neither a DLL nor the process's executable image.
    INVALID_IMPORT_OF_NON_DLL = 1276,
    /// Windows cannot open this program since it has been disabled.
    ACCESS_DISABLED_WEBBLADE = 1277,
    /// Windows cannot open this program because the license enforcement system has been tampered with or become corrupted.
    ACCESS_DISABLED_WEBBLADE_TAMPER = 1278,
    /// A transaction recover failed.
    RECOVERY_FAILURE = 1279,
    /// The current thread has already been converted to a fiber.
    ALREADY_FIBER = 1280,
    /// The current thread has already been converted from a fiber.
    ALREADY_THREAD = 1281,
    /// The system detected an overrun of a stack-based buffer in this application.
    /// This overrun could potentially allow a malicious user to gain control of this application.
    STACK_BUFFER_OVERRUN = 1282,
    /// Data present in one of the parameters is more than the function can operate on.
    PARAMETER_QUOTA_EXCEEDED = 1283,
    /// An attempt to do an operation on a debug object failed because the object is in the process of being deleted.
    DEBUGGER_INACTIVE = 1284,
    /// An attempt to delay-load a .dll or get a function address in a delay-loaded .dll failed.
    DELAY_LOAD_FAILED = 1285,
    /// %1 is a 16-bit application. You do not have permissions to execute 16-bit applications.
    /// Check your permissions with your system administrator.
    VDM_DISALLOWED = 1286,
    /// Insufficient information exists to identify the cause of failure.
    UNIDENTIFIED_ERROR = 1287,
    /// The parameter passed to a C runtime function is incorrect.
    INVALID_CRUNTIME_PARAMETER = 1288,
    /// The operation occurred beyond the valid data length of the file.
    BEYOND_VDL = 1289,
    /// The service start failed since one or more services in the same process have an incompatible service SID type setting.
    /// A service with restricted service SID type can only coexist in the same process with other services with a restricted SID type.
    /// If the service SID type for this service was just configured, the hosting process must be restarted in order to start this service.
    /// On Windows Server 2003 and Windows XP, an unrestricted service cannot coexist in the same process with other services.
    /// The service with the unrestricted service SID type must be moved to an owned process in order to start this service.
    INCOMPATIBLE_SERVICE_SID_TYPE = 1290,
    /// The process hosting the driver for this device has been terminated.
    DRIVER_PROCESS_TERMINATED = 1291,
    /// An operation attempted to exceed an implementation-defined limit.
    IMPLEMENTATION_LIMIT = 1292,
    /// Either the target process, or the target thread's containing process, is a protected process.
    PROCESS_IS_PROTECTED = 1293,
    /// The service notification client is lagging too far behind the current state of services in the machine.
    SERVICE_NOTIFY_CLIENT_LAGGING = 1294,
    /// The requested file operation failed because the storage quota was exceeded.
    /// To free up disk space, move files to a different location or delete unnecessary files.
    /// For more information, contact your system administrator.
    DISK_QUOTA_EXCEEDED = 1295,
    /// The requested file operation failed because the storage policy blocks that type of file.
    /// For more information, contact your system administrator.
    CONTENT_BLOCKED = 1296,
    /// A privilege that the service requires to function properly does not exist in the service account configuration.
    /// You may use the Services Microsoft Management Console (MMC) snap-in (services.msc) and the Local Security Settings MMC snap-in (secpol.msc) to view the service configuration and the account configuration.
    INCOMPATIBLE_SERVICE_PRIVILEGE = 1297,
    /// A thread involved in this operation appears to be unresponsive.
    APP_HANG = 1298,
    /// Indicates a particular Security ID may not be assigned as the label of an object.
    INVALID_LABEL = 1299,
    /// Not all privileges or groups referenced are assigned to the caller.
    NOT_ALL_ASSIGNED = 1300,
    /// Some mapping between account names and security IDs was not done.
    SOME_NOT_MAPPED = 1301,
    /// No system quota limits are specifically set for this account.
    NO_QUOTAS_FOR_ACCOUNT = 1302,
    /// No encryption key is available. A well-known encryption key was returned.
    LOCAL_USER_SESSION_KEY = 1303,
    /// The password is too complex to be converted to a LAN Manager password.
    /// The LAN Manager password returned is a NULL string.
    NULL_LM_PASSWORD = 1304,
    /// The revision level is unknown.
    UNKNOWN_REVISION = 1305,
    /// Indicates two revision levels are incompatible.
    REVISION_MISMATCH = 1306,
    /// This security ID may not be assigned as the owner of this object.
    INVALID_OWNER = 1307,
    /// This security ID may not be assigned as the primary group of an object.
    INVALID_PRIMARY_GROUP = 1308,
    /// An attempt has been made to operate on an impersonation token by a thread that is not currently impersonating a client.
    NO_IMPERSONATION_TOKEN = 1309,
    /// The group may not be disabled.
    CANT_DISABLE_MANDATORY = 1310,
    /// There are currently no logon servers available to service the logon request.
    NO_LOGON_SERVERS = 1311,
    /// A specified logon session does not exist. It may already have been terminated.
    NO_SUCH_LOGON_SESSION = 1312,
    /// A specified privilege does not exist.
    NO_SUCH_PRIVILEGE = 1313,
    /// A required privilege is not held by the client.
    PRIVILEGE_NOT_HELD = 1314,
    /// The name provided is not a properly formed account name.
    INVALID_ACCOUNT_NAME = 1315,
    /// The specified account already exists.
    USER_EXISTS = 1316,
    /// The specified account does not exist.
    NO_SUCH_USER = 1317,
    /// The specified group already exists.
    GROUP_EXISTS = 1318,
    /// The specified group does not exist.
    NO_SUCH_GROUP = 1319,
    /// Either the specified user account is already a member of the specified group, or the specified group cannot be deleted because it contains a member.
    MEMBER_IN_GROUP = 1320,
    /// The specified user account is not a member of the specified group account.
    MEMBER_NOT_IN_GROUP = 1321,
    /// This operation is disallowed as it could result in an administration account being disabled, deleted or unable to log on.
    LAST_ADMIN = 1322,
    /// Unable to update the password. The value provided as the current password is incorrect.
    WRONG_PASSWORD = 1323,
    /// Unable to update the password. The value provided for the new password contains values that are not allowed in passwords.
    ILL_FORMED_PASSWORD = 1324,
    /// Unable to update the password. The value provided for the new password does not meet the length, complexity, or history requirements of the domain.
    PASSWORD_RESTRICTION = 1325,
    /// The user name or password is incorrect.
    LOGON_FAILURE = 1326,
    /// Account restrictions are preventing this user from signing in.
    /// For example: blank passwords aren't allowed, sign-in times are limited, or a policy restriction has been enforced.
    ACCOUNT_RESTRICTION = 1327,
    /// Your account has time restrictions that keep you from signing in right now.
    INVALID_LOGON_HOURS = 1328,
    /// This user isn't allowed to sign in to this computer.
    INVALID_WORKSTATION = 1329,
    /// The password for this account has expired.
    PASSWORD_EXPIRED = 1330,
    /// This user can't sign in because this account is currently disabled.
    ACCOUNT_DISABLED = 1331,
    /// No mapping between account names and security IDs was done.
    NONE_MAPPED = 1332,
    /// Too many local user identifiers (LUIDs) were requested at one time.
    TOO_MANY_LUIDS_REQUESTED = 1333,
    /// No more local user identifiers (LUIDs) are available.
    LUIDS_EXHAUSTED = 1334,
    /// The subauthority part of a security ID is invalid for this particular use.
    INVALID_SUB_AUTHORITY = 1335,
    /// The access control list (ACL) structure is invalid.
    INVALID_ACL = 1336,
    /// The security ID structure is invalid.
    INVALID_SID = 1337,
    /// The security descriptor structure is invalid.
    INVALID_SECURITY_DESCR = 1338,
    /// The inherited access control list (ACL) or access control entry (ACE) could not be built.
    BAD_INHERITANCE_ACL = 1340,
    /// The server is currently disabled.
    SERVER_DISABLED = 1341,
    /// The server is currently enabled.
    SERVER_NOT_DISABLED = 1342,
    /// The value provided was an invalid value for an identifier authority.
    INVALID_ID_AUTHORITY = 1343,
    /// No more memory is available for security information updates.
    ALLOTTED_SPACE_EXCEEDED = 1344,
    /// The specified attributes are invalid, or incompatible with the attributes for the group as a whole.
    INVALID_GROUP_ATTRIBUTES = 1345,
    /// Either a required impersonation level was not provided, or the provided impersonation level is invalid.
    BAD_IMPERSONATION_LEVEL = 1346,
    /// Cannot open an anonymous level security token.
    CANT_OPEN_ANONYMOUS = 1347,
    /// The validation information class requested was invalid.
    BAD_VALIDATION_CLASS = 1348,
    /// The type of the token is inappropriate for its attempted use.
    BAD_TOKEN_TYPE = 1349,
    /// Unable to perform a security operation on an object that has no associated security.
    NO_SECURITY_ON_OBJECT = 1350,
    /// Configuration information could not be read from the domain controller, either because the machine is unavailable, or access has been denied.
    CANT_ACCESS_DOMAIN_INFO = 1351,
    /// The security account manager (SAM) or local security authority (LSA) server was in the wrong state to perform the security operation.
    INVALID_SERVER_STATE = 1352,
    /// The domain was in the wrong state to perform the security operation.
    INVALID_DOMAIN_STATE = 1353,
    /// This operation is only allowed for the Primary Domain Controller of the domain.
    INVALID_DOMAIN_ROLE = 1354,
    /// The specified domain either does not exist or could not be contacted.
    NO_SUCH_DOMAIN = 1355,
    /// The specified domain already exists.
    DOMAIN_EXISTS = 1356,
    /// An attempt was made to exceed the limit on the number of domains per server.
    DOMAIN_LIMIT_EXCEEDED = 1357,
    /// Unable to complete the requested operation because of either a catastrophic media failure or a data structure corruption on the disk.
    INTERNAL_DB_CORRUPTION = 1358,
    /// An internal error occurred.
    INTERNAL_ERROR = 1359,
    /// Generic access types were contained in an access mask which should already be mapped to nongeneric types.
    GENERIC_NOT_MAPPED = 1360,
    /// A security descriptor is not in the right format (absolute or self-relative).
    BAD_DESCRIPTOR_FORMAT = 1361,
    /// The requested action is restricted for use by logon processes only.
    /// The calling process has not registered as a logon process.
    NOT_LOGON_PROCESS = 1362,
    /// Cannot start a new logon session with an ID that is already in use.
    LOGON_SESSION_EXISTS = 1363,
    /// A specified authentication package is unknown.
    NO_SUCH_PACKAGE = 1364,
    /// The logon session is not in a state that is consistent with the requested operation.
    BAD_LOGON_SESSION_STATE = 1365,
    /// The logon session ID is already in use.
    LOGON_SESSION_COLLISION = 1366,
    /// A logon request contained an invalid logon type value.
    INVALID_LOGON_TYPE = 1367,
    /// Unable to impersonate using a named pipe until data has been read from that pipe.
    CANNOT_IMPERSONATE = 1368,
    /// The transaction state of a registry subtree is incompatible with the requested operation.
    RXACT_INVALID_STATE = 1369,
    /// An internal security database corruption has been encountered.
    RXACT_COMMIT_FAILURE = 1370,
    /// Cannot perform this operation on built-in accounts.
    SPECIAL_ACCOUNT = 1371,
    /// Cannot perform this operation on this built-in special group.
    SPECIAL_GROUP = 1372,
    /// Cannot perform this operation on this built-in special user.
    SPECIAL_USER = 1373,
    /// The user cannot be removed from a group because the group is currently the user's primary group.
    MEMBERS_PRIMARY_GROUP = 1374,
    /// The token is already in use as a primary token.
    TOKEN_ALREADY_IN_USE = 1375,
    /// The specified local group does not exist.
    NO_SUCH_ALIAS = 1376,
    /// The specified account name is not a member of the group.
    MEMBER_NOT_IN_ALIAS = 1377,
    /// The specified account name is already a member of the group.
    MEMBER_IN_ALIAS = 1378,
    /// The specified local group already exists.
    ALIAS_EXISTS = 1379,
    /// Logon failure: the user has not been granted the requested logon type at this computer.
    LOGON_NOT_GRANTED = 1380,
    /// The maximum number of secrets that may be stored in a single system has been exceeded.
    TOO_MANY_SECRETS = 1381,
    /// The length of a secret exceeds the maximum length allowed.
    SECRET_TOO_LONG = 1382,
    /// The local security authority database contains an internal inconsistency.
    INTERNAL_DB_ERROR = 1383,
    /// During a logon attempt, the user's security context accumulated too many security IDs.
    TOO_MANY_CONTEXT_IDS = 1384,
    /// Logon failure: the user has not been granted the requested logon type at this computer.
    LOGON_TYPE_NOT_GRANTED = 1385,
    /// A cross-encrypted password is necessary to change a user password.
    NT_CROSS_ENCRYPTION_REQUIRED = 1386,
    /// A member could not be added to or removed from the local group because the member does not exist.
    NO_SUCH_MEMBER = 1387,
    /// A new member could not be added to a local group because the member has the wrong account type.
    INVALID_MEMBER = 1388,
    /// Too many security IDs have been specified.
    TOO_MANY_SIDS = 1389,
    /// A cross-encrypted password is necessary to change this user password.
    LM_CROSS_ENCRYPTION_REQUIRED = 1390,
    /// Indicates an ACL contains no inheritable components.
    NO_INHERITANCE = 1391,
    /// The file or directory is corrupted and unreadable.
    FILE_CORRUPT = 1392,
    /// The disk structure is corrupted and unreadable.
    DISK_CORRUPT = 1393,
    /// There is no user session key for the specified logon session.
    NO_USER_SESSION_KEY = 1394,
    /// The service being accessed is licensed for a particular number of connections.
    /// No more connections can be made to the service at this time because there are already as many connections as the service can accept.
    LICENSE_QUOTA_EXCEEDED = 1395,
    /// The target account name is incorrect.
    WRONG_TARGET_NAME = 1396,
    /// Mutual Authentication failed. The server's password is out of date at the domain controller.
    MUTUAL_AUTH_FAILED = 1397,
    /// There is a time and/or date difference between the client and server.
    TIME_SKEW = 1398,
    /// This operation cannot be performed on the current domain.
    CURRENT_DOMAIN_NOT_ALLOWED = 1399,
    /// Invalid window handle.
    INVALID_WINDOW_HANDLE = 1400,
    /// Invalid menu handle.
    INVALID_MENU_HANDLE = 1401,
    /// Invalid cursor handle.
    INVALID_CURSOR_HANDLE = 1402,
    /// Invalid accelerator table handle.
    INVALID_ACCEL_HANDLE = 1403,
    /// Invalid hook handle.
    INVALID_HOOK_HANDLE = 1404,
    /// Invalid handle to a multiple-window position structure.
    INVALID_DWP_HANDLE = 1405,
    /// Cannot create a top-level child window.
    TLW_WITH_WSCHILD = 1406,
    /// Cannot find window class.
    CANNOT_FIND_WND_CLASS = 1407,
    /// Invalid window; it belongs to other thread.
    WINDOW_OF_OTHER_THREAD = 1408,
    /// Hot key is already registered.
    HOTKEY_ALREADY_REGISTERED = 1409,
    /// Class already exists.
    CLASS_ALREADY_EXISTS = 1410,
    /// Class does not exist.
    CLASS_DOES_NOT_EXIST = 1411,
    /// Class still has open windows.
    CLASS_HAS_WINDOWS = 1412,
    /// Invalid index.
    INVALID_INDEX = 1413,
    /// Invalid icon handle.
    INVALID_ICON_HANDLE = 1414,
    /// Using private DIALOG window words.
    PRIVATE_DIALOG_INDEX = 1415,
    /// The list box identifier was not found.
    LISTBOX_ID_NOT_FOUND = 1416,
    /// No wildcards were found.
    NO_WILDCARD_CHARACTERS = 1417,
    /// Thread does not have a clipboard open.
    CLIPBOARD_NOT_OPEN = 1418,
    /// Hot key is not registered.
    HOTKEY_NOT_REGISTERED = 1419,
    /// The window is not a valid dialog window.
    WINDOW_NOT_DIALOG = 1420,
    /// Control ID not found.
    CONTROL_ID_NOT_FOUND = 1421,
    /// Invalid message for a combo box because it does not have an edit control.
    INVALID_COMBOBOX_MESSAGE = 1422,
    /// The window is not a combo box.
    WINDOW_NOT_COMBOBOX = 1423,
    /// Height must be less than 256.
    INVALID_EDIT_HEIGHT = 1424,
    /// Invalid device context (DC) handle.
    DC_NOT_FOUND = 1425,
    /// Invalid hook procedure type.
    INVALID_HOOK_FILTER = 1426,
    /// Invalid hook procedure.
    INVALID_FILTER_PROC = 1427,
    /// Cannot set nonlocal hook without a module handle.
    HOOK_NEEDS_HMOD = 1428,
    /// This hook procedure can only be set globally.
    GLOBAL_ONLY_HOOK = 1429,
    /// The journal hook procedure is already installed.
    JOURNAL_HOOK_SET = 1430,
    /// The hook procedure is not installed.
    HOOK_NOT_INSTALLED = 1431,
    /// Invalid message for single-selection list box.
    INVALID_LB_MESSAGE = 1432,
    /// LB_SETCOUNT sent to non-lazy list box.
    SETCOUNT_ON_BAD_LB = 1433,
    /// This list box does not support tab stops.
    LB_WITHOUT_TABSTOPS = 1434,
    /// Cannot destroy object created by another thread.
    DESTROY_OBJECT_OF_OTHER_THREAD = 1435,
    /// Child windows cannot have menus.
    CHILD_WINDOW_MENU = 1436,
    /// The window does not have a system menu.
    NO_SYSTEM_MENU = 1437,
    /// Invalid message box style.
    INVALID_MSGBOX_STYLE = 1438,
    /// Invalid system-wide (SPI_*) parameter.
    INVALID_SPI_VALUE = 1439,
    /// Screen already locked.
    SCREEN_ALREADY_LOCKED = 1440,
    /// All handles to windows in a multiple-window position structure must have the same parent.
    HWNDS_HAVE_DIFF_PARENT = 1441,
    /// The window is not a child window.
    NOT_CHILD_WINDOW = 1442,
    /// Invalid GW_* command.
    INVALID_GW_COMMAND = 1443,
    /// Invalid thread identifier.
    INVALID_THREAD_ID = 1444,
    /// Cannot process a message from a window that is not a multiple document interface (MDI) window.
    NON_MDICHILD_WINDOW = 1445,
    /// Popup menu already active.
    POPUP_ALREADY_ACTIVE = 1446,
    /// The window does not have scroll bars.
    NO_SCROLLBARS = 1447,
    /// Scroll bar range cannot be greater than MAXLONG.
    INVALID_SCROLLBAR_RANGE = 1448,
    /// Cannot show or remove the window in the way specified.
    INVALID_SHOWWIN_COMMAND = 1449,
    /// Insufficient system resources exist to complete the requested service.
    NO_SYSTEM_RESOURCES = 1450,
    /// Insufficient system resources exist to complete the requested service.
    NONPAGED_SYSTEM_RESOURCES = 1451,
    /// Insufficient system resources exist to complete the requested service.
    PAGED_SYSTEM_RESOURCES = 1452,
    /// Insufficient quota to complete the requested service.
    WORKING_SET_QUOTA = 1453,
    /// Insufficient quota to complete the requested service.
    PAGEFILE_QUOTA = 1454,
    /// The paging file is too small for this operation to complete.
    COMMITMENT_LIMIT = 1455,
    /// A menu item was not found.
    MENU_ITEM_NOT_FOUND = 1456,
    /// Invalid keyboard layout handle.
    INVALID_KEYBOARD_HANDLE = 1457,
    /// Hook type not allowed.
    HOOK_TYPE_NOT_ALLOWED = 1458,
    /// This operation requires an interactive window station.
    REQUIRES_INTERACTIVE_WINDOWSTATION = 1459,
    /// This operation returned because the timeout period expired.
    TIMEOUT = 1460,
    /// Invalid monitor handle.
    INVALID_MONITOR_HANDLE = 1461,
    /// Incorrect size argument.
    INCORRECT_SIZE = 1462,
    /// The symbolic link cannot be followed because its type is disabled.
    SYMLINK_CLASS_DISABLED = 1463,
    /// This application does not support the current operation on symbolic links.
    SYMLINK_NOT_SUPPORTED = 1464,
    /// Windows was unable to parse the requested XML data.
    XML_PARSE_ERROR = 1465,
    /// An error was encountered while processing an XML digital signature.
    XMLDSIG_ERROR = 1466,
    /// This application must be restarted.
    RESTART_APPLICATION = 1467,
    /// The caller made the connection request in the wrong routing compartment.
    WRONG_COMPARTMENT = 1468,
    /// There was an AuthIP failure when attempting to connect to the remote host.
    AUTHIP_FAILURE = 1469,
    /// Insufficient NVRAM resources exist to complete the requested service. A reboot might be required.
    NO_NVRAM_RESOURCES = 1470,
    /// Unable to finish the requested operation because the specified process is not a GUI process.
    NOT_GUI_PROCESS = 1471,
    /// The event log file is corrupted.
    EVENTLOG_FILE_CORRUPT = 1500,
    /// No event log file could be opened, so the event logging service did not start.
    EVENTLOG_CANT_START = 1501,
    /// The event log file is full.
    LOG_FILE_FULL = 1502,
    /// The event log file has changed between read operations.
    EVENTLOG_FILE_CHANGED = 1503,
    /// The specified task name is invalid.
    INVALID_TASK_NAME = 1550,
    /// The specified task index is invalid.
    INVALID_TASK_INDEX = 1551,
    /// The specified thread is already joining a task.
    THREAD_ALREADY_IN_TASK = 1552,
    /// The Windows Installer Service could not be accessed.
    /// This can occur if the Windows Installer is not correctly installed. Contact your support personnel for assistance.
    INSTALL_SERVICE_FAILURE = 1601,
    /// User cancelled installation.
    INSTALL_USEREXIT = 1602,
    /// Fatal error during installation.
    INSTALL_FAILURE = 1603,
    /// Installation suspended, incomplete.
    INSTALL_SUSPEND = 1604,
    /// This action is only valid for products that are currently installed.
    UNKNOWN_PRODUCT = 1605,
    /// Feature ID not registered.
    UNKNOWN_FEATURE = 1606,
    /// Component ID not registered.
    UNKNOWN_COMPONENT = 1607,
    /// Unknown property.
    UNKNOWN_PROPERTY = 1608,
    /// Handle is in an invalid state.
    INVALID_HANDLE_STATE = 1609,
    /// The configuration data for this product is corrupt. Contact your support personnel.
    BAD_CONFIGURATION = 1610,
    /// Component qualifier not present.
    INDEX_ABSENT = 1611,
    /// The installation source for this product is not available.
    /// Verify that the source exists and that you can access it.
    INSTALL_SOURCE_ABSENT = 1612,
    /// This installation package cannot be installed by the Windows Installer service.
    /// You must install a Windows service pack that contains a newer version of the Windows Installer service.
    INSTALL_PACKAGE_VERSION = 1613,
    /// Product is uninstalled.
    PRODUCT_UNINSTALLED = 1614,
    /// SQL query syntax invalid or unsupported.
    BAD_QUERY_SYNTAX = 1615,
    /// Record field does not exist.
    INVALID_FIELD = 1616,
    /// The device has been removed.
    DEVICE_REMOVED = 1617,
    /// Another installation is already in progress.
    /// Complete that installation before proceeding with this install.
    INSTALL_ALREADY_RUNNING = 1618,
    /// This installation package could not be opened.
    /// Verify that the package exists and that you can access it, or contact the application vendor to verify that this is a valid Windows Installer package.
    INSTALL_PACKAGE_OPEN_FAILED = 1619,
    /// This installation package could not be opened.
    /// Contact the application vendor to verify that this is a valid Windows Installer package.
    INSTALL_PACKAGE_INVALID = 1620,
    /// There was an error starting the Windows Installer service user interface. Contact your support personnel.
    INSTALL_UI_FAILURE = 1621,
    /// Error opening installation log file.
    /// Verify that the specified log file location exists and that you can write to it.
    INSTALL_LOG_FAILURE = 1622,
    /// The language of this installation package is not supported by your system.
    INSTALL_LANGUAGE_UNSUPPORTED = 1623,
    /// Error applying transforms. Verify that the specified transform paths are valid.
    INSTALL_TRANSFORM_FAILURE = 1624,
    /// This installation is forbidden by system policy. Contact your system administrator.
    INSTALL_PACKAGE_REJECTED = 1625,
    /// Function could not be executed.
    FUNCTION_NOT_CALLED = 1626,
    /// Function failed during execution.
    FUNCTION_FAILED = 1627,
    /// Invalid or unknown table specified.
    INVALID_TABLE = 1628,
    /// Data supplied is of wrong type.
    DATATYPE_MISMATCH = 1629,
    /// Data of this type is not supported.
    UNSUPPORTED_TYPE = 1630,
    /// The Windows Installer service failed to start. Contact your support personnel.
    CREATE_FAILED = 1631,
    /// The Temp folder is on a drive that is full or is inaccessible.
    /// Free up space on the drive or verify that you have write permission on the Temp folder.
    INSTALL_TEMP_UNWRITABLE = 1632,
    /// This installation package is not supported by this processor type. Contact your product vendor.
    INSTALL_PLATFORM_UNSUPPORTED = 1633,
    /// Component not used on this computer.
    INSTALL_NOTUSED = 1634,
    /// This update package could not be opened.
    /// Verify that the update package exists and that you can access it, or contact the application vendor to verify that this is a valid Windows Installer update package.
    PATCH_PACKAGE_OPEN_FAILED = 1635,
    /// This update package could not be opened.
    /// Contact the application vendor to verify that this is a valid Windows Installer update package.
    PATCH_PACKAGE_INVALID = 1636,
    /// This update package cannot be processed by the Windows Installer service.
    /// You must install a Windows service pack that contains a newer version of the Windows Installer service.
    PATCH_PACKAGE_UNSUPPORTED = 1637,
    /// Another version of this product is already installed. Installation of this version cannot continue.
    /// To configure or remove the existing version of this product, use Add/Remove Programs on the Control Panel.
    PRODUCT_VERSION = 1638,
    /// Invalid command line argument. Consult the Windows Installer SDK for detailed command line help.
    INVALID_COMMAND_LINE = 1639,
    /// Only administrators have permission to add, remove, or configure server software during a Terminal services remote session.
    /// If you want to install or configure software on the server, contact your network administrator.
    INSTALL_REMOTE_DISALLOWED = 1640,
    /// The requested operation completed successfully.
    /// The system will be restarted so the changes can take effect.
    SUCCESS_REBOOT_INITIATED = 1641,
    /// The upgrade cannot be installed by the Windows Installer service because the program to be upgraded may be missing, or the upgrade may update a different version of the program.
    /// Verify that the program to be upgraded exists on your computer and that you have the correct upgrade.
    PATCH_TARGET_NOT_FOUND = 1642,
    /// The update package is not permitted by software restriction policy.
    PATCH_PACKAGE_REJECTED = 1643,
    /// One or more customizations are not permitted by software restriction policy.
    INSTALL_TRANSFORM_REJECTED = 1644,
    /// The Windows Installer does not permit installation from a Remote Desktop Connection.
    INSTALL_REMOTE_PROHIBITED = 1645,
    /// Uninstallation of the update package is not supported.
    PATCH_REMOVAL_UNSUPPORTED = 1646,
    /// The update is not applied to this product.
    UNKNOWN_PATCH = 1647,
    /// No valid sequence could be found for the set of updates.
    PATCH_NO_SEQUENCE = 1648,
    /// Update removal was disallowed by policy.
    PATCH_REMOVAL_DISALLOWED = 1649,
    /// The XML update data is invalid.
    INVALID_PATCH_XML = 1650,
    /// Windows Installer does not permit updating of managed advertised products.
    /// At least one feature of the product must be installed before applying the update.
    PATCH_MANAGED_ADVERTISED_PRODUCT = 1651,
    /// The Windows Installer service is not accessible in Safe Mode.
    /// Please try again when your computer is not in Safe Mode or you can use System Restore to return your machine to a previous good state.
    INSTALL_SERVICE_SAFEBOOT = 1652,
    /// A fail fast exception occurred.
    /// Exception handlers will not be invoked and the process will be terminated immediately.
    FAIL_FAST_EXCEPTION = 1653,
    /// The app that you are trying to run is not supported on this version of Windows.
    INSTALL_REJECTED = 1654,
    /// The string binding is invalid.
    RPC_S_INVALID_STRING_BINDING = 1700,
    /// The binding handle is not the correct type.
    RPC_S_WRONG_KIND_OF_BINDING = 1701,
    /// The binding handle is invalid.
    RPC_S_INVALID_BINDING = 1702,
    /// The RPC protocol sequence is not supported.
    RPC_S_PROTSEQ_NOT_SUPPORTED = 1703,
    /// The RPC protocol sequence is invalid.
    RPC_S_INVALID_RPC_PROTSEQ = 1704,
    /// The string universal unique identifier (UUID) is invalid.
    RPC_S_INVALID_STRING_UUID = 1705,
    /// The endpoint format is invalid.
    RPC_S_INVALID_ENDPOINT_FORMAT = 1706,
    /// The network address is invalid.
    RPC_S_INVALID_NET_ADDR = 1707,
    /// No endpoint was found.
    RPC_S_NO_ENDPOINT_FOUND = 1708,
    /// The timeout value is invalid.
    RPC_S_INVALID_TIMEOUT = 1709,
    /// The object universal unique identifier (UUID) was not found.
    RPC_S_OBJECT_NOT_FOUND = 1710,
    /// The object universal unique identifier (UUID) has already been registered.
    RPC_S_ALREADY_REGISTERED = 1711,
    /// The type universal unique identifier (UUID) has already been registered.
    RPC_S_TYPE_ALREADY_REGISTERED = 1712,
    /// The RPC server is already listening.
    RPC_S_ALREADY_LISTENING = 1713,
    /// No protocol sequences have been registered.
    RPC_S_NO_PROTSEQS_REGISTERED = 1714,
    /// The RPC server is not listening.
    RPC_S_NOT_LISTENING = 1715,
    /// The manager type is unknown.
    RPC_S_UNKNOWN_MGR_TYPE = 1716,
    /// The interface is unknown.
    RPC_S_UNKNOWN_IF = 1717,
    /// There are no bindings.
    RPC_S_NO_BINDINGS = 1718,
    /// There are no protocol sequences.
    RPC_S_NO_PROTSEQS = 1719,
    /// The endpoint cannot be created.
    RPC_S_CANT_CREATE_ENDPOINT = 1720,
    /// Not enough resources are available to complete this operation.
    RPC_S_OUT_OF_RESOURCES = 1721,
    /// The RPC server is unavailable.
    RPC_S_SERVER_UNAVAILABLE = 1722,
    /// The RPC server is too busy to complete this operation.
    RPC_S_SERVER_TOO_BUSY = 1723,
    /// The network options are invalid.
    RPC_S_INVALID_NETWORK_OPTIONS = 1724,
    /// There are no remote procedure calls active on this thread.
    RPC_S_NO_CALL_ACTIVE = 1725,
    /// The remote procedure call failed.
    RPC_S_CALL_FAILED = 1726,
    /// The remote procedure call failed and did not execute.
    RPC_S_CALL_FAILED_DNE = 1727,
    /// A remote procedure call (RPC) protocol error occurred.
    RPC_S_PROTOCOL_ERROR = 1728,
    /// Access to the HTTP proxy is denied.
    RPC_S_PROXY_ACCESS_DENIED = 1729,
    /// The transfer syntax is not supported by the RPC server.
    RPC_S_UNSUPPORTED_TRANS_SYN = 1730,
    /// The universal unique identifier (UUID) type is not supported.
    RPC_S_UNSUPPORTED_TYPE = 1732,
    /// The tag is invalid.
    RPC_S_INVALID_TAG = 1733,
    /// The array bounds are invalid.
    RPC_S_INVALID_BOUND = 1734,
    /// The binding does not contain an entry name.
    RPC_S_NO_ENTRY_NAME = 1735,
    /// The name syntax is invalid.
    RPC_S_INVALID_NAME_SYNTAX = 1736,
    /// The name syntax is not supported.
    RPC_S_UNSUPPORTED_NAME_SYNTAX = 1737,
    /// No network address is available to use to construct a universal unique identifier (UUID).
    RPC_S_UUID_NO_ADDRESS = 1739,
    /// The endpoint is a duplicate.
    RPC_S_DUPLICATE_ENDPOINT = 1740,
    /// The authentication type is unknown.
    RPC_S_UNKNOWN_AUTHN_TYPE = 1741,
    /// The maximum number of calls is too small.
    RPC_S_MAX_CALLS_TOO_SMALL = 1742,
    /// The string is too long.
    RPC_S_STRING_TOO_LONG = 1743,
    /// The RPC protocol sequence was not found.
    RPC_S_PROTSEQ_NOT_FOUND = 1744,
    /// The procedure number is out of range.
    RPC_S_PROCNUM_OUT_OF_RANGE = 1745,
    /// The binding does not contain any authentication information.
    RPC_S_BINDING_HAS_NO_AUTH = 1746,
    /// The authentication service is unknown.
    RPC_S_UNKNOWN_AUTHN_SERVICE = 1747,
    /// The authentication level is unknown.
    RPC_S_UNKNOWN_AUTHN_LEVEL = 1748,
    /// The security context is invalid.
    RPC_S_INVALID_AUTH_IDENTITY = 1749,
    /// The authorization service is unknown.
    RPC_S_UNKNOWN_AUTHZ_SERVICE = 1750,
    /// The entry is invalid.
    EPT_S_INVALID_ENTRY = 1751,
    /// The server endpoint cannot perform the operation.
    EPT_S_CANT_PERFORM_OP = 1752,
    /// There are no more endpoints available from the endpoint mapper.
    EPT_S_NOT_REGISTERED = 1753,
    /// No interfaces have been exported.
    RPC_S_NOTHING_TO_EXPORT = 1754,
    /// The entry name is incomplete.
    RPC_S_INCOMPLETE_NAME = 1755,
    /// The version option is invalid.
    RPC_S_INVALID_VERS_OPTION = 1756,
    /// There are no more members.
    RPC_S_NO_MORE_MEMBERS = 1757,
    /// There is nothing to unexport.
    RPC_S_NOT_ALL_OBJS_UNEXPORTED = 1758,
    /// The interface was not found.
    RPC_S_INTERFACE_NOT_FOUND = 1759,
    /// The entry already exists.
    RPC_S_ENTRY_ALREADY_EXISTS = 1760,
    /// The entry is not found.
    RPC_S_ENTRY_NOT_FOUND = 1761,
    /// The name service is unavailable.
    RPC_S_NAME_SERVICE_UNAVAILABLE = 1762,
    /// The network address family is invalid.
    RPC_S_INVALID_NAF_ID = 1763,
    /// The requested operation is not supported.
    RPC_S_CANNOT_SUPPORT = 1764,
    /// No security context is available to allow impersonation.
    RPC_S_NO_CONTEXT_AVAILABLE = 1765,
    /// An internal error occurred in a remote procedure call (RPC).
    RPC_S_INTERNAL_ERROR = 1766,
    /// The RPC server attempted an integer division by zero.
    RPC_S_ZERO_DIVIDE = 1767,
    /// An addressing error occurred in the RPC server.
    RPC_S_ADDRESS_ERROR = 1768,
    /// A floating-point operation at the RPC server caused a division by zero.
    RPC_S_FP_DIV_ZERO = 1769,
    /// A floating-point underflow occurred at the RPC server.
    RPC_S_FP_UNDERFLOW = 1770,
    /// A floating-point overflow occurred at the RPC server.
    RPC_S_FP_OVERFLOW = 1771,
    /// The list of RPC servers available for the binding of auto handles has been exhausted.
    RPC_X_NO_MORE_ENTRIES = 1772,
    /// Unable to open the character translation table file.
    RPC_X_SS_CHAR_TRANS_OPEN_FAIL = 1773,
    /// The file containing the character translation table has fewer than 512 bytes.
    RPC_X_SS_CHAR_TRANS_SHORT_FILE = 1774,
    /// A null context handle was passed from the client to the host during a remote procedure call.
    RPC_X_SS_IN_NULL_CONTEXT = 1775,
    /// The context handle changed during a remote procedure call.
    RPC_X_SS_CONTEXT_DAMAGED = 1777,
    /// The binding handles passed to a remote procedure call do not match.
    RPC_X_SS_HANDLES_MISMATCH = 1778,
    /// The stub is unable to get the remote procedure call handle.
    RPC_X_SS_CANNOT_GET_CALL_HANDLE = 1779,
    /// A null reference pointer was passed to the stub.
    RPC_X_NULL_REF_POINTER = 1780,
    /// The enumeration value is out of range.
    RPC_X_ENUM_VALUE_OUT_OF_RANGE = 1781,
    /// The byte count is too small.
    RPC_X_BYTE_COUNT_TOO_SMALL = 1782,
    /// The stub received bad data.
    RPC_X_BAD_STUB_DATA = 1783,
    /// The supplied user buffer is not valid for the requested operation.
    INVALID_USER_BUFFER = 1784,
    /// The disk media is not recognized. It may not be formatted.
    UNRECOGNIZED_MEDIA = 1785,
    /// The workstation does not have a trust secret.
    NO_TRUST_LSA_SECRET = 1786,
    /// The security database on the server does not have a computer account for this workstation trust relationship.
    NO_TRUST_SAM_ACCOUNT = 1787,
    /// The trust relationship between the primary domain and the trusted domain failed.
    TRUSTED_DOMAIN_FAILURE = 1788,
    /// The trust relationship between this workstation and the primary domain failed.
    TRUSTED_RELATIONSHIP_FAILURE = 1789,
    /// The network logon failed.
    TRUST_FAILURE = 1790,
    /// A remote procedure call is already in progress for this thread.
    RPC_S_CALL_IN_PROGRESS = 1791,
    /// An attempt was made to logon, but the network logon service was not started.
    NETLOGON_NOT_STARTED = 1792,
    /// The user's account has expired.
    ACCOUNT_EXPIRED = 1793,
    /// The redirector is in use and cannot be unloaded.
    REDIRECTOR_HAS_OPEN_HANDLES = 1794,
    /// The specified printer driver is already installed.
    PRINTER_DRIVER_ALREADY_INSTALLED = 1795,
    /// The specified port is unknown.
    UNKNOWN_PORT = 1796,
    /// The printer driver is unknown.
    UNKNOWN_PRINTER_DRIVER = 1797,
    /// The print processor is unknown.
    UNKNOWN_PRINTPROCESSOR = 1798,
    /// The specified separator file is invalid.
    INVALID_SEPARATOR_FILE = 1799,
    /// The specified priority is invalid.
    INVALID_PRIORITY = 1800,
    /// The printer name is invalid.
    INVALID_PRINTER_NAME = 1801,
    /// The printer already exists.
    PRINTER_ALREADY_EXISTS = 1802,
    /// The printer command is invalid.
    INVALID_PRINTER_COMMAND = 1803,
    /// The specified datatype is invalid.
    INVALID_DATATYPE = 1804,
    /// The environment specified is invalid.
    INVALID_ENVIRONMENT = 1805,
    /// There are no more bindings.
    RPC_S_NO_MORE_BINDINGS = 1806,
    /// The account used is an interdomain trust account.
    /// Use your global user account or local user account to access this server.
    NOLOGON_INTERDOMAIN_TRUST_ACCOUNT = 1807,
    /// The account used is a computer account.
    /// Use your global user account or local user account to access this server.
    NOLOGON_WORKSTATION_TRUST_ACCOUNT = 1808,
    /// The account used is a server trust account.
    /// Use your global user account or local user account to access this server.
    NOLOGON_SERVER_TRUST_ACCOUNT = 1809,
    /// The name or security ID (SID) of the domain specified is inconsistent with the trust information for that domain.
    DOMAIN_TRUST_INCONSISTENT = 1810,
    /// The server is in use and cannot be unloaded.
    SERVER_HAS_OPEN_HANDLES = 1811,
    /// The specified image file did not contain a resource section.
    RESOURCE_DATA_NOT_FOUND = 1812,
    /// The specified resource type cannot be found in the image file.
    RESOURCE_TYPE_NOT_FOUND = 1813,
    /// The specified resource name cannot be found in the image file.
    RESOURCE_NAME_NOT_FOUND = 1814,
    /// The specified resource language ID cannot be found in the image file.
    RESOURCE_LANG_NOT_FOUND = 1815,
    /// Not enough quota is available to process this command.
    NOT_ENOUGH_QUOTA = 1816,
    /// No interfaces have been registered.
    RPC_S_NO_INTERFACES = 1817,
    /// The remote procedure call was cancelled.
    RPC_S_CALL_CANCELLED = 1818,
    /// The binding handle does not contain all required information.
    RPC_S_BINDING_INCOMPLETE = 1819,
    /// A communications failure occurred during a remote procedure call.
    RPC_S_COMM_FAILURE = 1820,
    /// The requested authentication level is not supported.
    RPC_S_UNSUPPORTED_AUTHN_LEVEL = 1821,
    /// No principal name registered.
    RPC_S_NO_PRINC_NAME = 1822,
    /// The error specified is not a valid Windows RPC error code.
    RPC_S_NOT_RPC_ERROR = 1823,
    /// A UUID that is valid only on this computer has been allocated.
    RPC_S_UUID_LOCAL_ONLY = 1824,
    /// A security package specific error occurred.
    RPC_S_SEC_PKG_ERROR = 1825,
    /// Thread is not canceled.
    RPC_S_NOT_CANCELLED = 1826,
    /// Invalid operation on the encoding/decoding handle.
    RPC_X_INVALID_ES_ACTION = 1827,
    /// Incompatible version of the serializing package.
    RPC_X_WRONG_ES_VERSION = 1828,
    /// Incompatible version of the RPC stub.
    RPC_X_WRONG_STUB_VERSION = 1829,
    /// The RPC pipe object is invalid or corrupted.
    RPC_X_INVALID_PIPE_OBJECT = 1830,
    /// An invalid operation was attempted on an RPC pipe object.
    RPC_X_WRONG_PIPE_ORDER = 1831,
    /// Unsupported RPC pipe version.
    RPC_X_WRONG_PIPE_VERSION = 1832,
    /// HTTP proxy server rejected the connection because the cookie authentication failed.
    RPC_S_COOKIE_AUTH_FAILED = 1833,
    /// The group member was not found.
    RPC_S_GROUP_MEMBER_NOT_FOUND = 1898,
    /// The endpoint mapper database entry could not be created.
    EPT_S_CANT_CREATE = 1899,
    /// The object universal unique identifier (UUID) is the nil UUID.
    RPC_S_INVALID_OBJECT = 1900,
    /// The specified time is invalid.
    INVALID_TIME = 1901,
    /// The specified form name is invalid.
    INVALID_FORM_NAME = 1902,
    /// The specified form size is invalid.
    INVALID_FORM_SIZE = 1903,
    /// The specified printer handle is already being waited on.
    ALREADY_WAITING = 1904,
    /// The specified printer has been deleted.
    PRINTER_DELETED = 1905,
    /// The state of the printer is invalid.
    INVALID_PRINTER_STATE = 1906,
    /// The user's password must be changed before signing in.
    PASSWORD_MUST_CHANGE = 1907,
    /// Could not find the domain controller for this domain.
    DOMAIN_CONTROLLER_NOT_FOUND = 1908,
    /// The referenced account is currently locked out and may not be logged on to.
    ACCOUNT_LOCKED_OUT = 1909,
    /// The object exporter specified was not found.
    OR_INVALID_OXID = 1910,
    /// The object specified was not found.
    OR_INVALID_OID = 1911,
    /// The object resolver set specified was not found.
    OR_INVALID_SET = 1912,
    /// Some data remains to be sent in the request buffer.
    RPC_S_SEND_INCOMPLETE = 1913,
    /// Invalid asynchronous remote procedure call handle.
    RPC_S_INVALID_ASYNC_HANDLE = 1914,
    /// Invalid asynchronous RPC call handle for this operation.
    RPC_S_INVALID_ASYNC_CALL = 1915,
    /// The RPC pipe object has already been closed.
    RPC_X_PIPE_CLOSED = 1916,
    /// The RPC call completed before all pipes were processed.
    RPC_X_PIPE_DISCIPLINE_ERROR = 1917,
    /// No more data is available from the RPC pipe.
    RPC_X_PIPE_EMPTY = 1918,
    /// No site name is available for this machine.
    NO_SITENAME = 1919,
    /// The file cannot be accessed by the system.
    CANT_ACCESS_FILE = 1920,
    /// The name of the file cannot be resolved by the system.
    CANT_RESOLVE_FILENAME = 1921,
    /// The entry is not of the expected type.
    RPC_S_ENTRY_TYPE_MISMATCH = 1922,
    /// Not all object UUIDs could be exported to the specified entry.
    RPC_S_NOT_ALL_OBJS_EXPORTED = 1923,
    /// Interface could not be exported to the specified entry.
    RPC_S_INTERFACE_NOT_EXPORTED = 1924,
    /// The specified profile entry could not be added.
    RPC_S_PROFILE_NOT_ADDED = 1925,
    /// The specified profile element could not be added.
    RPC_S_PRF_ELT_NOT_ADDED = 1926,
    /// The specified profile element could not be removed.
    RPC_S_PRF_ELT_NOT_REMOVED = 1927,
    /// The group element could not be added.
    RPC_S_GRP_ELT_NOT_ADDED = 1928,
    /// The group element could not be removed.
    RPC_S_GRP_ELT_NOT_REMOVED = 1929,
    /// The printer driver is not compatible with a policy enabled on your computer that blocks NT 4.0 drivers.
    KM_DRIVER_BLOCKED = 1930,
    /// The context has expired and can no longer be used.
    CONTEXT_EXPIRED = 1931,
    /// The current user's delegated trust creation quota has been exceeded.
    PER_USER_TRUST_QUOTA_EXCEEDED = 1932,
    /// The total delegated trust creation quota has been exceeded.
    ALL_USER_TRUST_QUOTA_EXCEEDED = 1933,
    /// The current user's delegated trust deletion quota has been exceeded.
    USER_DELETE_TRUST_QUOTA_EXCEEDED = 1934,
    /// The computer you are signing into is protected by an authentication firewall.
    /// The specified account is not allowed to authenticate to the computer.
    AUTHENTICATION_FIREWALL_FAILED = 1935,
    /// Remote connections to the Print Spooler are blocked by a policy set on your machine.
    REMOTE_PRINT_CONNECTIONS_BLOCKED = 1936,
    /// Authentication failed because NTLM authentication has been disabled.
    NTLM_BLOCKED = 1937,
    /// Logon Failure: EAS policy requires that the user change their password before this operation can be performed.
    PASSWORD_CHANGE_REQUIRED = 1938,
    /// The pixel format is invalid.
    INVALID_PIXEL_FORMAT = 2000,
    /// The specified driver is invalid.
    BAD_DRIVER = 2001,
    /// The window style or class attribute is invalid for this operation.
    INVALID_WINDOW_STYLE = 2002,
    /// The requested metafile operation is not supported.
    METAFILE_NOT_SUPPORTED = 2003,
    /// The requested transformation operation is not supported.
    TRANSFORM_NOT_SUPPORTED = 2004,
    /// The requested clipping operation is not supported.
    CLIPPING_NOT_SUPPORTED = 2005,
    /// The specified color management module is invalid.
    INVALID_CMM = 2010,
    /// The specified color profile is invalid.
    INVALID_PROFILE = 2011,
    /// The specified tag was not found.
    TAG_NOT_FOUND = 2012,
    /// A required tag is not present.
    TAG_NOT_PRESENT = 2013,
    /// The specified tag is already present.
    DUPLICATE_TAG = 2014,
    /// The specified color profile is not associated with the specified device.
    PROFILE_NOT_ASSOCIATED_WITH_DEVICE = 2015,
    /// The specified color profile was not found.
    PROFILE_NOT_FOUND = 2016,
    /// The specified color space is invalid.
    INVALID_COLORSPACE = 2017,
    /// Image Color Management is not enabled.
    ICM_NOT_ENABLED = 2018,
    /// There was an error while deleting the color transform.
    DELETING_ICM_XFORM = 2019,
    /// The specified color transform is invalid.
    INVALID_TRANSFORM = 2020,
    /// The specified transform does not match the bitmap's color space.
    COLORSPACE_MISMATCH = 2021,
    /// The specified named color index is not present in the profile.
    INVALID_COLORINDEX = 2022,
    /// The specified profile is intended for a device of a different type than the specified device.
    PROFILE_DOES_NOT_MATCH_DEVICE = 2023,
    /// The network connection was made successfully, but the user had to be prompted for a password other than the one originally specified.
    CONNECTED_OTHER_PASSWORD = 2108,
    /// The network connection was made successfully using default credentials.
    CONNECTED_OTHER_PASSWORD_DEFAULT = 2109,
    /// The specified username is invalid.
    BAD_USERNAME = 2202,
    /// This network connection does not exist.
    NOT_CONNECTED = 2250,
    /// This network connection has files open or requests pending.
    OPEN_FILES = 2401,
    /// Active connections still exist.
    ACTIVE_CONNECTIONS = 2402,
    /// The device is in use by an active process and cannot be disconnected.
    DEVICE_IN_USE = 2404,
    /// The specified print monitor is unknown.
    UNKNOWN_PRINT_MONITOR = 3000,
    /// The specified printer driver is currently in use.
    PRINTER_DRIVER_IN_USE = 3001,
    /// The spool file was not found.
    SPOOL_FILE_NOT_FOUND = 3002,
    /// A StartDocPrinter call was not issued.
    SPL_NO_STARTDOC = 3003,
    /// An AddJob call was not issued.
    SPL_NO_ADDJOB = 3004,
    /// The specified print processor has already been installed.
    PRINT_PROCESSOR_ALREADY_INSTALLED = 3005,
    /// The specified print monitor has already been installed.
    PRINT_MONITOR_ALREADY_INSTALLED = 3006,
    /// The specified print monitor does not have the required functions.
    INVALID_PRINT_MONITOR = 3007,
    /// The specified print monitor is currently in use.
    PRINT_MONITOR_IN_USE = 3008,
    /// The requested operation is not allowed when there are jobs queued to the printer.
    PRINTER_HAS_JOBS_QUEUED = 3009,
    /// The requested operation is successful.
    /// Changes will not be effective until the system is rebooted.
    SUCCESS_REBOOT_REQUIRED = 3010,
    /// The requested operation is successful.
    /// Changes will not be effective until the service is restarted.
    SUCCESS_RESTART_REQUIRED = 3011,
    /// No printers were found.
    PRINTER_NOT_FOUND = 3012,
    /// The printer driver is known to be unreliable.
    PRINTER_DRIVER_WARNED = 3013,
    /// The printer driver is known to harm the system.
    PRINTER_DRIVER_BLOCKED = 3014,
    /// The specified printer driver package is currently in use.
    PRINTER_DRIVER_PACKAGE_IN_USE = 3015,
    /// Unable to find a core driver package that is required by the printer driver package.
    CORE_DRIVER_PACKAGE_NOT_FOUND = 3016,
    /// The requested operation failed.
    /// A system reboot is required to roll back changes made.
    FAIL_REBOOT_REQUIRED = 3017,
    /// The requested operation failed.
    /// A system reboot has been initiated to roll back changes made.
    FAIL_REBOOT_INITIATED = 3018,
    /// The specified printer driver was not found on the system and needs to be downloaded.
    PRINTER_DRIVER_DOWNLOAD_NEEDED = 3019,
    /// The requested print job has failed to print.
    /// A print system update requires the job to be resubmitted.
    PRINT_JOB_RESTART_REQUIRED = 3020,
    /// The printer driver does not contain a valid manifest, or contains too many manifests.
    INVALID_PRINTER_DRIVER_MANIFEST = 3021,
    /// The specified printer cannot be shared.
    PRINTER_NOT_SHAREABLE = 3022,
    /// The operation was paused.
    REQUEST_PAUSED = 3050,
    /// Reissue the given operation as a cached IO operation.
    IO_REISSUE_AS_CACHED = 3950,
    _,
};

pub const FORMAT_MESSAGE_ALLOCATE_BUFFER = 0x00000100;
pub const FORMAT_MESSAGE_ARGUMENT_ARRAY = 0x00002000;
pub const FORMAT_MESSAGE_FROM_HMODULE = 0x00000800;
pub const FORMAT_MESSAGE_FROM_STRING = 0x00000400;
pub const FORMAT_MESSAGE_FROM_SYSTEM = 0x00001000;
pub const FORMAT_MESSAGE_IGNORE_INSERTS = 0x00000200;
pub const FORMAT_MESSAGE_MAX_WIDTH_MASK = 0x000000FF;

pub const PIPE_ACCESS_INBOUND = 0x00000001;
pub const PIPE_ACCESS_OUTBOUND = 0x00000002;
pub const PIPE_ACCESS_DUPLEX = 0x00000003;

pub const PIPE_TYPE_BYTE = 0x00000000;
pub const PIPE_TYPE_MESSAGE = 0x00000004;

pub const PIPE_READMODE_BYTE = 0x00000000;
pub const PIPE_READMODE_MESSAGE = 0x00000002;

pub const PIPE_WAIT = 0x00000000;
pub const PIPE_NOWAIT = 0x00000001;

pub const GENERIC_READ = 0x80000000;
pub const GENERIC_WRITE = 0x40000000;
pub const GENERIC_EXECUTE = 0x20000000;
pub const GENERIC_ALL = 0x10000000;

pub const FILE_SHARE_DELETE = 0x00000004;
pub const FILE_SHARE_READ = 0x00000001;
pub const FILE_SHARE_WRITE = 0x00000002;

pub const DELETE = 0x00010000;
pub const READ_CONTROL = 0x00020000;
pub const WRITE_DAC = 0x00040000;
pub const WRITE_OWNER = 0x00080000;
pub const SYNCHRONIZE = 0x00100000;
pub const STANDARD_RIGHTS_READ = READ_CONTROL;
pub const STANDARD_RIGHTS_WRITE = READ_CONTROL;
pub const STANDARD_RIGHTS_EXECUTE = READ_CONTROL;
pub const STANDARD_RIGHTS_REQUIRED = DELETE | READ_CONTROL | WRITE_DAC | WRITE_OWNER;

// disposition for NtCreateFile
pub const FILE_SUPERSEDE = 0;
pub const FILE_OPEN = 1;
pub const FILE_CREATE = 2;
pub const FILE_OPEN_IF = 3;
pub const FILE_OVERWRITE = 4;
pub const FILE_OVERWRITE_IF = 5;
pub const FILE_MAXIMUM_DISPOSITION = 5;

// flags for NtCreateFile and NtOpenFile
pub const FILE_READ_DATA = 0x00000001;
pub const FILE_LIST_DIRECTORY = 0x00000001;
pub const FILE_WRITE_DATA = 0x00000002;
pub const FILE_ADD_FILE = 0x00000002;
pub const FILE_APPEND_DATA = 0x00000004;
pub const FILE_ADD_SUBDIRECTORY = 0x00000004;
pub const FILE_CREATE_PIPE_INSTANCE = 0x00000004;
pub const FILE_READ_EA = 0x00000008;
pub const FILE_WRITE_EA = 0x00000010;
pub const FILE_EXECUTE = 0x00000020;
pub const FILE_TRAVERSE = 0x00000020;
pub const FILE_DELETE_CHILD = 0x00000040;
pub const FILE_READ_ATTRIBUTES = 0x00000080;
pub const FILE_WRITE_ATTRIBUTES = 0x00000100;

pub const FILE_DIRECTORY_FILE = 0x00000001;
pub const FILE_WRITE_THROUGH = 0x00000002;
pub const FILE_SEQUENTIAL_ONLY = 0x00000004;
pub const FILE_NO_INTERMEDIATE_BUFFERING = 0x00000008;
pub const FILE_SYNCHRONOUS_IO_ALERT = 0x00000010;
pub const FILE_SYNCHRONOUS_IO_NONALERT = 0x00000020;
pub const FILE_NON_DIRECTORY_FILE = 0x00000040;
pub const FILE_CREATE_TREE_CONNECTION = 0x00000080;
pub const FILE_COMPLETE_IF_OPLOCKED = 0x00000100;
pub const FILE_NO_EA_KNOWLEDGE = 0x00000200;
pub const FILE_OPEN_FOR_RECOVERY = 0x00000400;
pub const FILE_RANDOM_ACCESS = 0x00000800;
pub const FILE_DELETE_ON_CLOSE = 0x00001000;
pub const FILE_OPEN_BY_FILE_ID = 0x00002000;
pub const FILE_OPEN_FOR_BACKUP_INTENT = 0x00004000;
pub const FILE_NO_COMPRESSION = 0x00008000;
pub const FILE_RESERVE_OPFILTER = 0x00100000;
pub const FILE_OPEN_REPARSE_POINT = 0x00200000;
pub const FILE_OPEN_OFFLINE_FILE = 0x00400000;
pub const FILE_OPEN_FOR_FREE_SPACE_QUERY = 0x00800000;

pub const CREATE_ALWAYS = 2;
pub const CREATE_NEW = 1;
pub const OPEN_ALWAYS = 4;
pub const OPEN_EXISTING = 3;
pub const TRUNCATE_EXISTING = 5;

pub const FILE_ATTRIBUTE_ARCHIVE = 0x20;
pub const FILE_ATTRIBUTE_COMPRESSED = 0x800;
pub const FILE_ATTRIBUTE_DEVICE = 0x40;
pub const FILE_ATTRIBUTE_DIRECTORY = 0x10;
pub const FILE_ATTRIBUTE_ENCRYPTED = 0x4000;
pub const FILE_ATTRIBUTE_HIDDEN = 0x2;
pub const FILE_ATTRIBUTE_INTEGRITY_STREAM = 0x8000;
pub const FILE_ATTRIBUTE_NORMAL = 0x80;
pub const FILE_ATTRIBUTE_NOT_CONTENT_INDEXED = 0x2000;
pub const FILE_ATTRIBUTE_NO_SCRUB_DATA = 0x20000;
pub const FILE_ATTRIBUTE_OFFLINE = 0x1000;
pub const FILE_ATTRIBUTE_READONLY = 0x1;
pub const FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS = 0x400000;
pub const FILE_ATTRIBUTE_RECALL_ON_OPEN = 0x40000;
pub const FILE_ATTRIBUTE_REPARSE_POINT = 0x400;
pub const FILE_ATTRIBUTE_SPARSE_FILE = 0x200;
pub const FILE_ATTRIBUTE_SYSTEM = 0x4;
pub const FILE_ATTRIBUTE_TEMPORARY = 0x100;
pub const FILE_ATTRIBUTE_VIRTUAL = 0x10000;

// flags for CreateEvent
pub const CREATE_EVENT_INITIAL_SET = 0x00000002;
pub const CREATE_EVENT_MANUAL_RESET = 0x00000001;

pub const EVENT_ALL_ACCESS = 0x1F0003;
pub const EVENT_MODIFY_STATE = 0x0002;

// MEMORY_BASIC_INFORMATION.Type flags for VirtualQuery
pub const MEM_IMAGE = 0x1000000;
pub const MEM_MAPPED = 0x40000;
pub const MEM_PRIVATE = 0x20000;
