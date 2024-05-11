;========================================================
;Description: Program of Assignment 3 Experiment2
;Author:[name][student ID] 
;Date:[Date]
;========================================================
;there is a variable DATA1 in the data segment
;  and it is in unpacked bcd format
;  please display it with 6 nixie tubes
.MODEL SMALL
.STACK 32
.DATA   
	PORT_A EQU 40H
	PORT_B EQU 42H
	PORT_C EQU 44H
	PORT_CTRL EQU 46H
	CTRLWORD_8255 = 10000000B ;both port output in mode0
	Pattern_Table db 3FH, 06H, 0DBH, 0CFH
         	db 0E6H, 0EDH, 0FDH, 07H
         	db 0FFH, 0EFH, 0F7H, 0FCH
         	db 03DH, 0DEH, 0F9H, 0F1H
    DATA1	db 1,2,3,4,5,6	;unpacked BCD number needs to be displayed
.CODE
MAIN PROC FAR
	MOV	AX, @DATA
	MOV	DS, AX  
	;TODO1: program 8255
	MOV DX, PORT_CTRL
	MOV AL, CTRLWORD_8255
	OUT DX, AL
	;TODO2: prepare to do display in scaning
LOOP1:
	MOV CX, 6 ; 6 unpacked BCD to be display 
	MOV SI, OFFSET DATA1	;SI points to BCD numbers
	MOV AH, 00H
	MOV AL, 0FEH	;prepare tube-active-code, active tube1 in beginning
	;TODO3: begin display
LOOP2:
	;TODO3-1: active a tube, then preserve tube-active-code onto stack for further use
	
   	;TODO3-2: load a BCD number from DATA1 and convert into pattern code, then output to light the tube
   	
	CALL delay	
	;TODO3-3: move to next BCD number, and retrieve tube-active-code from stack, then move to next tube by ROL 
	
	LOOP LOOP2	;		
	JMP LOOP1;
	
	MOV AX, 4C00H
	INT 21H
MAIN ENDP         
;;==============================================================
;SubrOUTine: DELAY
;delay for some millseconds
DELAY	PROC NEAR
        PUSH BX;
        PUSH CX;
   	MOV BX,0Fh
loop_OUT:
	MOV CX, 0FFh
loop_inner:
	LOOP loop_inner			
	DEC BX			
   	JNZ loop_OUT	
   	POP CX;
   	POP BX;	
	RET
DELAY	ENDP
END MAIN