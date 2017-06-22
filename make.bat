@echo off

set GENERATOR=Visual Studio 15 2017

IF NOT "x%1" == "x" GOTO :%1

GOTO :build

:projects
cmake -H. -Bbuild -G"%GENERATOR%"
GOTO :end

:build
cmake -H. -Bbuild -G"%GENERATOR%"
cmake --build build --config Release
GOTO :end

:clean
IF EXIST build RMDIR /S /Q build
GOTO :end

:test
cmake -H. -Bbuild -G"%GENERATOR%"
cmake --build build --config Release
call "build/Release/TestLua51Bindings.exe"
GOTO :end

:end