;========================================================
;Description: Program of Assignment 1 Experiment 2
;Author:[ABID ALI][2019380141]
;Date:[05/17/2021]
;========================================================
;This is the program for experiment2 assignment 1
;In this program, we try to display numbers with
; a virtual led display device provided by emu8086.
;The port to setup the display is 199
;======================================================== 
#start=led_display.exe#
         .MODEL SMALL
         .STACK 64
         .DATA
         PORT_LED EQU 199
         .CODE
MAIN	 PROC FAR            ;THIS IS THE PROGRAM ENTRY POINT
	     MOV AX, @DATA	     ;LOAD THE DATA SEGMENT ADDRESS
	     MOV DS, AX	         ;ASSIGN VALUE TO DATA SEGMENT REGISTER
;TODO1: DISPLAY 8888 TO TEST THE DEVICE
         MOV AX, 8888        ;MOVING THE VALUE 8888 IN 8 BIT AX REGISTER
         MOV DX, PORT_LED
         OUT DX, AX
	     ;CALL DELAY	         ;CALL DELAY SUB PROCEDURE
;TODO2: START TO DISPLAY NUMBERS
;(put your program to do the display of numbers here)


         MOV AX, 00H
     LOOPBACK:
         OUT DX, AX
         INC AX
         ;CALL DELAY          ;CALL DELAY SUBPROCEDURE
         JMP LOOPBACK
         MOV AH, 4CH         ;SET UP TO
	     INT 21H	         ;RETURN TO DOS
MAIN	 ENDP
;===========================================================
;SUBROUTINE: DELAY
;DELAY CAN BE SEEN FOR FEW MILLISECOND         
DELAY	 PROC NEAR
         PUSH BX             ;PUSH BX IN THE STACK
         PUSH CX             ;PUSH CX IN THE STACK
         MOV BX,0Ah 
loop_OUT:	 MOV CX, 03h     ;LABEL OF OUTERLOOP

loop_inner:	LOOP loop_inner  ;LABEL OF INNERLOOP
         DEC BX
         JNZ loop_OUT
         POP CX              ;POP CX FROM THE STACK
         POP BX              ;POP BX FROM THE STACK
         RET
DELAY	 ENDP
	     END MAIN	         ;THIS IS THE PROGRAM EXIT POINT
