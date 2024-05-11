;Chapter7 section3 program7-8: passing parameters via stack
;This program try to calculate the sum of 3 words.
;the words is passed in via stack; 
;The result is passed out via AX register;
		.MODEL SMALL	
		.STACK 64	
		.DATA	
VALUE1	DW	3F62H
VALUE2	DW	1979H
VALUE3	DW	25F1H
RESULT	DW	2DUP(0)
		.CODE	
MAIN		PROC FAR	;this is the program entry point
		MOV AX, @DATA	;load the data segment address
		MOV DS, AX	;assign value to data segment register
		PUSH	VALUE3
		PUSH	VALUE2
		PUSH	VALUE1
		CALL	SUBPROG6	;call the add routine
		MOV RESULT, AX	; the sum
		MOV RESULT+2, BX; the carry if there is any
		MOV AH, 4CH	;set up to 
		INT 21H	;return to DOS
MAIN		ENDP	
;-----------------------------------------
SUBPROG6	PROC 
		SUB BX, BX;CLEAR BX FOR CARRIES
		PUSH BP	;SAVE BP FOR IT IS USED INSIDE SUBPROG
		MOV BP, SP; LOAD STACK POINTER TO BP
		MOV AX, [BP]+4; MOV VALUE1 TO AX
		MOV CX, [BP]+6; MOV VALUE2 TO CX
		MOV DX, [BP]+8; MOV VALUE3 TO DX
		ADD AX, CX
		ADC BX, 00
		ADD AX, DX
		ADC BX, 00
		POP BP
		RET 6;RETURN TO MAIN AND ADD 6 TO SP TO BYPASS DATA
SUBPROG6	ENDP
		END MAIN	;this is the program exit point
