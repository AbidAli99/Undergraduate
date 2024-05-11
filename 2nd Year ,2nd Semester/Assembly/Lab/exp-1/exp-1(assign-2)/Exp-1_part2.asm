;========================================================
;Description: Program of Assignment 2 Experiment1
;Author:[ABID ALI][2019380141] 
;Date:[2021/05/14]
;SORTING ARRAY BY USING BUBBLE SORT ALGORITHM 
;========================================================
          INCLUDE 'EMU8086.INC'
          .MODEL SMALL
          .STACK 32

          .DATA

DATAS     DB 21H,13H,4H,5H,7H, 6H,8H,20H,9H,11H 
DATANUM   DW 10
      

          .CODE
MAIN      PROC
          MOV AX, @DATA                ; initialize DS
          MOV DS, AX
          
          MOV BX,DATANUM               ; set BX=10

     

          LEA SI, DATAS                ; set SI=offset address of DATAS

          CALL PRINT_DATAS             ; call the procedure PRINT_DATAS

          LEA SI, DATAS                ; set SI=offset address of the DATAS

          CALL BUBBLE_SORT             ; call the procedure BUBBLE_SORT

          PRINTN

          LEA SI, DATAS                ; set SI=offset address of DATAS

          CALL PRINT_DATAS             ; call the procedure PRINT_DATAS

          MOV AH, 4CH                  ; return control to DOS
          INT 21H
MAIN      ENDP



 ;-------------------------  Procedure Definitions  ------------------------;




 ;-----------------------------  PRINT_DATAS  ------------------------------;


PRINT_DATAS PROC
   ; this procedure will print the elements of a given array
   ; input : SI=offset address of the array
   ;       : DATANUM=BX=size of the array
   ; output : none

          PUSH AX                    ; push AX onto the STACK   
          PUSH CX                    ; push CX onto the STACK
          PUSH DX                    ; push DX onto the STACK

          MOV CX, BX                 ; set CX=BX

   @PRINT_DATAS:                  ; loop label
         XOR AH, AH                  ; clear AH
         MOV AL, [SI]                ; set AL=[SI]

         CALL OUTDEC                 ; call the procedure OUTDEC

         MOV AH, 2                   ; set output function
         MOV DL, 20H                 ; set DL=20H
         INT 21H                     ; print a character

         INC SI                      ; set SI=SI+1
   LOOP @PRINT_DATAS              ; jump to label @PRINT_DATAS while CX!=0

        POP DX                       ; pop a value from STACK into DX
        POP CX                       ; pop a value from STACK into CX
        POP AX                       ; pop a value from STACK into AX

        RET                          ; return control to the calling procedure
 PRINT_DATAS ENDP


 ;----------------------------  BUBBLE_SORT  -------------------------------;


 BUBBLE_SORT PROC
   ; this procedure will sort the array in ascending order
   ; input : SI=offset address of the array
   ;       : BX=array size
   ; output : none

       PUSH AX                      ; push AX onto the STACK  
       PUSH BX                      ; push BX onto the STACK
       PUSH CX                      ; push CX onto the STACK
       PUSH DX                      ; push DX onto the STACK
       PUSH DI                      ; push DI onto the STACK

       MOV AX, SI                   ; set AX=SI
       MOV CX, BX                   ; set CX=BX
       DEC CX                       ; set CX=CX-1

   @OUTER_LOOP:                 ; loop label
       MOV BX, CX                   ; set BX=CX

       MOV SI, AX                   ; set SI=AX
       MOV DI, AX                   ; set DI=AX
       INC DI                       ; set DI=DI+1

   @INNER_LOOP:                  ; loop label 
       MOV DL, [SI]                ; set DL=[SI]

       CMP DL, [DI]                ; compare DL with [DI]
       JNG @SKIP_EXCHANGE          ; jump to label @SKIP_EXCHANGE if DL<[DI]

       XCHG DL, [DI]               ; set DL=[DI], [DI]=DL
       MOV [SI], DL                ; set [SI]=DL

    @SKIP_EXCHANGE:                ; jump label
       INC SI                      ; set SI=SI+1
       INC DI                      ; set DI=DI+1

       DEC BX                      ; set BX=BX-1
     JNZ @INNER_LOOP               ; jump to label @INNER_LOOP if BX!=0
   LOOP @OUTER_LOOP                ; jump to label @OUTER_LOOP while CX!=0

      POP DI                       ; pop a value from STACK into DI
      POP DX                       ; pop a value from STACK into DX
      POP CX                       ; pop a value from STACK into CX
      POP BX                       ; pop a value from STACK into BX
      POP AX                       ; pop a value from STACK into AX

   RET                             ; return control to the calling procedure
 BUBBLE_SORT ENDP


 ;--------------------------------  OUTDEC  --------------------------------;


 OUTDEC PROC
   ; this procedure will display a decimal number
   ; input : AX
   ; output : none

     PUSH BX                        ; push BX onto the STACK
     PUSH CX                        ; push CX onto the STACK
     PUSH DX                        ; push DX onto the STACK

     XOR CX, CX                     ; clear CX
     MOV BX, 10                     ; set BX=10

   @OUTPUT:                        ; loop label
     XOR DX, DX                    ; clear DX
     DIV BX                        ; divide AX by BX
     PUSH DX                        ; push DX onto the STACK
     INC CX                        ; increment CX
     OR AX, AX                      ; take OR of Ax with AX
   JNE @OUTPUT                      ; jump to label @OUTPUT if ZF=0

     MOV AH, 2                      ; set output function

   @DISPLAY:                        ; loop label
     POP DX                         ; pop a value from STACK to DX
     OR DL, 30H                     ; convert decimal to ascii code
     INT 21H                        ; print a character
     LOOP @DISPLAY                  ; jump to label @DISPLAY if CX!=0

     POP DX                         ; pop a value from STACK into DX
     POP CX                         ; pop a value from STACK into CX
     POP BX                         ; pop a value from STACK into BX

   RET                              ; return control to the calling procedure
 OUTDEC ENDP
 

 END MAIN
