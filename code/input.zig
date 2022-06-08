const EnumArray = @import("std").enums.EnumArray;

pub const Input = struct {
    keys: EnumArray(KeyID, Key),

    pub fn new() Input {
        var input = Input{.keys = undefined};
        input.clearKeys();
        return input;
    }

    pub fn clearKeys(self: *Input) void {
        var iter = self.keys.iterator();
        while (iter.next()) |*entry| {
            entry.value.half_transition_count = 0;
            entry.value.ended_down = false;
        }
    }

    pub fn clearHalfTransitionCounts(self: *Input) void {
        var iter = self.keys.iterator();
        while (iter.next()) |*entry| {
            entry.value.half_transition_count = 0;
        }
    }

    pub fn keyEvent(self: *Input, key_id: KeyID, is_down: bool) void {
        var key = self.keys.getPtr(key_id);
        key.ended_down = is_down;
        key.half_transition_count += 1;
    }

    pub fn pressed(self: *Input, key_id: KeyID) bool {
        const key = self.keys.get(key_id);
        const result = key.half_transition_count > 2 or key.ended_down and key.half_transition_count > 0;
        return result;
    }

    pub fn down(self: *Input, key_id: KeyID) bool {
        return self.keys.get(key_id).ended_down;
    }
};

pub const KeyID = enum {
    left,
    right,
    f5,
};

pub const Key = struct {
    ended_down: bool,
    half_transition_count: i32,
};
