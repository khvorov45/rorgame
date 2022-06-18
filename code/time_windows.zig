const log = @import("log.zig");
const win = @import("windows_bindings.zig");
const outputWindowsError = @import("log_windows.zig").outputWindowsError;

pub const Clock = win.LARGE_INTEGER;

pub fn getCurrentClock() Clock {
    var result: Clock = undefined;
    _ = win.QueryPerformanceCounter(&result);
    return result;
}

pub fn getMsFrom(clock: Clock) f32 {
    var freq: Clock = undefined;
    _ = win.QueryPerformanceFrequency(&freq);

    const diff = getCurrentClock() - clock;
    const diff_ms = @intToFloat(f32, diff) / @intToFloat(f32, freq) * 1000;
    return diff_ms;
}
