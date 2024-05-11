;========================================================
;Description: Program of Assignment 3 Experiment1
;Author:[name][student ID] 
;Date:[Date]
;========================================================
;view 8254 output
;LED1 displays out0 of timer0
;LED2 displays out1 of timer1, and LED1 should light for 1s and off for 1s

.MODEL SMALL
.STACK 32
.DATA   
	IOS4 EQU 048H;
.CODE
MAIN PROC FAR
	TODO1: program timer0, both cmd and initial value
	
	TODO1: program timer1, both cmd and initial value
	
	MOV AX, 4C00H
	INT 21H
MAIN ENDP         

END MAIN