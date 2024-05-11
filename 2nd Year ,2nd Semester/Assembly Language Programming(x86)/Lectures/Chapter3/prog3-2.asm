;TITLE	PROG3-2 (EXE) MULTIWORD ADDITION 
;page	60,132
.MODEL	SMALL
.STACK	64
;---------------------------------------
		.DATA
DATA1	DQ	548FB9963CE7H	;in memory: E7 3C 96 B9 8F 54
;		ORG	0010H
DATA2	DQ	3FCD4FA23B8DH	;in memory: 8D 3B A2 4F CD 3F
;		ORG	0020H
DATA3	DQ	?;945D09387874	;in memory: 74 78 38 09 5D 94
;---------------------------------------
		.CODE
MAIN	PROC	FAR
		MOV	AX, @DATA
		MOV	DS, AX
		;================================================================
		CLC						;clear carry before first addition
		MOV	SI, OFFSET DATA1	;SI is pointer for operand1
		MOV DI, OFFSET DATA2	;DI is pointer for operand2
		MOV	BX, OFFSET DATA3	;BX is pointer for the sum
		MOV	CX, 04				;CX is the loop counter
BACK:	MOV	AX, [SI]			;move the first operand to AX
		ADC AX, [DI]			;add the second operand to AX
		MOV [BX],AX				;store the sum
		INC SI					;increment data pointer
		INC	SI					;to point to next word of operand1
		INC DI					;point to next word of operand2
		INC DI
		INC BX					;point to next word of sum
		INC BX
		LOOP BACK				;if not finished, continue adding
		;================================================================
		MOV	AH,  4CH		
		INT	21H					;go back to dos
MAIN	ENDP
		END	MAIN		