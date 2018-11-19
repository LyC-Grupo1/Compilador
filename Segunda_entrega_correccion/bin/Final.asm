;
;ARCHIVO FINAL.ASM
;

INCLUDE macros2.asm		 ;incluye macros
INCLUDE number.asm		 ;incluye el asm para impresion de numeros

.MODEL LARGE ; tipo del modelo de memoria usado.
.386
.STACK 200h ; bytes en el stack
	
.DATA ; comienzo de la zona de datos.
	TRUE equ 1
	FALSE equ 0
	MAXTEXTSIZE equ 200
	_z dd ?
	_i dd ?
	_b dd ?
	_cadena dd ?
	_s dd ?
	_1 dd 1
	_10 dd 10
	_15 dd 15
	_16 dd 16

.CODE ;Comienzo de la zona de codigo
START: 		 ;Código assembler resultante de compilar el programa fuente.
	mov AX,@DATA 		 ;Inicializa el segmento de datos
	mov DS,AX
	;ASIGNACION
	fld _1
	fstp _i
	;ASIGNACION
	fld _10
	fstp _b
	;CMP
	fld _15
	fld _i
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	jne _etiq19
	jmp _etiq14
_etiq14:
	;ASIGNACION
	fld _16
	fstp _i
	jmp _etiq19
_etiq19:
_etiq19:

TERMINAR: ;Fin de ejecución.
	mov ax, 4C00h ; termina la ejecución.
	int 21h; syscall

END START;final del archivo.