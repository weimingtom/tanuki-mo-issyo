echo off
for  /d /r %%A in (?ebug) do rmdir /s /q "%%A" 
for  /r %%B in (*.suo) do del "%%B"
for  /r %%C in (*.user) do del "%%C"
for  /r %%D in (*.ncb) do del "%%D"

for  /d /r %%a in (*.metadata) do rmdir /s /q "%%a"
for  /d /r %%b in (*bin) do rmdir /s /q "%%b"
echo on