;========================================================
;Description: Program of Assignment 1 Experiment4
;Author:[ABID ALI][2019380141] 
;Date:[06/30/2021]
;========================================================
;This is the program for 8259 example
; by clicking the bin switch, 
; the lantern moves
.MODEL SMALL
.MODEL SMALL
.STACK 32
.DATA 
    PORT_LED EQU 68H
    PORT_8259LOW EQU 60H
    PORT_8259HIGH EQU 62H
    pattern_code db 01H
.CODE
MAIN PROC FAR
    MOV AX, @DATA
    MOV DS,AX
    CLI
	;TODO1: regist ISR
    PUSH DS
    MOV AX,0
    MOV DS,AX
    mov SI,40h*4
    MOV BX,OFFSET ISR
    MOV[SI],BX
    MOV BX,SEG ISR
    MOV[SI+2],BX
    POP DS 
	;TODO2: initialize 8259 cmd1,2,4	
    MOV DX,PORT_8259LOW
    MOV AL,00010011B            ;ICW 1
    OUT DX,AL
    MOV DX,PORT_8259HIGH
    MOV AL,40H                  ;ICW 2 
    OUT DX,AL
    MOV AL,00000001B            ;ICW 4
    OUT DX,AL
	;TODO3: light the LSB light
    MOV DX,PORT_LED 
	MOV AL, pattern_code
	out DX,AL
	STI
FIX_BUG:
	MOV DX,60H        
	MOV AL,40H	               ;dump 40H, which is the int number, to data bus
	OUT DX,AL	
	JMP FIX_BUG
	
	MOV AX, 4C00H
	INT 21H
MAIN ENDP         
;;==============================================================
;SubrOUTine: ISR 
ISR	PROC FAR
	cli                        ;The flag may be set or cleared using the CLI (Clear Interrupts)
	PUSH AX                    ;PUSH AX FROM THE STACK
	PUSH DX                    ;PUSH DX FROM THE STACK
	MOV AL,pattern_code        ;pattern_code are put on AL register
	ROL AL,1
	MOV DX,PORT_LED;
	OUT DX,AL
	MOV pattern_code,AL
	MOV DX,PORT_8259LOW
	MOV AL,20H
	OUT DX,AL
	POP DX                     ;POP DX FROM THE STACK
	POP AX                     ;POP AX FROM THE STACK
	sti                        ;The STI instruction sets the IF flag, but interrupts are not checked for until after the next instruction which in this case would be the CLI which takes effect immediately.
	IRET
ISR	ENDP
END MAIN
    
    
    
    
     
    
    