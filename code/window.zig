pub const Window = struct {
    is_running: bool = false,
    width: i32 = 1000,
    height: i32 = 1000,

    pub fn init(window: *Window) void {
        window.is_running = true;

    }
};
