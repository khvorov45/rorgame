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
            entry.value.pressed = false;
        }
    }
};

pub const KeyID = enum {
    f5,
};

pub const Key = struct {
    pressed: bool,
};
