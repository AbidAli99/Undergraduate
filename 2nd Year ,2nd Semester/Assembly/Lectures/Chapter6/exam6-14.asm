;Example 6-13: transfers a block of 20bytes of data
		.MODEL SMALL	
		.STACK 64	
		.DATA	
		;	
        DATA1 DB 'ABCDEFGHIJKLMNOPQRS$'
        DATA2 DB 20 DUP(?)
		.CODE	
MAIN	PROC FAR	;this is the program entry point
		MOV AX, @DATA	;load the data segment address
		MOV DS, AX	;assign value to data segment register
		MOV	ES, AX
		CLD
		;
		MOV	SI, OFFSET DATA1
		MOV	DI, OFFSET DATA2
		MOV	CX, 20
		REP MOVSB		;Repeat until CX-- = 0
		;; display the duplicated string
        MOV	DX, OFFSET DATA2
        CALL DISPLAY;
		;; return to dos	
		MOV AH, 4CH	
		INT 21H	
MAIN	ENDP	 
;THIS SUBROUTINE DISPLAYS A STRING ON THE SCREEN
DISPLAY PROC    
        PUSH AX
		MOV	AH, 09			;DISPLAY STRING FUNCTION
		;MOV	DX, OFFSET DATAREA	;DX POINTS TO BUFFER
		INT	21H            
		POP AX
		RET
DISPLAY	ENDP  
        ;
		END MAIN	;this is the program exit point
      
      