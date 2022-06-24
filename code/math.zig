fn V2(comptime T: type) type {
    return struct {
        x: T = 0,
        y: T = 0,

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

        pub fn mulf(self: @This(), other: T) @This() {
            return @This(){ .x = self.x * other, .y = self.y * other };
        }

        pub fn floor(self: @This()) @This() {
            return @This(){ .x = @floor(self.x), .y = @floor(self.y) };
        }

        pub fn ceil(self: @This()) @This() {
            return @This(){ .x = @ceil(self.x), .y = @ceil(self.y) };
        }

        pub fn round(self: @This()) @This() {
            return @This(){ .x = @round(self.x), .y = @round(self.y) };
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
    const NumberType: type = if (T == V2i) i32 else f32;
    return struct {
        topleft: T = T{},
        dim: T = T{},

        pub fn bottomright(rect: @This()) T {
            return rect.topleft.add(rect.dim);
        }

        pub fn clipToRect(rect: @This(), clip: @This()) @This() {
            const result_topleft = rect.topleft.max(clip.topleft);
            const result_bottomright = rect.bottomright().min(clip.bottomright());
            return @This(){ .topleft = result_topleft, .dim = result_bottomright.sub(result_topleft) };
        }

        pub fn to(self: @This(), comptime Target: type) Target {
            switch (Target) {
                Rect2f => return Target{ .topleft = self.topleft.to(V2f), .dim = self.dim.to(V2f) },
                else => @compileError("wrong conversion"),
            }
        }

        pub fn outline(self: @This(), thickness: NumberType) Outline(@This()) {
            const top = @This(){ .topleft = self.topleft, .dim = T{ .x = self.dim.x, .y = thickness } };
            const bottom = @This(){ .topleft = T{ .x = self.topleft.x, .y = self.topleft.y + self.dim.y - thickness }, .dim = top.dim };
            const left = @This(){ .topleft = T{.x = self.topleft.x, .y = self.topleft.y + thickness}, .dim = T{ .x = thickness, .y = self.dim.y - thickness * 2 } };
            const right = @This(){ .topleft = T{ .x = self.topleft.x + self.dim.x - thickness, .y = left.topleft.y }, .dim = left.dim };
            const result = Outline(@This()) {
                .top = top,
                .bottom = bottom,
                .left = left,
                .right = right,
            };
            return result;
        }
    };
}

pub const Rect2i = Rect2(V2i);
pub const Rect2f = Rect2(V2f);

fn Outline(comptime T: type) type {
    return struct {
        top: T,
        bottom: T,
        left: T,
        right: T,
    };
}

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
        const aU32 = @floatToInt(u32, @minimum(@maximum(color255.a, 0), 255)) & 0xFF;
        const rU32 = @floatToInt(u32, @minimum(@maximum(color255.r, 0), 255)) & 0xFF;
        const gU32 = @floatToInt(u32, @minimum(@maximum(color255.g, 0), 255)) & 0xFF;
        const bU32 = @floatToInt(u32, @minimum(@maximum(color255.b, 0), 255)) & 0xFF;
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

    pub fn fromRGB255(r: i32, g: i32, b: i32) Color {
        const result = Color{ .r = @intToFloat(f32, r) / 255, .g = @intToFloat(f32, g) / 255, .b = @intToFloat(f32, b) / 255, .a = 1 };
        return result;
    }

    pub fn transitionBlend(start: Color, on_start: f32, end: Color) Color {
        const final_alpha = start.a * on_start + end.a * (1 - on_start);
        const start_rgb_coef = safeRatio0(on_start * start.a, final_alpha);
        const end_rgb_coef = safeRatio0((1 - on_start) * end.a, final_alpha);
        const result = Color{
            .r = start_rgb_coef * start.r + end_rgb_coef * end.r,
            .g = start_rgb_coef * start.g + end_rgb_coef * end.g,
            .b = start_rgb_coef * start.b + end_rgb_coef * end.b,
            .a = final_alpha,
        };
        return result;
    }

    pub fn lerp(start: Color, from_start: f32, end: Color) Color {
        const result = start.mul(1 - from_start).add(end.mul(from_start));
        return result;
    }
};

fn safeRatio0(v1: f32, v2: f32) f32 {
    if (v2 == 0) {
        return 0;
    }
    return v1 / v2;
}

pub fn pointInRect(point: V2f, rect: Rect2f) bool {
    const bottomright = rect.bottomright();
    const in_x = point.x >= rect.topleft.x and point.x < bottomright.x;
    const in_y = point.y >= rect.topleft.y and point.y < bottomright.y;
    const result = in_x and in_y;
    return result;
}
