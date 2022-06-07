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
    temp_count: i32,

    pub fn new(comptime reserve: usize, comptime commit: usize) !VirtualArena {
        comptime assert(commit <= reserve);
        const reserve_result = try platform.reserve(reserve);
        const commit_result = try platform.commit(reserve_result.ptr, commit);
        var varena = VirtualArena{
            .base = reserve_result.ptr,
            .reserved = reserve_result.size_actual,
            .committed = commit_result,
            .used = 0,
            .temp_count = 0,
        };
        return varena;
    }

    fn alloc(varena: *VirtualArena, size: usize, ptr_align: u29, len_align: u29, ret_addr: usize) ![]u8 {
        _ = len_align;
        _ = ret_addr;

        var base_aligned = varena.base + varena.used;
        var size_aligned = size;
        alignPtr(&base_aligned, ptr_align, &size_aligned);

        const committed_and_free = varena.committed - varena.used;
        const reserved_and_free = varena.reserved - varena.used;

        if (committed_and_free >= size_aligned) {
            varena.used += size_aligned;
            return base_aligned[0..size];
        } else if (reserved_and_free >= size_aligned) {
            const to_commit = varena.used + size_aligned;
            varena.committed = platform.commit(varena.base, to_commit) catch return error.OutOfMemory;
            varena.used += size_aligned;
            return base_aligned[0..size];
        } else {
            log.err("virtual arena {} out of memory, asked for {} bytes", .{ varena, size_aligned });
            return error.OutOfMemory;
        }
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

    pub fn tempBegin(varena: *VirtualArena) VirtualArenaTemp {
        varena.temp_count += 1;
        return VirtualArenaTemp{ .used = varena.used, .varena = varena };
    }
};

pub const VirtualArenaTemp = struct {
    used: usize,
    varena: *VirtualArena,

    pub fn end(temp: VirtualArenaTemp) void {
        assert(temp.varena.temp_count > 0);
        temp.varena.temp_count -= 1;
        temp.varena.used = temp.used;
    }
};

pub const Arena = struct {
    memory: []u8,
    used: usize,

    pub fn new(size: usize, al: Allocator) !Arena {
        var arena = Arena{
            .memory = try al.allocWithOptions(u8, size, 2 * @alignOf(*u8), null),
            .used = 0,
        };
        return arena;
    }

    fn alloc(arena: *Arena, size: usize, ptr_align: u29, len_align: u29, ret_addr: usize) ![]u8 {
        _ = len_align;
        _ = ret_addr;

        var base_aligned = arena.memory.ptr + arena.used;
        var size_aligned = size;
        alignPtr(&base_aligned, ptr_align, &size_aligned);

        const mem_free = arena.memory.len - arena.used;

        if (mem_free >= size_aligned) {
            arena.used += size_aligned;
            return base_aligned[0..size];
        } else {
            log.err("arena (size {}, used {}) out of memory, asked for {} bytes", .{ arena.memory.len, arena.used, size_aligned });
            return error.OutOfMemory;
        }
    }

    fn resize(arena: *Arena, buf: []u8, buf_align: u29, new_len: usize, len_align: u29, ret_addr: usize) ?usize {
        _ = arena;
        _ = buf;
        _ = buf_align;
        _ = new_len;
        _ = len_align;
        _ = ret_addr;
        panic("arena resize", .{});
        return null;
    }

    fn free(arena: *Arena, buf: []u8, buf_align: u29, ret_addr: usize) void {
        _ = arena;
        _ = buf;
        _ = buf_align;
        _ = ret_addr;
        panic("arena free", .{});
    }

    pub fn allocator(arena: *Arena) std.mem.Allocator {
        return Allocator.init(arena, alloc, resize, free);
    }
};
