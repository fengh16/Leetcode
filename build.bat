@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"
cd /d %1
mkdir build
set compilerflags=/Od /Zi /EHsc /Wall /std:c++14
set linkerflags=/Fe:%1/build/main.exe
cl.exe %compilerflags% %2 %linkerflags%
del %3.obj