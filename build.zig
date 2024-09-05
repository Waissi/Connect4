const std = @import("std");
const builtin = @import("builtin");

pub fn build(b: *std.Build) !void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const exe = b.addExecutable(.{ .name = "Connect4", .target = target, .optimize = optimize });
    exe.addIncludePath(b.path("include"));
    exe.addIncludePath(b.path("deps/raylib/zig-out/include"));
    exe.addObjectFile(b.path("deps/raylib/zig-out/lib/libraylib.a"));
    if (builtin.target.os.tag == .macos) {
        exe.linkFramework("CoreVideo");
        exe.linkFramework("IOKit");
        exe.linkFramework("Cocoa");
        exe.linkFramework("GLUT");
        exe.linkFramework("OpenGL");
    }
    exe.addCSourceFiles(.{ .files = &.{ "src/board.c", "src/game.c", "src/main.c" }, .flags = &.{} });
    exe.linkLibC();
    b.installArtifact(exe);
}
