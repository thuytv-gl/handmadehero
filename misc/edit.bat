@echo off
nvim ^
-c ":nmap <M-b> :!build<CR>" ^
-c ":nmap <M-d> :!devenv build\handmade.exe /DebugExe<CR>" ^
-c ":nmap <M-r> :!build\handmade.exe<CR>"
