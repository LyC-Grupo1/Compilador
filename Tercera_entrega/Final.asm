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
	R1 dd ?
	@aux1 dd ?
	@aux2 dd ?
	@aux3 dd ?
	@aux4 dd ?
	@aux5 dd ?
	@aux6 dd ?
	@aux7 dd ?
	@aux8 dd ?
	@aux9 dd ?
	@aux10 dd ?
	@aux11 dd ?
	@aux12 dd ?
	@aux13 dd ?
	@aux14 dd ?
	@aux15 dd ?
	_i dd ?
	_b dd ?
	_a dd ?
	_cadena dd ?
	_s dd ?
	_1 dd 1
	_10 dd 10
	_8 dd 8
	_5 dd 5
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
	;SUMA
	fld _5
	fld _8
	fadd
	fstp @aux1
	;ASIGNACION
	fld @aux1
	fstp _b
	;SUMA
	fld _5
	fld _8
	fadd
	fstp @aux2
	;ASIGNACION
	fld @aux2
	fstp _i
	;CMP
	fld _15
	fld _i
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	jne _etiq29
	jmp _etiq24
_etiq24:
	;ASIGNACION
	fld _16
	fstp _i
	jmp _etiq29
_etiq29:
	;CMP
	fld _2
	fld _a
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	jl _etiq50
	jmp _etiq36
_etiq36:
	;SUMA
	fld _4
	fld _b
	fadd
	fstp @aux3
	;MULTIPLICACION
	fld @aux3
	fld _a
	fmul
	fstp @aux4
	;CMP
	fld @aux4
	fld _a
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	jg _etiq50
	jmp _etiq47
_etiq47:
	jmp _etiq51
_etiq50:
_etiq51:

TERMINAR: ;Fin de ejecución.
	mov ax, 4C00h ; termina la ejecución.
	int 21h; syscall

END START;final del archivo.