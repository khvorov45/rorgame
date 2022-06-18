const builtin = @import("builtin");

const assert = @import("std").debug.assert;

const platform = if (builtin.os.tag == .windows) @import("time_windows.zig") else @panic("missing time implementation");
usingnamespace platform;

pub const Section = struct {
    name: []const u8,
    start: platform.Clock,
    ms: f32,

    pub fn begin(section: *Section, name: []const u8) void {
        section.start = platform.getCurrentClock();
        section.name = name;
    }

    pub fn end(section: *Section) void {
        section.ms = platform.getMsFrom(section.start);
    }
};

pub const Sections = struct {
    storage: [64]Section,
    used: usize = 0,

    pub fn begin(sections: *Sections, name: []const u8) void {
        assert(sections.used < sections.storage.len);
        sections.storage[sections.used].begin(name);
    }

    pub fn endLast(sections: *Sections) void {
        assert(sections.used < sections.storage.len);
        sections.storage[sections.used].end();
        sections.used += 1;
    }
};
