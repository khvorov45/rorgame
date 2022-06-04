const std = @import("std");

pub fn build(b: *std.build.Builder) void {
    const target = b.standardTargetOptions(.{});
    const mode = b.standardReleaseOptions();

    const fmt = b.addFmt(&[_][]const u8{"code"});

    const exe = b.addExecutable("rorgame", "code/rorgame.zig");
    exe.step.dependOn(&fmt.step);
    exe.subsystem = .Windows;
    exe.setTarget(target);
    exe.setBuildMode(mode);
    exe.install();
}
