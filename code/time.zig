const std = @import("std");
const assert = std.debug.assert;

const builtin = @import("builtin");
const platform = if (builtin.os.tag == .windows) @import("time_windows.zig") else @panic("missing time implementation");
usingnamespace platform;

pub const Section = struct {
    start: platform.Clock = 0,
    ms: f32 = 0,
    nest_level: i32 = 0,

    pub fn begin(section: *Section, nest_level: i32) void {
        section.start = platform.getCurrentClock();
        section.nest_level = nest_level;
    }

    pub fn end(section: *Section) void {
        section.ms = platform.getMsFrom(section.start);
    }
};

pub const SectionID = enum {
    frame,
    input,
    update,
    clear_buffers,
    animation,
    debug_atlases,
    debug_timings,
    display_pixels,
};

pub const Sections = struct {
    sections: std.enums.EnumArray(SectionID, ?Section),
    current_nest_level: i32,
    last: [@typeInfo(SectionID).Enum.fields.len]SectionID,
    last_index: usize,

    pub fn new() Sections {
        var sections = Sections {
            .sections = undefined,
            .current_nest_level = 0,
            .last = undefined,
            .last_index = 0,
        };
        var iter = sections.sections.iterator();
        while (iter.next()) |*entry| {
            entry.value.* = null;
        }
        return sections;
    }

    pub fn begin(sections: *Sections, id: SectionID) void {
        assert(sections.last_index < sections.last.len);
        var maybe_section = sections.sections.getPtr(id);
        if (maybe_section.*) |sec| {
            _ = sec;
        } else {
            maybe_section.* = Section{};
        }
        maybe_section.*.?.begin(sections.current_nest_level);
        sections.current_nest_level += 1;
        sections.last[sections.last_index] = id;
        sections.last_index += 1;
    }

    pub fn end(sections: *Sections) void {
        assert(sections.current_nest_level > 0);
        assert(sections.last_index > 0);
        sections.last_index -= 1;
        sections.sections.getPtr(sections.last[sections.last_index]).*.?.end();
        sections.current_nest_level -= 1;
    }
};
