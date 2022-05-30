const std = @import("std");

pub fn build(b: *std.build.Builder) void {
    // Standard target options allows the person running `zig build` to choose
    // what target to build for. Here we do not override the defaults, which
    // means any target is allowed, and the default is native. Other options
    // for restricting supported target set are available.
    const target = b.standardTargetOptions(.{});

    // Standard release options allow the person running `zig build` to select
    // between Debug, ReleaseSafe, ReleaseFast, and ReleaseSmall.
    const mode = b.standardReleaseOptions();

    const fmt = b.addFmt(&[_][]const u8{"code"});

    const exe = b.addExecutable("rorgame", "code/rorgame.zig");
    exe.step.dependOn(&fmt.step);
    exe.subsystem = .Windows;
    exe.setTarget(target);
    exe.setBuildMode(mode);
    exe.install();
}
