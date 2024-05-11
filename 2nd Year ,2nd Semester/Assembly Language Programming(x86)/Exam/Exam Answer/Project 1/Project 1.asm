;==========================================================
;Description: Program of Project 1 Average and display

;Author:[ABID ALI][2019380141]

;Date:[07/09/2021] 

;========================================================== 
;to find average first we will Calculate the addition of all 10 numbers and then divide the total ny number of elements(10).  
;==========================================================
 
 #start=led_display.exe#
      .MODEL SMALL

      .STACK 32

      .DATA
       PORT_LED EQU 199

DATAI DB 89H,98H,78H,92H,86H,72H,85H,79H,80H,88H

AVERAGE DB 00H   

       .CODE       
MAIN  PROC FAR                    ;THIS IS THE PROGRAM ENTRY POINT
      ;INITIALIZE DATA SEGMENT
      MOV AX, @DATA               ;LOAD THE DATA SEGMENT ADDRESS
      MOV DS, AX                  ;ASSIGN VALUE TO DATA SEGMENT REGISTER
      ;HERE IS THE PROGRAM BODY 
      ;DISPLAY 0 TO TEST THE DEVICE      
      name "led"
      MOV AX,0                    ;MOVING THE VALUE 0 IN 8 BIT AX REGISTER
      MOV DX, PORT_LED   
      OUT DX,AX                   

      MOV DX,0000H   
      LEA SI,DATAI                ;SI POINTS TO THE FIRST  MEMORY LOCATION THAT IS 89H
      MOV CX,0AH                  ;CX CONTAINS THE NUMBER OF ELEMENTS IN THE MEMORY LOCATION
      MOV AH,00H
     
      Calculate: MOV AL,[SI]
      ADD DX,AX                   ;ADDITION OF ALL ELEMENTS IN DX
      DEC CX
      JZ JUMP                     ;JUMPS IF CX IS ZERO THAT IS ALL TEN ELEMENTS HAVE BEEN ADDED
      INC SI
      JMP Calculate


JUMP: MOV AX,DX                   ;JUMP2 LABEL CREATED
      MOV BL,0AH                  ;MOVING 0AH IN BL REGISTER
      DIV BL
      MOV DL,AL                   ;MOVING AL REGISTER INSIDE DL REGISTER
      MOV BL,AL                   ;MOVING AL REGISTER INSIDE BL REGISTER
      MOV BH,00H                  ;MOVING 00H IN BL REGISTER
      CALL DISP                   ;DISPLAYS THE AVG. ON THE EMULATOR SCREEN (DISPLAYING  HEXADECIMAL VALUE)
 
  
  
;DISPLAYING ON LED
  
  
;LED WILL DISPLAY DECIMAL ANSWER
MOV AX,BX
OUT 199,AX
  
  
;RETURN TO DOS
  
MOV AX, 4C00H                     ;SET UP TO
                                  ;RETURN TO DOS
INT 21H

MAIN ENDP
;;==================================================================
;SUBROUTINE:DISP
DISP PROC                         ;PROCEDURE TO DISPLAY
       MOV CL,04H                 ;MOVING 04H IN CL REGISTER
       MOV CH,02H                 ;MOVING 02H IN CH REGISTER
       MOV BL,DL                  ;MOVING DL REGISTER INSIDE BL REGISTER
JUMP1:                            ;JUMP1 LABEL CREATED
       ROL BL,CL
       MOV DL,BL
       AND DL,0FH
       CMP DL,0AH
       JB JUMP2
       ADD DL,07H                 ;JUMP2 LABEL CREATED
JUMP2:
       ADD DL,30H
       MOV AH,02H
       INT 21H
       DEC CH                     ;DECREMENTING CH
       JNZ JUMP1                  ;JUMP NOT ZERO FLAG IS SET,WE GO TO JUMP1
       RET
DISP ENDP

END MAIN                          ;THIS IS THE PROGRAM EXIT POINT