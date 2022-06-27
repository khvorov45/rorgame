const std = @import("std");
const assert = std.debug.assert;

const builtin = @import("builtin");
const platform = if (builtin.os.tag == .windows) @import("time_windows.zig") else @panic("missing time implementation");
usingnamespace platform;

pub const Section = struct {
    start: platform.Clock = 0,
    ms: ?f32 = null,
    nest_level: i32 = 0,

    pub fn begin(section: *Section, nest_level: i32) void {
        section.* = Section{
            .start = platform.getCurrentClock(),
            .nest_level = nest_level,
            .ms = null,
        };
    }

    pub fn end(section: *Section) void {
        section.ms = platform.getMsFrom(section.start);
    }
};

pub const SectionID = enum {
    frame,
    work,
    input,
    update,
    clear_buffers,
    animation,
    debug_atlases,
    debug_timings,
    wait,
    sleep,
    spin,
    display_pixels,
};

pub const SectionsBuf = std.enums.EnumArray(SectionID, Section);

pub const Timer = struct {
    sections: [20]SectionsBuf,
    sections_index: usize,
    current_nest_level: i32,
    last: [@typeInfo(SectionID).Enum.fields.len]SectionID,
    last_index: usize,
    min_sleep_ms: f32,
    cycle_buffers: bool,

    pub fn new() Timer {
        var timer = Timer{
            .sections = undefined,
            .sections_index = 0,
            .current_nest_level = 0,
            .last = undefined,
            .last_index = 0,
            .min_sleep_ms = platform.getMinSleepMs(),
            .cycle_buffers = true,
        };

        for (timer.sections) |*set| {
            var iter = set.iterator();
            while (iter.next()) |*entry| {
                entry.value.* = Section{};
            }
        }

        return timer;
    }

    pub fn getCurrentFrameSections(timer: *Timer) *SectionsBuf {
        return &timer.sections[timer.sections_index];
    }

    pub fn getLastFrameSections(timer: *Timer) *SectionsBuf {
        var index = timer.sections_index;
        if (index == 0) {
            index = timer.sections.len - 1;
        } else {
            index -= 1;
        }
        return &timer.sections[index];
    }

    pub fn getNextSectionsIndex(timer: *Timer, index: usize) usize {
        const result = (index + 1) % timer.sections.len;
        return result;
    }

    pub fn getPrevSectionsIndex(timer: *Timer, index: usize) usize {
        var result = index;
        if (result == 0) {
            result = timer.sections.len - 1;
        } else {
            result -= 1;
        }
        return result;
    }

    pub fn begin(timer: *Timer, id: SectionID) void {
        assert(timer.last_index < timer.last.len);
        const sections = timer.getCurrentFrameSections();
        sections.getPtr(id).begin(timer.current_nest_level);
        timer.current_nest_level += 1;
        timer.last[timer.last_index] = id;
        timer.last_index += 1;
    }

    pub fn end(timer: *Timer) void {
        assert(timer.current_nest_level > 0);
        assert(timer.last_index > 0);
        timer.last_index -= 1;
        const last_id = timer.last[timer.last_index];
        const sections = timer.getCurrentFrameSections();
        sections.getPtr(last_id).end();
        timer.current_nest_level -= 1;
        if (last_id == .frame) {
            if (timer.cycle_buffers) {
                timer.sections_index = (timer.sections_index + 1) % timer.sections.len;
            }
            var iter = timer.sections[timer.sections_index].iterator();
            while (iter.next()) |entry| {
                entry.value.ms = null;
            }
        }
    }

    pub fn getMsFromSectionStart(timer: *Timer, id: SectionID) f32 {
        const result = platform.getMsFrom(timer.getCurrentFrameSections().get(id).start);
        return result;
    }

    pub fn sleep(timer: Timer, ms: f32) void {
        const periods = @floor(ms / timer.min_sleep_ms);
        const to_sleep = timer.min_sleep_ms * periods;
        if (to_sleep > 0) {
            platform.sleep(to_sleep);
        }
    }
};
