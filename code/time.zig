const builtin = @import("builtin");
const platform = if (builtin.os.tag == .windows) @import("time_windows.zig") else @panic("missing time implementation");
usingnamespace platform;
