const win = @import("windows_bindings.zig");

pub fn panic_exit() noreturn {
    win.ExitProcess(3);
}

pub fn exit() noreturn {
    win.ExitProcess(0);
}
