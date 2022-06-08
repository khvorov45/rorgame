const std = @import("std");

pub fn build(b: *std.build.Builder) void {
    const target = b.standardTargetOptions(.{});
    const mode = b.standardReleaseOptions();

    const exe = b.addExecutable("rorgame", "code/rorgame.zig");
    exe.addCSourceFile("code/freetype.c", &[_][]const u8{"-g", "-O0"});
    exe.subsystem = .Windows;
    exe.setTarget(target);
    exe.setBuildMode(mode);
    exe.install();
}
