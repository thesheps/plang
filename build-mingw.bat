@echo off

mkdir build
cd build

cmake .. -G "MinGW Makefiles"
if %ERRORLEVEL% GEQ 1 GOTO Error

mingw32-make.exe
if %ERRORLEVEL% GEQ 1 GOTO Error

ctest --output-on-failure

:Error