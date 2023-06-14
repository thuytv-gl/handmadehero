@echo off
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
w:
cd handmadehero
set path=w:\handmadehero\misc;%path%
start alacritty
