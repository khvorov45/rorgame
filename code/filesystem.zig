const builtin = @import("builtin");

const platform = if (builtin.os.tag == .windows) @import("filesystem_windows.zig") else @panic("unimplemented log");
usingnamespace platform;
