;TITLE	PROG3-1B (EXE) ADDING 5 WORDS 
;page	60,132
.MODEL	SMALL
.STACK	64
;---------------------------------------
		.DATA
COUNT	EQU	05
OPD		DW	27345, 28521, 29533, 20105, 32375
;		ORG	0010H				;tell the assembler to pub SUM at DS:0010
SUM		DW	2 DUP(?)			;preserve 4 bytes for result
;---------------------------------------
		.CODE
MAIN	PROC	FAR
		MOV	AX, @DATA
		MOV	DS, AX
		;================================================================
		MOV	CX, COUNT			;CX is the loop counter
		MOV	SI, OFFSET OPD		;SI is the data pointer
		MOV	AX, 00				;AX will hold the sum
		MOV	BX, AX				;BX will hold the carries
BACK:	ADD	AL, [SI]			;add the next word to AX
		ADC BX, 0				;add carry to BX
		INC SI					;increment data pointer twise
		INC	SI					;to point to next word
		DEC CX					;decrement loop counter
		JNZ	BACK				;if not finished, go add next byte
		MOV	SUM, AX				;else, store sum
		MOV	SUM+2, BX			;store the carries
		;================================================================
		MOV	AH,  4CH		
		INT	21H					;go back to dos
MAIN	ENDP
		END	MAIN			