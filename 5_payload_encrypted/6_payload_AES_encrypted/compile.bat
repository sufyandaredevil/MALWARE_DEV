@ECHO OFF

cl.exe /nologo /Ox /MT /W0 /GS- /DNDEBUG /Tcaesencrypted.cpp /link /OUT:aesencrypted.exe /SUBSYSTEM:CONSOLE /MACHINE:x64