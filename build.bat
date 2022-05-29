@echo off

zig fmt code
zig build-exe -O Debug -femit-bin=build/rorgame.exe code/rorgame.zig --subsystem windows
