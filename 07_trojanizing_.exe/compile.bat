@ECHO OFF

cl.exe /nologo /Ox /MT /W0 /GS- /DNDEBUG /Tcshellcoderunner.cpp /link /OUT:shellcoderunner.exe /SUBSYSTEM:CONSOLE /MACHINE:x86