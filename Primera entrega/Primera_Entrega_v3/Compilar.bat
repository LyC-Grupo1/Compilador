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
Compilador.exe Prueba5-WRITE-READ.txt
Compilador.exe Prueba6-BETWEEN.txt
Compilador.exe Prueba7-ASIGNACION-MULTIPLE.txt

del lex.yy.c
del y.tab.c
del y.output
del y.tab.h
del Compilador.exe

pause
