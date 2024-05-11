;TITLE	PROG3-1A (EXE ADDING 5 BYTES 
;page	60,132
.MODEL	SMALL
.STACK	64
;---------------------------------------
		.DATA
COUNT	EQU	05
OPD		DB	125,235,197,91,48
;		ORG	0008H				;tell the assembler to pub SUM at DS:0008
SUM		DW	?					;preserve double bytes for result
;---------------------------------------
		.CODE
MAIN	PROC	FAR
		MOV	AX, @DATA
		MOV	DS, AX
		;================================================================
		MOV	CX, count			    ;CX is the loop counter
		MOV	SI, OFFSET OPD		;SI is the data pointer
		MOV	AX, 00				;AX will hold the sum
BACK:	ADD	AL, [SI]			;add the next byte to AL
		JNC	OVER				;if no carry, continue
		INC	AH					;else accumulate carry in AH
OVER:	INC	SI					;increment data pointer
		DEC CX					;decrement loop counter
		JNZ	BACK				;if not finished, go add next byte
		MOV	SUM, AX				;else, store sum
		;================================================================
		MOV	AH,  4CH		
		INT	21H					;go back to dos
MAIN	ENDP
		END	MAIN			