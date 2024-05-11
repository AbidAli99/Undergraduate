;========================================================
;Description: Program of Assignment 2 Experiment 2
;Author:[ABID ALI][2019380141] 
;Date:[05/22/2021]
;==============================================================='
;This is the program for experiment2 assignment 1
;In this program, we try to display,8 LED lights are connected to the data bus 
;start with D9, then  light D8 and turn off D9, then move to the next D7, etc.
;When you reaches D1, please roll back  to D2, and so on, till you turn on D9 again.
;==================================================================
.MODEL SMALL
.STACK 32

.DATA
    PORT_A EQU 40H                ;PORT_A IS NOT A VARIABLE, IT IS JUST SYNONYM FOR NUMBER 40H 
    PORT_CTRL EQU 46H             ;PORT_CTRL IS NOT A VARIABLE, IT IS JUST SYNONYM FOR NUMBER 46H
    CTRLWORD_8255 =10000000B      ;IN CTRLWORD_8255 THE VALUE ASSIGNED 10000000B
    PATTERN_CODE DB  01H          ;PATTERN_CODE DATA BYTE IS 01H
    FLAG_SHIFT DB 00H             ;FLAG_SHIFT CODE DATA BYTE IS 00H 

.CODE                             ;THIS IS THE PROGRAM ENTRY POINT
MAIN PROC FAR                     ;LOAD THE DATA SEGMENT ADDRESS
     MOV AX, @DATA                ;ASSIGN VALUE TO DATA SEGMENT REGISTER
     MOV DS, AX 
     ;TODO1:PROGRAM 8255
     MOV DX, PORT_CTRL            ;MOVING THE VALUE OF PORT_CTRL IN 8 BIT DX REGISTER
     MOV AL, CTRLWORD_8255        ;MOVING THE VALUE OF CTRLWORD_8255 IN 8 BIT AL REGISTER
     OUT DX, AL
     ;TODO2:
     ;Sometesting:output portA
     MOV DX, PORT_A               ;MOVING THE VALUE OF PORT_A IN 8 BIT DX REGISTER
     MOV AL, 0F5H                 ;MOVING THE VALUE (0F5H) IN 8 BIT AL REGISTER
     OUT DX, AL 
    
     MOV AL, PATTERN_CODE
     MOV DX, PORT_A  
MOVE_LEFT:                       ;LABEL OF MOVE_LEFT
     OUT DX,AL                   
     CALL DELAY                  ;CALL DELAY SUB PROCEDURE
     SHL AL, 1                   ;MOVES ALL OF BITS IN AL  LEFT ONE PLACE
     CMP AL,10000000B            ;COMPARING THE AL REGISTER WITH THE VALUE 
     JZ MOVE_RIGHT               ;JUMP ZERO INSTRUCTION,IT'S A CONDITIONAL INSTRUCTION
                                 ;IT JUMP WHEN ZERO FLAG(ZF) IS SET 1
                                 ;JZ is commonly used to explicitly test for something being equal to zero
     JMP MOVE_LEFT                
MOVE_RIGHT:                      ;LABEL OF MOVE_RIGHT
     OUT DX, AL
     CALL DELAY                  ;CALL DELAY SUB PROCEDURE
     SHR AL, 1                   ;MOVES ALL OF BITS IN AL  RIGHT ONE PLACE
     CMP AL, 00000001H
     JZ MOVE_LEFT
     JMP MOVE_RIGHT
     MOV AX,4C00H                ;SET UP TO
     INT 21H                     ;RETURN TO DOS
MAIN ENDP
;;==================================================================
;SUBROUTINE:DELAY
;DELAY FOR SOME MILLISECONDS
DELAY PROC NEAR
      PUSH BX;
      PUSH CX;
      MOV BX, 0FH
LOOP_OUT:
         MOV CX, 0FFH            ;LABEL OF OUTERLOOP                 
LOOP_INNER:                      ;LABEL OF INNERLOOP
         LOOP LOOP_INNER         ;LOOP INSTRUCTION IS USED FOR LOOPING
         DEC BX                  ;BX IS DECREMENTED
         JNZ LOOP_OUT            ;JNZ IS JUMP NOT ZERO,IT'S A CONDITIONAL JUMP  
                                 ;IT JUMPS TO LOOP_OT IF ZERO FLAG(ZF) IS 'ZERO'
         POP CX                  ;POP CX FROM THE STACK
         POP BX;                 ;POP BX FROM THE STACK
         RET                     ;IT'S THE RETURN INSTRUCTION
DELAY	 ENDP                    ;;ENDING POINT DELAY SEGMENT
	     END MAIN	             ;THIS IS THE PROGRAM EXIT POINT
                               
    