const wnd = @import("window.zig");

pub fn main() !void {
    var window_: wnd.Window = undefined;
    var window = &window_;
    wnd.platform.init(window, 1000, 1000);

    while (window.is_running) {

        wnd.platform.waitForInput(window);
    }
}
