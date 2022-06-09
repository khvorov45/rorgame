const std = @import("std");
const builtin = @import("builtin");

pub fn build(b: *std.build.Builder) void {
    const target = b.standardTargetOptions(.{});
    const mode = b.standardReleaseOptions();

    const platform_define = if (builtin.os.tag == .windows) "-DFREETYPE_WINDOWS" else @panic("just windows");

    const exe = b.addExecutable("rorgame", "code/rorgame.zig");
    exe.addCSourceFile("code/freetype.c", &[_][]const u8{"-g", "-O0", platform_define});
    exe.subsystem = .Windows;
    exe.setTarget(target);
    exe.setBuildMode(mode);
    exe.install();
}
