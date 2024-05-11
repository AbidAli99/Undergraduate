;Chapter2 section4 passing parameters via registers
;This program try to calculate the sum of score 
;within a sub procedure. The score table is defined
;inside the DATA segment, and the address is passed in 
;via BX register. 
;The result is passed out via AX register;
		.MODEL SMALL	
		.STACK 64	
		.DATA	
		;define a score table, the first byte is the counter	
STABLE	DB 10, 8, 9, 9, 7, 6, 7, 8, 9, 10, 9
SUMSCORE DB ?	
		.CODE	
MAIN		PROC FAR	;this is the program entry point
		MOV AX, @DATA	;load the data segment address
		MOV DS, AX	;assign value to data segment register
		;MOV BX, OFFSET STABLE;
		;MOV AX, 0H
		CALL SUBP_SUM
		;MOV AVGSCORE, AL
		MOV AH, 4CH	;set up to 
		INT 21H	;return to DOS
MAIN		ENDP	
	; the sub prodedure
SUBP_SUM	PROC
		PUSH CX
		PUSH BX
		PUSH AX
		MOV BX, OFFSET STABLE
		MOV CL, [BX]; LOAD LOOP COUNT
		INC BX;		POINT AT THE FIRST MEMBER 
		MOV AX, 0H
DOSUM:	ADD AL, [BX]
		INC BX
		DEC CL
		JNZ DOSUM
		MOV BX, OFFSET SUMSCORE
		MOV [BX], AL
		POP AX
		POP BX
		POP CX
		RET		;return to main; AX holds the sum
SUBP_SUM	ENDP	
		END MAIN	;this is the program exit point

