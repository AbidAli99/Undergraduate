;Two sets of ASCII data have come in from the keyboard. Write and run a program to:
;1. Convert from ASCII to packed BCD.
;2. Add the multibyte packed BCD and save it.
;3. Convert the packed BCD result to ASCII.

;TITLE	PROG3-6 (EXE) ASCII to BCD conversion and addition
;page	60,132
.MODEL	SMALL
.STACK	64
;---------------------------------------
		.DATA
DATA1_ASC	DB	'0649147816'
		ORG	0010H
DATA2_ASC	DB	'0072687188'
		ORG	0020H
DATA3_BCD	DB	5 DUP(?)
		ORG	0028H
DATA4_BCD	DB	5 DUP(?)
		ORG 0030H
DATA5_ADD	DB	5 DUP(?)
		ORG	0040H
DATA6_ASC	DB	10 DUP(?)
;---------------------------------------
		.CODE
MAIN	PROC	FAR
		MOV	AX, @DATA
		MOV	DS, AX
		;================================================================
		MOV	BX, OFFSET DATA1_ASC
		MOV DI, OFFSET DATA3_BCD
		MOV	CX, 10				;CX holds number of bytes to convert
		CALL CONV_BCD			;CALL sub procedure to do conversion
		MOV	BX, OFFSET DATA2_ASC
		MOV DI, OFFSET DATA4_BCD
		MOV CX, 10
		CALL CONV_BCD
		CALL BCD_ADD			;CALL sub procedure todo BCD addition
		MOV	SI, OFFSET DATA5_ADD
		MOV	DI, OFFSET DATA6_ASC
		MOV CX, 05
		CALL CONV_ASC			;CALL sub procedure to convert result to ASCII
		;================================================================
		MOV	AH,  4CH		
		INT	21H					;go back to dos
MAIN	ENDP
;---------------------------------------
;THIS subroutine converts ASCII to packed BCD
CONV_BCD	PROC
AGAIN:	MOV	AX, [BX]			;here, BX=pointer for ASCII data
		XCHG AH, AL
		AND	AX, 0F0FH
		PUSH CX
		MOV CL,4
		SHL AH, CL
		OR	AL, AH
		MOV	[DI], AL			;DI=POINTER FOR BCD DATA
		ADD	BX, 2				;point t next 2 ASCII bytes
		INC DI					;point to next BCD data
		POP CX				
		LOOP AGAIN
		RET
CONV_BCD ENDP
;---------------------------------------
;THIS SUBROUTINE ADDS TWO MULTIBYTE PACKED BCD OPERANDS
BCD_ADD PROC
		MOV	BX, OFFSET DATA3_BCD
		MOV	DI, OFFSET DATA4_BCD
		MOV	SI, OFFSET DATA5_ADD
		MOV	CX, 05
		CLC
		;DO BCD ADDITION FOR THE LOWER SIDE
BACK:	MOV	AL, [BX]+4			;GET NEXT BYTE OF OPERAND1
		ADC	AL, [DI]+4			;ADD NEXT BYTE OF OPERAND2
		DAA						;CORRECT FOR BCD ADDITION
		MOV	[SI]+4, AL
		DEC	BX
		DEC	DI
		DEC	SI
		LOOP BACK
		RET
BCD_ADD ENDP
;---------------------------------------
;THIS SUBROUTINE CONVERTS FROM PACKED BCD TO ASCII
CONV_ASC	PROC
AGAIN2:	MOV	AL, [SI]			;SI=POINTER FOR BCD DATA
		MOV	AH, AL				;DUPLICATE TO UNPACK
		AND	AX, 0F00FH			;UNPACK
		PUSH CX
		MOV	CL, 04
		SHR	AH, CL
		OR	AX, 3030H			;CONVERT UNPACKED BCD TO ASCII
		XCHG AH, AL
		MOV	[DI], AX
		INC	SI
		ADD	DI, 2				;POINT TO NEXT ASCII DATA
		POP CX
		LOOP AGAIN2
		RET
CONV_ASC ENDP
;---------------------------------------
		END MAIN		