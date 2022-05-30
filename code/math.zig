pub const V2i = struct {
    x: i32,
    y: i32,

    pub fn max(self: V2i, other: V2i) V2i {
        return V2i{ .x = @maximum(self.x, other.x), .y = @maximum(self.y, other.y) };
    }

    pub fn min(self: V2i, other: V2i) V2i {
        return V2i{ .x = @minimum(self.x, other.x), .y = @minimum(self.y, other.y) };
    }

    pub fn add(self: V2i, other: V2i) V2i {
        return V2i{ .x = self.x + other.x, .y = self.y + other.y };
    }

    pub fn sub(self: V2i, other: V2i) V2i {
        return V2i{ .x = self.x - other.x, .y = self.y - other.y };
    }
};

pub const Rect2i = struct {
    topleft: V2i,
    dim: V2i,

    pub fn bottomright(rect: Rect2i) V2i {
        return rect.topleft.add(rect.dim);
    }

    pub fn clipToRect(rect: Rect2i, clip: Rect2i) Rect2i {
        const result_topleft = rect.topleft.max(clip.topleft);
        const result_bottomright = rect.bottomright().min(clip.bottomright());
        return Rect2i{ .topleft = result_topleft, .dim = result_bottomright.sub(result_topleft) };
    }
};

pub const Color = struct {
    r: f32,
    g: f32,
    b: f32,
    a: f32,

    pub fn mul(color: Color, other: f32) Color {
        return Color{ .r = color.r * other, .g = color.g * other, .b = color.b * other, .a = color.a * other };
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
};
