;========================================================
;Description: Program of Assignment 1 Experiment1
;Author:[ABID ALI][2019380141] 
;Date:[2021/05/13]
;========================================================'
        .MODEL SMALL
        .STACK 32
        .DATA
DATA1    DB 10H,34H,56H,78H,00H
DATA2    DB 90H,88H,77H,66H,00H
DATA3    DB 00H,00H,00H,00H 


        .CODE
MAIN     PROC FAR
         ; INITIALIZE DATA SEGMENT
START:   MOV AX, @DATA
         MOV DS, AX 
         MOV CX,05                       ;INITIALIZING CX=5 TO LOOP 5 TIMES
       
         ; here is the program body 
         MOV BX,OFFSET DATA1             ;WE PUT THE VALUE IN THE BX REGISTER
         MOV SI,OFFSET DATA2
         MOV DI,OFFSET DATA3
       
AGAIN:                                    ;LOOP BODY
       
         MOV AL,[BX]
         INC BX
         ADC AL,[SI]
         INC SI
         MOV [DI],AL
         INC DI
         DEC CX                           ;DECREMENTING THE CX EACH TIME ,TO MAKE IT A FINITE LOOP
         JNZ AGAIN                        ;LOOP AGAIN
         ; RETURN TO DOS                  ;BACK TO DOS
         MOV AX, 4C00H
         INT 21H
MAIN     ENDP
END      MAIN  