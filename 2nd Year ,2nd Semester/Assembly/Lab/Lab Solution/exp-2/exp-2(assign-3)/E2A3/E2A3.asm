;===================================================================
;Description: Program of Assignment 2 Experiment 3
;Author:[ABID ALI][2019380141] 
;Date:[05/22/2021]
;===================================================================
;This is the program for experiment 2 assignment 3
;change the led lights into a nixie tube
;===================================================================
       .MODEL SMALL
       .DATA
       ;THIS IS THE PATTERN TABLE
TABLE  DB 3FH,06H,5BH,4FH                ;DISPLAYING 3FH=0,06H=1,5BH=2,4FH=3
       DB 66H,6DH,7DH,07H                
       DB 7FH,6FH,77H,7CH               
       DB 39H,5EH,79H,31H
       .CODE
       .STARTUP
       MOV DX, 46H
       MOV AL, 90H
       OUT DX, AL                        ;OUTPUT BYTE IN AL TO I/O PORT ADDRESS IN DX.
TOP:                                     ;TOP IS A LABEL AND WE ALSO THE PROCESS
       ;TODO;PORT A
       MOV DX, 40H
       IN  AL, DX
       AND AL, 0FH
       MOV BX,OFFSET TABLE               ;THIS IS THE OFFSET PART OF THE PATTERN TABLE
       XLAT
       ;TODO;PORT B                 
       MOV DX, 42H                       ;PATTEN TABLE CODE IS OUTPUTED 
       OUT DX, AL
       JMP TOP                           ;IT GOES FROM THE BOTTOM TO THE LABEL TOP ,CREATING A LOOP LIKE STRUCTURE
     .EXIT
    END                                  ;PROGRAM ENDS HERE                              