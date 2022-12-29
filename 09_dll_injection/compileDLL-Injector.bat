@ECHO OFF

cl.exe /nologo /Ox /MT /W0 /GS- /DNDEBUG /TcDLL-Injector.cpp /link /OUT:DLL-Injector.exe /SUBSYSTEM:CONSOLE /MACHINE:x64