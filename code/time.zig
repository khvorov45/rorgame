const builtin = @import("builtin");
const platform = if (builtin.os.tag == .windows) @import("time_windows.zig") else @panic("missing time implementation");
usingnamespace platform;

pub const Section = struct {
    start: platform.Clock,
    ms: f32,

    pub fn begin(section: *Section) void {
        section.start = platform.getCurrentClock();
    }

    pub fn end(section: *Section) void {
        section.ms = platform.getMsFrom(section.start);
    }
};
