;========================================================
;Description: Program of Assignment 3 Experiment2
;Author:[ABID ALI][2019380141] 
;Date:[08/08/2021]
;========================================================
;there is a variable DATA1 in the data segment
;  and it is in unpacked bcd format
;  please display it with 6 nixie tubes
;========================================================       
       .MODEL SMALL
       .STACK 32
       .DATA
       PORT_A EQU 40H
       PORT_B EQU 42H
       PORT_C EQU 44H
       PORT_CTRL EQU 46H
       CTRLWORLD_8255 = 10000000B          ;BOTH PORT WILL OUTPUT IN MOD0
       ;PATTERN TABLE GIVEN TO US ,BY THE TEACHER
       PATTERN_TABLE DB 3FH, 06H, 0DBH, 0CFH
                     DB 0E6H, 0EDH, 0FDH, 07H 
                     DB 0FFH, 0EFH, 0F7H, 0FCH
                     DB 03DH, 0DEH, 0F9H, 0F1H
       ;DATA1         DB 1,2,3,4,5,6         ;UNPACKED BCD NUMBER WILL BE DISPLAYED 
       DATA1         DB 5,6,7,8,9,0          ;UNPACKED BCD NUMBER WILL BE DISPLAYED
       .CODE
       MAIN PROC FAR
            MOV AX, @DATA
            MOV DS, AX
            ;TODO1:PROGRAM 8255
            MOV DX, PORT_CTRL
            MOV AL, 10000000B               ;MOV AL, CTRLWORD_8255
            OUT DX, AL
            ;TODO2:
LOOP1:         
            MOV CX, 6                       ;6 UNPACKED BCD TO BE DISPLAY
            MOV SI, OFFSET DATA1            ;SI WILL BE POINTED 
            MOV AH, 00H
            MOV AL, 0FEH                    ;
            ;TODO3:BEGIN TO DISPLAY        
LOOP2:
            ;
            MOV DX, PORT_C
            OUT DX, AL                      ;
            PUSH AX                         ;PUSH AX IN THE STACK
            ;TODO3
            MOV BX, OFFSET PATTERN_TABLE    ;BX POINTS TO THE PATTERN TABLE
            MOV AL, BYTE PTR [SI]           ;LOADING A BCD NUMBER 
            XLAT                            ;WE ARE RETRIEVE PATTERN-CODE 
            MOV DX, PORT_B
            OUT DX, AL
            CALL DELAY
            ;TODO3-3:                       ;MOVE TO NEXT BCD NUMBER AND RETRIEVE TUBE-ACTIVE-CODE FROM STACK,THEN MOVE TO NEXT TUBE BY ROL
            INC SI                          ;MOVE TO NEXT BCD NUMBER
            POP AX
            ROL AL, 1                       ;CONSTRUCT NEXT TUBE-ACTIVE-CODE
            LOOP LOOP2                      ;
            
            JMP LOOP1                       
            
            MOV AX, 4C00H                   ;RETURN TO DOS
            INT 21H
MAIN ENDP            
;;====================================================================                   
;SUBROUTINE:DELAY
;DELAY FOR SOME MILLISECONDS
DELAY    PROC NEAR
         PUSH BX;                            ;PUSH BX IN THE STACK
         PUSH CX;                            ;PUSH CX IN THE STACK
         MOV BX, 0FH
LOOP_OUT:                                    ;LABEL OF OUTERLOOP
    MOV CX, 0FFH
LOOP_INNER:                                  ;LABEL OF INNERLOOP
    LOOP LOOP_INNER
    DEC BX
    JNZ LOOP_OUT
    POP CX                                   ;POP CX FROM THE STACK
    POP BX                                   ;POP BX FROM THE STACK                                    
    RET
DELAY   ENDP
END MAIN                                    ;THIS IS THE PROGRAM EXIT POINT