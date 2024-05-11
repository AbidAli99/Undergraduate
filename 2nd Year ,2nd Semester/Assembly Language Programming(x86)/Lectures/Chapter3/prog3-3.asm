;TITLE	PROG3-3 (EXE) SMP example. Find the highest score in the table
;page	60,132
.MODEL	SMALL
.STACK	64
;---------------------------------------
		.DATA
;		ORG 0000
GRADES	DB	69,87,96,45,75		;45H, 57H, 60H, 2DH, 4BH
;		ORG	0008
HIGHEST	DB	?
;---------------------------------------
		.CODE
MAIN	PROC	FAR
		MOV	AX, @DATA
		MOV	DS, AX
		;================================================================
		MOV	CX, 5
		MOV	BX, OFFSET GRADES
		SUB	AL, AL				;clear AL, to hold the highest grade found so far
AGAIN:	CMP	AL, [BX]			;compare next grade to highest
		JA	NEXT				;jump if AL still highest
		MOV	AL, [BX]			;else AL holds new highest
NEXT:	INC	BX					;point to next grade
		LOOP AGAIN				;continue search
		MOV	HIGHEST, AL			;store shghest grade
		;================================================================
		MOV	AH,  4CH		
		INT	21H					;go back to dos
MAIN	ENDP
		END	MAIN		