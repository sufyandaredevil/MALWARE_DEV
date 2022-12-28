@ECHO OFF

cl.exe /nologo /Ox /MT /W0 /GS- /DNDEBUG /Tcprocessinjection.cpp /link /OUT:processinjection.exe /SUBSYSTEM:CONSOLE /MACHINE:x64