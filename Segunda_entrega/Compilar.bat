c:\GnuWin32\bin\flex Lexico.l
pause
c:\GnuWin32\bin\bison -dyv Sintactico.y
pause
c:\MinGW\bin\gcc.exe lex.yy.c y.tab.c -o Compilador.exe
pause
cls
Compilador.exe PRUEBA_REPEAT.txt
pause
del lex.yy.c
del y.tab.c
del y.output
del y.tab.h
del Compilador.exe
cls
pause
