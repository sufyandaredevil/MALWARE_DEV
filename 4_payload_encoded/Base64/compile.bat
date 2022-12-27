@ECHO OFF

cl.exe /nologo /Ox /MT /W0 /GS- /DNDEBUG /Tcbase64_encoding.cpp /link /OUT:base64_encoding.exe /SUBSYSTEM:CONSOLE /MACHINE:x64