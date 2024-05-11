;========================================================
;Description: Program of Assignment 3 Experiment1
;Author:[ABID ALI][2019380141] 
;Date:[06/05/2021]
;========================================================
;view 8254 output
;LED1 displays out0 of timer0
;LED2 displays out1 of timer1, and LED1 should light for 1s and off for 1s
     .MODEL SMALL
     .STACK 32
     .DATA
         IOS4 EQU 08H;
     .CODE
MAIN PROC FAR
     ;TODO1: PROGRAM TIMER0, BOTH CMD AND INITIAL VALUE
    
     MOV AL, 00110100B         ;TIMER 0 CMD
     MOV DX, IOS4+6
     OUT DX, AL  
     MOV AX, 10000             ;TIMER0 INIT VALUE
     MOV DX,IOS4
     OUT DX, AL
     MOV AL, AH
     OUT DX, AL
     ;TODO1: PROGRAM TIMER1, BOTH CMD AND INITIAL VALUE
     
     MOV AL, 01010110B          ;TIMER1 CMD
     MOV DX, IOS4+6 
     OUT DX, AL
     MOV AX, 100                ;TIMER1 INIT VALUE
     MOV DX, IOS4+2
     OUT DX, AL   
     
         MOV AX, 4C00H
         INT 21H
MAIN ENDP

END MAIN
     
             