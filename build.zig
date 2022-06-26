const std = @import("std");
const builtin = @import("builtin");

pub fn build(b: *std.build.Builder) void {
    const target = b.standardTargetOptions(.{});
    const mode = b.standardReleaseOptions();

    const freetype = b.addStaticLibrary("freetype", null);
    const freetype_include_path = "code/freetype/include";
    freetype.addSystemIncludePath(freetype_include_path);

    const freetype_files = [_][]const u8{
        // Required
        "base/ftsystem.c",
        "base/ftinit.c",
        "base/ftdebug.c",
        "base/ftbase.c",

        // Recommended
        "base/ftbbox.c",
        "base/ftglyph.c",

        // Optional
        "base/ftbdf.c",
        "base/ftbitmap.c",
        "base/ftcid.c",
        "base/ftfstype.c",
        "base/ftgasp.c",
        "base/ftgxval.c",
        "base/ftmm.c",
        "base/ftotval.c",
        "base/ftpatent.c",
        "base/ftpfr.c",
        "base/ftstroke.c",
        "base/ftsynth.c",
        "base/fttype1.c",
        "base/ftwinfnt.c",

        // Font drivers
        "bdf/bdf.c",
        "cff/cff.c",
        "cid/type1cid.c",
        "pcf/pcf.c",
        "pfr/pfr.c",
        "sfnt/sfnt.c",
        "truetype/truetype.c",
        "type1/type1.c",
        "type42/type42.c",
        "winfonts/winfnt.c",

        // Rasterisers
        "raster/raster.c",
        "sdf/sdf.c",
        "smooth/smooth.c",
        "svg/svg.c",

        // Auxillary
        "autofit/autofit.c",
        "cache/ftcache.c",
        "gzip/ftgzip.c",
        "lzw/ftlzw.c",
        "bzip2/ftbzip2.c",
        "gxvalid/gxvalid.c",
        "otvalid/otvalid.c",
        "psaux/psaux.c",
        "pshinter/pshinter.c",
        "psnames/psnames.c",
    };
    const freetype_flags = &[_][]const u8{ "-DFT2_BUILD_LIBRARY" };
    freetype.setTarget(target);
    freetype.setBuildMode(mode);
    inline for (freetype_files) |file| {
        freetype.addCSourceFile("code/freetype/src/" ++ file, freetype_flags);
    }
    freetype.linkLibC();

    const zlib = b.addStaticLibrary("zlib", null);
    const zlib_include_path = "code/zlib";
    zlib.addSystemIncludePath(zlib_include_path);

    const zlib_files = [_][]const u8{
        "adler32.c",
        "compress.c",
        "crc32.c",
        "deflate.c",
        "gzclose.c",
        "gzlib.c",
        "gzread.c",
        "gzwrite.c",
        "infback.c",
        "inffast.c",
        "inflate.c",
        "inftrees.c",
        "trees.c",
        "uncompr.c",
        "zutil.c",
    };
    const zlib_flags = &[_][]const u8{};
    zlib.setTarget(target);
    zlib.setBuildMode(mode);
    inline for (zlib_files) |file| {
        zlib.addCSourceFile("code/zlib/" ++ file, zlib_flags);
    }
    zlib.linkLibC();

    const exe = b.addExecutable("rorgame", "code/rorgame.zig");
    exe.addSystemIncludePath(freetype_include_path); // NOTE(khvorov) For bindings
    exe.addSystemIncludePath(zlib_include_path); // NOTE(khvorov) For bindings
    exe.linkLibrary(freetype);
    exe.linkLibrary(zlib);
    exe.subsystem = .Windows;
    exe.setTarget(target);
    exe.setBuildMode(mode);
    exe.install();
}
