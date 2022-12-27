@ECHO OFF

cl.exe /nologo /Ox /MT /W0 /GS- /DNDEBUG /TcfunctionObfuscated.cpp /link /OUT:functionObfuscated.exe /SUBSYSTEM:CONSOLE /MACHINE:x64