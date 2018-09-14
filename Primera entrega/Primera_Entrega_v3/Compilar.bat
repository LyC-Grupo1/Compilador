d:\GnuWin32\bin\flex Lexico.l
pause
d:\GnuWin32\bin\bison -dyv Sintactico.y
pause
d:\MinGW\bin\gcc.exe lex.yy.c y.tab.c -o Compilador.exe
pause
pause
cls
Compilador.exe PruebaEjemplo.txt
Compilador.exe Prueba1-WHILE.txt
Compilador.exe Prueba2-COMENTARIOS.txt
Compilador.exe Prueba3-DEFVAR.txt
Compilador.exe Prueba4-CONDICIONES.txt
del lex.yy.c
del y.tab.c
del y.output
del y.tab.h
del TPFinal.exe

pause
