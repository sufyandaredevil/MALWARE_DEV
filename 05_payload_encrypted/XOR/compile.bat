@ECHO OFF

cl.exe /nologo /Ox /MT /W0 /GS- /DNDEBUG /Tcxorencrypted.cpp /link /OUT:xorencrypted.exe /SUBSYSTEM:CONSOLE /MACHINE:x64