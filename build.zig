const std = @import("std");
const builtin = @import("builtin");

pub fn build(b: *std.Build) !void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const libraylib = b.dependency("libraylib", .{ .target = target, .optimize = optimize });
    const raylib = libraylib.artifact("raylib");

    const exe = b.addExecutable(.{ .name = "Connect4", .target = target, .optimize = optimize });
    exe.addIncludePath(b.path("include"));
    exe.addIncludePath(b.path("deps/raylib/src"));
    exe.linkLibrary(raylib);
    exe.addCSourceFiles(.{ .files = &.{ "src/board.c", "src/game.c", "src/main.c" }, .flags = &.{} });
    exe.linkLibC();
    b.installArtifact(exe);
}
