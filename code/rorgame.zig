const wnd = @import("window.zig");

pub fn main() !void {
    var window_ = wnd.Window{};
    var window = &window_;
    wnd.platform.init(window, 1000, 1000);
}
