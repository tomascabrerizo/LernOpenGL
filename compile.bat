if not exist ".\bin" mkdir .\bin
if not exist ".\bin-int" mkdir .\bin-int

mingw32-make

move game.exe .\bin
move *.o .\bin-int

bin\game.exe