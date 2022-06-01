fn V2(comptime T: type) type {
    return struct {
        x: T,
        y: T,

        pub fn max(self: @This(), other: @This()) @This() {
            return @This(){ .x = @maximum(self.x, other.x), .y = @maximum(self.y, other.y) };
        }

        pub fn min(self: @This(), other: @This()) @This() {
            return @This(){ .x = @minimum(self.x, other.x), .y = @minimum(self.y, other.y) };
        }

        pub fn add(self: @This(), other: @This()) @This() {
            return @This(){ .x = self.x + other.x, .y = self.y + other.y };
        }

        pub fn sub(self: @This(), other: @This()) @This() {
            return @This(){ .x = self.x - other.x, .y = self.y - other.y };
        }

        pub fn to(self: @This(), comptime Target: type) Target {
            switch (Target) {
                V2f => return Target{ .x = @intToFloat(f32, self.x), .y = @intToFloat(f32, self.y) },
                else => @compileError("wrong conversion"),
            }
        }
    };
}

pub const V2i = V2(i32);
pub const V2f = V2(f32);

fn Rect2(comptime T: type) type {
    return struct {
        topleft: T,
        dim: T,

        pub fn bottomright(rect: @This()) T {
            return rect.topleft.add(rect.dim);
        }

        pub fn clipToRect(rect: @This(), clip: @This()) @This() {
            const result_topleft = rect.topleft.max(clip.topleft);
            const result_bottomright = rect.bottomright().min(clip.bottomright());
            return @This(){ .topleft = result_topleft, .dim = result_bottomright.sub(result_topleft) };
        }
    };
}

pub const Rect2i = Rect2(V2i);
pub const Rect2f = Rect2(V2f);

pub const Color = struct {
    r: f32,
    g: f32,
    b: f32,
    a: f32,

    pub fn mul(color: Color, other: f32) Color {
        return Color{ .r = color.r * other, .g = color.g * other, .b = color.b * other, .a = color.a * other };
    }

    pub fn add(color: Color, other: Color) Color {
        return Color{ .r = color.r + other.r, .g = color.g + other.g, .b = color.b + other.b, .a = color.a + other.a };
    }

    pub fn toU32ARGB(color: Color) u32 {
        const color255 = color.mul(255);
        const aU32 = @floatToInt(u32, color255.a) & 0xFF;
        const rU32 = @floatToInt(u32, color255.r) & 0xFF;
        const gU32 = @floatToInt(u32, color255.g) & 0xFF;
        const bU32 = @floatToInt(u32, color255.b) & 0xFF;
        const result = (aU32 << 24) | (rU32 << 16) | (gU32 << 8) | bU32;
        return result;
    }

    pub fn fromU32ARGB(src: u32) Color {
        const a = @intToFloat(f32, (src >> 24) & 0xFF) / 255;
        const r = @intToFloat(f32, (src >> 16) & 0xFF) / 255;
        const g = @intToFloat(f32, (src >> 8) & 0xFF) / 255;
        const b = @intToFloat(f32, (src >> 0) & 0xFF) / 255;
        const result = Color{ .r = r, .g = g, .b = b, .a = a };
        return result;
    }
};
