@echo off

if not exist .\build mkdir .\build

pushd .\build

cl /Zi ..\handmade.cpp /link user32.lib gdi32.lib

popd 
