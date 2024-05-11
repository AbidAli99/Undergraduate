;TITLE	PROG3-4 (EXE) LWERCASE TO UPPERCASE CONVERSION
;page	60,132
.MODEL	SMALL
.STACK	64
;---------------------------------------
		.DATA
DATA1	DB	'mY NAME is jOe'	;45H, 57H, 60H, 2DH, 4BH
		ORG	0020H
DATA2	DB	14 DUP(?)
;---------------------------------------
		.CODE
MAIN	PROC	FAR
		MOV	AX, @DATA
		MOV	DS, AX
		;================================================================
		MOV	SI, OFFSET DATA1
		MOV BX, OFFSET DATA2
		MOV	CX, 14
BACK:	MOV	AL, [SI]			;GET NEXT CHARACTER
		CMP	AL, 61H				;IF LESS THAN 'a'
		JB	OVER				;THEN NO NEED TO CONVERT
		CMP AL, 7AH				;IF GREATER THAN 'Z'
		JA	OVER				;THEN NO NEED TO CONVERT
		AND	AL, 11011111B		;MASK D5 TO CONVERT TO UPPERCASE
OVER:	MOV	[BX],AL				;STORE UPPERCASE CHARACTER
		INC	SI
		INC BX
		LOOP BACK		
		;================================================================
		MOV	AH,  4CH		
		INT	21H					;go back to dos
MAIN	ENDP
		END	MAIN	