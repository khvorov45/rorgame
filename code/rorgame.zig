const wnd = @import("window.zig");

pub fn main() !void {
    var window_ = wnd.Window{};
    var window = &window_;
    window.init();
}
