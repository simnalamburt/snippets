// zig build-exe win32.zig -target x86_64-windows

const std = @import("std");

pub fn main() void {
    _ = std.os.windows.user32.MessageBoxA(null, "hello", "title", 0);
}
