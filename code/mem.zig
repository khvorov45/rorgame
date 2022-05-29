const builtin = @import("builtin");
const std = @import("std");

const assert = std.debug.assert;
const panic = std.debug.panic;

const log = @import("log.zig");

pub const platform = if (builtin.os.tag == .windows) @import("mem_windows.zig") else @panic("missing mem implementation");

pub const BYTE = 1;
pub const KILOBYTE = 1024 * BYTE;
pub const MEGABYTE = 1024 * KILOBYTE;
pub const GIGABYTE = 1024 * MEGABYTE;

pub const Error = std.mem.Allocator.Error;
pub const Allocator = std.mem.Allocator;

fn isPowerOf2(val: usize) bool {
    const result = (val & (val - 1)) == 0;
    return result;
}

fn alignPtr(ptr: *[*]u8, ptr_align: usize, size: *usize) void {
    assert(isPowerOf2(ptr_align));
    const ptr_og = ptr.*;
    const off_by = @ptrToInt(ptr_og) & (ptr_align - 1);
    var move_by: usize = 0;
    if (off_by > 0) {
        move_by = ptr_align - off_by;
    }
    const ptr_aligned = ptr_og + move_by;
    ptr.* = ptr_aligned;
    size.* = size.* + move_by;
}

pub const VirtualArena = struct {
    base: [*]u8,
    reserved: usize,
    committed: usize,
    used: usize,

    pub fn new(comptime reserve: usize, comptime commit: usize) VirtualArena {
        comptime assert(commit <= reserve);
        const reserve_result = platform.reserve(reserve);
        const commit_result = platform.commit(reserve_result.ptr, commit);
        var varena = VirtualArena{
            .base = reserve_result.ptr,
            .reserved = reserve_result.size_actual,
            .committed = commit_result,
            .used = 0,
        };
        return varena;
    }

    fn alloc(varena: *VirtualArena, size: usize, ptr_align: u29, len_align: u29, ret_addr: usize) ![]u8 {
        _ = len_align;
        _ = ret_addr;

        var result: Error![]u8 = undefined;

        var base_aligned = varena.base + varena.used;
        var size_aligned = size;
        alignPtr(&base_aligned, ptr_align, &size_aligned);

        const committed_and_free = varena.committed - varena.used;
        const reserved_and_free = varena.reserved - varena.used;

        if (committed_and_free >= size_aligned) {
            result = base_aligned[0..size];
            varena.used += size_aligned;
        } else if (reserved_and_free >= size_aligned) {
            varena.committed = platform.commit(varena.base, varena.used + size_aligned);
            result = base_aligned[0..size];
            varena.used += size_aligned;
        } else {
            log.err("virtual arena {} out of memory, asked for {} bytes", .{ varena, size_aligned });
            result = error.OutOfMemory;
        }

        return result;
    }

    fn resize(varena: *VirtualArena, buf: []u8, buf_align: u29, new_len: usize, len_align: u29, ret_addr: usize) ?usize {
        _ = varena;
        _ = buf;
        _ = buf_align;
        _ = new_len;
        _ = len_align;
        _ = ret_addr;
        panic("Virtual arena resize", .{});
        return null;
    }

    fn free(varena: *VirtualArena, buf: []u8, buf_align: u29, ret_addr: usize) void {
        _ = varena;
        _ = buf;
        _ = buf_align;
        _ = ret_addr;
        panic("Virtual arena free", .{});
    }

    pub fn allocator(varena: *VirtualArena) std.mem.Allocator {
        return Allocator.init(varena, alloc, resize, free);
    }
};
