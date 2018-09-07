D:\GnuWin32\bin\flex Lexico.l
D:\GnuWin32\bin\bison -dyv Bison.y
D:\MinGW\bin\gcc.exe lex.yy.c y.tab.c -o ejecutar.exe

echo Ejectuando pruebas OK
ejecutar.exe test.txt
pause

echo Ejecutando pruebas NOK
ejecutar.exe PruebasFail.txt
pause
