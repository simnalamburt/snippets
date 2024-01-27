// zig build-exe win32.zig -target x86_64-windows --subsystem windows

const std = @import("std");
const w = std.os.windows;

pub fn main() !void {
    _ = w.user32.MessageBoxA(null, "hello", "title", 0);
}

// You can use wWinMain as well
//
// pub export fn wWinMain(_: w.HINSTANCE, _: ?w.HINSTANCE, _: w.PWSTR, _: c_int) callconv(w.WINAPI) c_int {
//     _ = w.user32.MessageBoxA(null, "hello", "title", 0);
//     return 0;
// }
