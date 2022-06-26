pub fn readU32le(buffer: *[]u8) u32 {
    const bytes = buffer.*[0..4];
    buffer.* = buffer.*[4..];

    const result =
        (@intCast(u32, bytes[3]) << 24) |
        (@intCast(u32, bytes[2]) << 16) |
        (@intCast(u32, bytes[1]) << 8) |
        (@intCast(u32, bytes[0]));

    return result;
}

pub fn readRGBAasARGB(buffer: *[]u8) u32 {
    const bytes = buffer.*[0..4];
    buffer.* = buffer.*[4..];

    const result =
        (@intCast(u32, bytes[3]) << 24) |
        (@intCast(u32, bytes[0]) << 16) |
        (@intCast(u32, bytes[1]) << 8) |
        (@intCast(u32, bytes[2]));

    return result;
}

pub fn readU16le(buffer: *[]u8) u32 {
    const bytes = buffer.*[0..2];
    buffer.* = buffer.*[2..];

    const result =
        (@intCast(u32, bytes[1]) << 8) |
        (@intCast(u32, bytes[0]));

    return result;
}

pub fn readU8(buffer: *[]u8) u8 {
    const byte = buffer.*[0];
    buffer.* = buffer.*[1..];
    return byte;
}

pub fn readI16le(buffer: *[]u8) i16 {
    const word = readU16le(buffer);
    const result = @bitCast(i16, @intCast(u16, word));
    return result;
}
