@ECHO OFF

cl.exe /nologo /Ox /MT /W0 /GS- /DNDEBUG /Tcpayload_in_data_section.cpp /link /OUT:payload_in_data_section.exe /SUBSYSTEM:CONSOLE /MACHINE:x64