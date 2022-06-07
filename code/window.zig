const builtin = @import("builtin");
const platform = if (builtin.os.tag == .windows) @import("window_windows.zig") else @panic("missing window implementation");
usingnamespace platform;
