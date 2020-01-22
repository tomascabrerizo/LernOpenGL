if not exist ".\bin" mkdir .\bin
if not exist ".\bin-int" mkdir .\bin-int
if exist "bin\game.exe" del .\bin\game.exe

mingw32-make

move game.exe .\bin
move *.o .\bin-int

bin\game.exe
