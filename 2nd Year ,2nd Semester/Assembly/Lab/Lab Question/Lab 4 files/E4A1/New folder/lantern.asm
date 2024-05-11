;========================================================
;Description: Program of Assignment 1 Experiment4
;Author:[name][student ID] 
;Date:[Date]
;========================================================
;This is the program for 8259 example
; by clicking the bin switch, 
; the lantern moves
.MODEL SMALL
.STACK 32
.DATA   
	PORT_LED EQU ??H
	PORT_8259LOW EQU ??H
	PORT_8259HIGH EQU ??H
	pattern_code db 01H
.CODE
MAIN PROC FAR
	MOV	AX, @DATA
	MOV	DS, AX  
	CLI
	;TODO1: regist ISR
	PUSH DS
	;
	POP DS
	;TODO2: initialize 8259 cmd1,2,4
    	
	;TODO3: light the LSB light
	mov dx,PORT_LED
	MOV AL, pattern_code
	out dx,al
	STI
FIX_BUG:
	MOV DX,60H        
	MOV AL,40H	;dump 40H, which is the int number, to data bus
	OUT DX,AL	
	JMP FIX_BUG
	
	MOV AX, 4C00H
	INT 21H
MAIN ENDP         
;;==============================================================
;SubrOUTine: MY_ISR
MY_ISR	PROC FAR
	cli
	;
	sti
	IRET
MY_ISR	ENDP
END MAIN