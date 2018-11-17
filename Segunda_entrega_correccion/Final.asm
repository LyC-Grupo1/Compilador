;
;ARCHIVO FINAL.ASM
;

INCLUDE macros2.asm		 ;incluye macros
INCLUDE number.asm		 ;incluye el asm para impresion de numeros

.MODEL LARGE ; tipo del modelo de memoria usado.
.386
.STACK 200h ; bytes en el stack

.CODE ;Comienzo de la zona de codigo
START: 		 ;Código assembler resultante de compilar el programa fuente.
	mov AX,@DATA 		 ;Inicializa el segmento de datos
	mov DS,AX
	;ASIGNACION
	mov R1, _1
	mov _i, R1
	;ASIGNACION
	mov R1, _10
	mov _b, R1
	;SUMA
	mov R1, _i
	add R1, _b
	mov @aux1, R1
	;ASIGNACION
	mov R1, @aux1
	mov _a, R1
	;DIVISION
	mov R1, _i
	div R1, _b
	mov @aux2, R1
	;ASIGNACION
	mov R1, @aux2
	mov _a, R1
	;MULTIPLICACION
	mov R1, _i
	mul R1, _b
	mov @aux3, R1
	;ASIGNACION
	mov R1, @aux3
	mov _a, R1

TERMINAR: ;Fin de ejecución.
	mov ax, 4C00h ; termina la ejecución.
	int 21h; syscall

END START;final del archivo.