@ECHO OFF

cl.exe /O2 /D_USRDLL /D_WINDLL mspaintDLL.cpp mspaintDLL.def /MT /link /DLL /OUT:mspaintDLL.dll