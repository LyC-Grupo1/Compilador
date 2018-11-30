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
	_cadena dd ?
	_s dd ?
	_1 dd 1
	_15 dd 15
	_99.99 dd 99.99
	_.99 dd .99
	_99. dd 99.
	_-542.43 dd -542.43
	_cteStr1 db "", '$', 2 dup(?)
	_7 dd 7
	_5 dd 5
	_4 dd 4
	_16 dd 16
	_2 dd 2
	_8 dd 8
	_30 dd 30
	_3 dd 3
	_cteStr2 db "ewr", '$', 5 dup(?)
	_cteStr3 db "ewr", '$', 5 dup(?)
	_cteStr4 db "@%asdr", '$', 8 dup(?)
	_cteStr5 db "@% > = FA <asdr", '$', 17 dup(?)

.CODE ;Comienzo de la zona de codigo
START: 		 ;Código assembler resultante de compilar el programa fuente.
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
	;ASIGNACION
	fld _.99
	fstp _n
	;ASIGNACION
	fld _99.
	fstp _n
	;ASIGNACION
	fld _-542.43
	fstp _n
	;ASIGNACION
	fld _cteStr1
	fstp _s
_etiq22:
	;CMP
	fld _7
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JBE _etiq36
	JMP _etiq29
_etiq29:
	;SUMA
	fld _b
	fld _5
	fadd
	fstp @aux1
	;ASIGNACION
	fld @aux1
	fstp _i
	JMP _etiq22
_etiq36:
	;CMP
	fld _15
	fld _i
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq
	JMP _etiq43
_etiq43:
	;CMP
	fld _4
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq55
	JMP _etiq50
_etiq50:
	;ASIGNACION
	fld _16
	fstp _i
	JMP _etiq55
_etiq55:
	;CMP
	fld _15
	fld _i
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq
	JMP _etiq62
_etiq62:
	;CMP
	fld _4
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq74
	JMP _etiq69
_etiq69:
	;ASIGNACION
	fld _16
	fstp _i
	JMP _etiq74
_etiq74:
	;CMP
	fld _15
	fld _i
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq
	JMP _etiq81
_etiq81:
	;CMP
	fld _4
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq93
	JMP _etiq88
_etiq88:
	;ASIGNACION
	fld _16
	fstp _i
	JMP _etiq93
_etiq93:
	;CMP
	fld _15
	fld _i
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq100
	JMP _etiq107
_etiq100:
	;CMP
	fld _4
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq112
	JMP _etiq107
_etiq107:
	;ASIGNACION
	fld _16
	fstp _i
	JMP _etiq112
_etiq112:
	;CMP
	fld _15
	fld _i
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq119
	JMP _etiq126
_etiq119:
	;CMP
	fld _4
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq131
	JMP _etiq126
_etiq126:
	;ASIGNACION
	fld _16
	fstp _i
	JMP _etiq131
_etiq131:
	;CMP
	fld _15
	fld _i
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq138
	JMP _etiq145
_etiq138:
	;CMP
	fld _4
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq150
	JMP _etiq145
_etiq145:
	;ASIGNACION
	fld _16
	fstp _i
	JMP _etiq150
_etiq150:
	;CMP
	fld _4
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq164
	JMP _etiq159
_etiq159:
	;ASIGNACION
	fld _16
	fstp _i
	JMP _etiq164
_etiq164:
	;CMP
	fld _2
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JA _etiq185
	JMP _etiq171
_etiq171:
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

	JB _etiq185
	JMP _etiq182
_etiq182:
	JMP _etiq186
_etiq185:
_etiq186:
	;CMP
	fld _0
	fld _0
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq197
	JMP _etiq192
_etiq192:
	;ASIGNACION
	fld _n
	fstp _i
	JMP _etiq197
_etiq197:
	;CMP
	fld _15
	fld _i
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq209
	JMP _etiq204
_etiq204:
	;ASIGNACION
	fld _n
	fstp _i
	JMP _etiq209
_etiq209:
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

	JA _etiq245
	JMP _etiq231
_etiq231:
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

	JB _etiq245
	JMP _etiq242
_etiq242:
	JMP _etiq246
_etiq245:
_etiq246:
	;CMP
	fld _2
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JA _etiq267
	JMP _etiq253
_etiq253:
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

	JB _etiq267
	JMP _etiq264
_etiq264:
	JMP _etiq268
_etiq267:
_etiq268:
	;CMP
	fld _1
	fld _0
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq281
	JMP _etiq274
_etiq274:
	;SUMA
	fld _2
	fld _i
	fadd
	fstp @aux8
	;ASIGNACION
	fld @aux8
	fstp _i
	JMP _etiq281
_etiq281:
	;CMP
	fld _2
	fld _a
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JA _etiq302
	JMP _etiq288
_etiq288:
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

	JB _etiq302
	JMP _etiq299
_etiq299:
	JMP _etiq303
_etiq302:
_etiq303:
	;CMP
	fld _1
	fld _0
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf

	JNE _etiq319
	JMP _etiq309
_etiq309:
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
	JMP _etiq281
_etiq319:
	;WRITE
	DisplayInteger _b 2
	newLine 1

	;WRITE
	displayString _cteStr2
	newLine 1

	;WRITE
	displayString _cteStr3
	newLine 1

	;WRITE
	;WRITE
	displayString _cteStr4
	newLine 1

	;WRITE
	displayString _cteStr5
	newLine 1


TERMINAR: ;Fin de ejecución.
	mov ax, 4C00h ; termina la ejecución.
	int 21h; syscall

END START;final del archivo.