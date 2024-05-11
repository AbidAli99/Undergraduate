;Example 6-15: compare two string and out put result
		.MODEL SMALL	
		.STACK 64	
		.DATA	
		;	
DAT_DICT	DB	'Europe'
DAT_TYPED	DB	'Euorope'
MESSAGE1	DB	'The spelling is correct','$'
MESSAGE2	DB	'Wrong spelling','$'
		.CODE	
MAIN	PROC FAR	;this is the program entry point
		MOV AX, @DATA	;load the data segment address
		MOV DS, AX	;assign value to data segment register
		MOV	ES, AX
		CLD
		MOV	SI, OFFSET DAT_DICT
		MOV	DI, OFFSET DAT_TYPED
		MOV	CX, 06
		REPE CMPSB		;Repeat as long as equal or until CX=0
		JE	OVER		;If ZF=1 then display message1
		MOV	AH, 09H
		MOV	DX, OFFSET MESSAGE2	;If ZF=0 then display message2
		JMP	DISPLAY
		MOV	AH, 09H
OVER:	MOV	DX, OFFSET MESSAGE1
DISPLAY:INT 21H
		;	
		MOV AH, 4CH	;set up to 
		INT 21H	;return to DOS
MAIN	ENDP	
		END MAIN	;this is the program exit point
