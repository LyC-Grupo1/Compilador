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
	_cteStr1 db "asd", '$', 5 dup(?)
	_8 dd 8
	_5 dd 5
	_2 dd 2
	_cteStr2 db "comienzo de Programa", '$', 22 dup(?)
	_15 dd 15
	_cteStr3 db "IF Afirmativo", '$', 15 dup(?)
	_30 dd 30
	_cteStr4 db "Fin de Programa", '$', 17 dup(?)

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
	;ASIGNACION
	fld _cteStr1
	fstp _s
	;SUMA
	fld _5
	fld _8
	fadd
	fstp @aux1
	;SUMA
	fld _2
	fld @aux1
	fadd
	fstp @aux2
	;ASIGNACION
	fld @aux2
	fstp _i
	;SUMA
	fld _5
	fld _8
	fadd
	fstp @aux3
	;SUMA
	fld _2
	fld @aux3
	fadd
	fstp @aux4
	;ASIGNACION
	fld @aux4
	fstp _i
	;SUMA
	fld _5
	fld _8
	fadd
	fstp @aux5
	;SUMA
	fld _2
	fld @aux5
	fadd
	fstp @aux6
	;ASIGNACION
	fld @aux6
	fstp _b
	;ASIGNACION
	fld _s
	fstp _i
	;WRITE
	displayString _cteStr2
	newLine 1

	;CMP
	fld _15
	fld _i
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq49
	JMP _etiq43
_etiq43:
	;WRITE
	displayString _cteStr3
	newLine 1

	;WRITE
	DisplayInteger _i 2
	newLine 1

	JMP _etiq49
_etiq49:
	;CMP
	fld _30
	fld _i
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JBE _etiq65
	JMP _etiq56
_etiq56:
	;WRITE
	DisplayInteger _i 2
	newLine 1

	;SUMA
	fld _1
	fld _i
	fadd
	fstp @aux7
	;ASIGNACION
	fld @aux7
	fstp _i
	JMP _etiq49
_etiq65:
	;CMP
	fld _2
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JA _etiq82
	JMP _etiq72
_etiq72:
	;CMP
	fld _b
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JB _etiq82
	JMP _etiq79
_etiq79:
	JMP _etiq83
_etiq82:
_etiq83:
	;WRITE
	displayString _cteStr4
	newLine 1


TERMINAR: ;Fin de ejecución.
	mov ax, 4C00h ; termina la ejecución.
	int 21h; syscall

END START;final del archivo.