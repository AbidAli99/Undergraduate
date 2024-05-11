;////////////////////////////////////////////////////////////////////////////////////////////////
;This program is an example to show how to interface ADC0809 in the way of virtual ports. 
;	1) The channel selection pin ADDA,B,C of ADC0809 is connected to A0 A1 and A2
;	and the address latch pin(ALE) is activated by an output of 
;	system address decoder(Y7, named as AD_S), together with IOWR signal.
;	As a result, the execution of a OUT instruction that visit an address whithin the
;	range of Y7, will force ADC0809 to lock up an channel.
;	2) The start convert pin of ADC0809 is also connected to AD_S. So, once the channel is 
;	locked up, the convert will begin.
;	3) The output signal End Of Convert(EOC) is connected to 8259.PortA.BIT0;
;	4) The input signal Output Enable(OUT EN) is connected to the system address decoder
;	output Y7, together with IORD signal. 
;	As a result, the execution of an IN instruction that visit an address within the 
;	range of Y7, will enable the convert result output of a ADC0809 channel
;
;	The following program will sample a signal through channel 3 of a ADC0809,
;	and save it into variable DATA_SAMPLE_VALUE in the DATA segment.

.MODEL SMALL
.STACK 32
.DATA
		PORT_8255 EQU 0D100H   ;8255A chip selection port addr 
  		CTRLWORD_8255 EQU 10010000B;8255A control word: PORTA input, PORTB output
 		DATA_SAMPLE_VALUE	DW 0FFH	;variable to hold a sample value
;place data definitions here

.CODE
MAIN	PROC FAR	;this is the program entry point
		MOV AX, @DATA	;load the data segment address
		MOV DS, AX		;assign value to data segment register
	;TODO1: Program 8255A	
		MOV DX,PORT_8255+3  	;PORT ADDR = config register
   		MOV AL,CTRLWORD_8255
   		OUT DX,AL
	;TODO3: START SAMPLE
		MOV AX, 00H
		MOV AL, 01H		;OUTPUT A DUMMY VALUE. THE THING THAT MATTERS IS THE ADDRESS
		MOV DX, PORT_ADCHANNELS+3	;sammple from CH3
		OUT DX, AL
	;TODO4: TEST EOC
	TESTEOC:
		MOV DX, PORT_8255		;read ADC.EOC from PORTA.BIT0
		IN AL, DX
		AND AL, 01H				;mask off additional bits
		JZ TESTEOC	;
	;TODO5: READ SAMPLE RESULT
		MOV DX, PORT_ADCHANNELS+3
		IN AL, DX 
	;TODO6: SAVE RESULT INTO VARIABLE
		MOV DATA_SAMPLE_VALUE, AX
; RETURN TO DOS
	MOV AX, 4C00H
	INT 21H
MAIN ENDP
END MAIN

;;==============================================================
;NAME: sub procedure DO_ADSample
;FUNCTION:
;	start AD convert; test EOC via 8255.portA.BIT0; 
;PARAMETERS:
;	AX: [OUT] sample value
;IN USE REGISTERS:
;	DX: for I/O instructions
DO_ADSample	PROC NEAR
		PUSH DX
	DOSAMPLE:
	;TODO1: START SAMPLE
		MOV AL, 01H		;OUTPUT A DUMMY VALUE. THE THING THAT MATTERS IS THE ADDRESS
		MOV DX, PORT_ADCHANNELS+3	;sammple from CH3
		OUT DX, AL
	;TODO2: TEST EOC
	TESTEOC:
		MOV DX, PORT_8255		;read ADC.EOC from PORTA.BIT0
		IN AL, DX
		AND AL, 01H				;mask off additional bits
		JZ TESTEOC	;
	;TODO3: READ SAMPLE RESULT
		MOV DX, PORT_ADCHANNELS+3
		IN AL, DX 
		POP DX
		RET
DO_ADSample ENDP