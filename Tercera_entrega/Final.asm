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
	_n dd ?
	_a dd ?
	_b dd ?
	_c dd ?
	_i dd ?
	_cadena db MAXTEXTSIZE dup(?), '$'
	_s db MAXTEXTSIZE dup(?), '$'
	_1 dd 1
	_15 dd 15
	_99.99 dd 99.99
	_7 dd 7
	_5 dd 5
	_4 dd 4
	_16 dd 16
	_2 dd 2
	_8 dd 8
	_30 dd 30
	_3 dd 3
	_cteStr1 db "ewr", '$', 5 dup(?)
	_cteStr2 db "ewr", '$', 5 dup(?)
	_cteStr3 db "@%asdr", '$', 8 dup(?)
	_cteStr4 db "@% > = FA <asdr", '$', 17 dup(?)

.CODE ;Comienzo de la zona de codigo
START: 		 ;CÃ³digo assembler resultante de compilar el programa fuente.
	mov AX,@DATA 		 ;Inicializa el segmento de datos
	mov DS,AX
	;ASIGNACION
	fld _1
	fstp _i
	;ASIGNACION
	fld _15
	fstp _a
	;ASIGNACION
	fld _99.99
	fstp _n
_etiq10:
	;CMP
	fld _7
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JBE _etiq24
	JMP _etiq17
_etiq17:
	;SUMA
	fld _b
	fld _5
	fadd
	fstp @aux1
	;ASIGNACION
	fld @aux1
	fstp _i
	JMP _etiq10
_etiq24:
	;CMP
	fld _15
	fld _i
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq,ý(
	JMP _etiq31
_etiq31:
	;CMP
	fld _4
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq43
	JMP _etiq38
_etiq38:
	;ASIGNACION
	fld _16
	fstp _i
	JMP _etiq43
_etiq43:
	;CMP
	fld _15
	fld _i
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq,ý(
	JMP _etiq50
_etiq50:
	;CMP
	fld _4
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq62
	JMP _etiq57
_etiq57:
	;ASIGNACION
	fld _16
	fstp _i
	JMP _etiq62
_etiq62:
	;CMP
	fld _15
	fld _i
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq,ý(
	JMP _etiq69
_etiq69:
	;CMP
	fld _4
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq81
	JMP _etiq76
_etiq76:
	;ASIGNACION
	fld _16
	fstp _i
	JMP _etiq81
_etiq81:
	;CMP
	fld _15
	fld _i
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq88
	JMP _etiq95
_etiq88:
	;CMP
	fld _4
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq100
	JMP _etiq95
_etiq95:
	;ASIGNACION
	fld _16
	fstp _i
	JMP _etiq100
_etiq100:
	;CMP
	fld _15
	fld _i
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq107
	JMP _etiq114
_etiq107:
	;CMP
	fld _4
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq119
	JMP _etiq114
_etiq114:
	;ASIGNACION
	fld _16
	fstp _i
	JMP _etiq119
_etiq119:
	;CMP
	fld _15
	fld _i
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq126
	JMP _etiq133
_etiq126:
	;CMP
	fld _4
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq138
	JMP _etiq133
_etiq133:
	;ASIGNACION
	fld _16
	fstp _i
	JMP _etiq138
_etiq138:
	;CMP
	fld _4
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq152
	JMP _etiq147
_etiq147:
	;ASIGNACION
	fld _16
	fstp _i
	JMP _etiq152
_etiq152:
	;CMP
	fld _2
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JA _etiq173
	JMP _etiq159
_etiq159:
	;SUMA
	fld _4
	fld _b
	fadd
	fstp @aux2
	;MULTIPLICACION
	fld @aux2
	fld _a
	fmul
	fstp @aux3
	;CMP
	fld @aux3
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JB _etiq173
	JMP _etiq170
_etiq170:
	JMP _etiq174
_etiq173:
_etiq174:
	;CMP
	fld _0
	fld _0
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq185
	JMP _etiq180
_etiq180:
	;ASIGNACION
	fld _a
	fstp _i
	JMP _etiq185
_etiq185:
	;CMP
	fld _15
	fld _i
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq197
	JMP _etiq192
_etiq192:
	;ASIGNACION
	fld _a
	fstp _i
	JMP _etiq197
_etiq197:
	;ASIGNACION
	fld _8
	fstp _a
	;ASIGNACION
	fld _8
	fstp _a
	;ASIGNACION
	fld _8
	fstp _b
	;ASIGNACION
	fld _8
	fstp _c
	;ASIGNACION
	fld _15
	fstp _a
	;ASIGNACION
	fld _30
	fstp _b
	;CMP
	fld _2
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JA _etiq236
	JMP _etiq222
_etiq222:
	;SUMA
	fld _4
	fld _b
	fadd
	fstp @aux4
	;MULTIPLICACION
	fld @aux4
	fld _a
	fmul
	fstp @aux5
	;CMP
	fld @aux5
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JB _etiq236
	JMP _etiq233
_etiq233:
	JMP _etiq237
_etiq236:
_etiq237:
	;CMP
	fld _2
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JA _etiq258
	JMP _etiq244
_etiq244:
	;SUMA
	fld _4
	fld _b
	fadd
	fstp @aux6
	;MULTIPLICACION
	fld @aux6
	fld _a
	fmul
	fstp @aux7
	;CMP
	fld @aux7
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JB _etiq258
	JMP _etiq255
_etiq255:
	JMP _etiq259
_etiq258:
_etiq259:
	;CMP
	fld _1
	fld _0
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq272
	JMP _etiq265
_etiq265:
	;SUMA
	fld _2
	fld _i
	fadd
	fstp @aux8
	;ASIGNACION
	fld @aux8
	fstp _i
	JMP _etiq272
_etiq272:
	;CMP
	fld _2
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JA _etiq293
	JMP _etiq279
_etiq279:
	;SUMA
	fld _4
	fld _b
	fadd
	fstp @aux9
	;MULTIPLICACION
	fld @aux9
	fld _a
	fmul
	fstp @aux10
	;CMP
	fld @aux10
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JB _etiq293
	JMP _etiq290
_etiq290:
	JMP _etiq294
_etiq293:
_etiq294:
	;CMP
	fld _1
	fld _0
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq310
	JMP _etiq300
_etiq300:
	;SUMA
	fld _1
	fld _n
	fadd
	fstp @aux11
	;ASIGNACION
	fld @aux11
	fstp _i
	;ASIGNACION
	fld _3
	fstp _n
	JMP _etiq272
_etiq310:
	;WRITE
	DisplayInteger _b 2
	newLine 1

	;WRITE
	displayString _cteStr1
	newLine 1

	;WRITE
	displayString _cteStr2
	newLine 1

	;WRITE
	;WRITE
	displayString _cteStr3
	newLine 1

	;WRITE
	displayString _cteStr4
	newLine 1


TERMINAR: ;Fin de ejecuciÃ³n.
	mov ax, 4C00h ; termina la ejecuciÃ³n.
	int 21h; syscall

END START;final del archivo.