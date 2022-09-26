;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
;
;
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file
            
;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                            ; make it known to linker.
;-------------------------------------------------------------------------------
            .text                           ; Assemble into program memory.
            .retain                         ; Override ELF conditional linking
                                            ; and retain current section.
            .retainrefs                     ; And retain any sections that have
                                            ; references to current section.

;-------------------------------------------------------------------------------
RESET       mov.w   #__STACK_END,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; Stop watchdog timer


;-------------------------------------------------------------------------------
; Main loop here
;-------------------------------------------------------------------------------

			clr.w	R4
			clr.w	R5
			clr.w	R6
			clr.w	R7
			clr.w	R8
			clr.w	R9
			clr.w	R10
			clr.w	R11
			clr.w	R12
			clr.w	R13
			clr.w	R14
			clr.w	R15

Lab3		mov.w 	#5, R4		;set up the initial a value in R4

Xcalc		mov.w	R4, R5		;copy the a value into R5
			call 	#ABSOL		;computer the absolute value of a in R5

Summation	mov.w 	R5, R6		;starting the upper limit with value a of the summation in R6
			call 	#FACTO		;get the factorial value of R6 and save in R6
			add.w	R6, R8
			dec		R5
			cmp.b	#0, R5
			jl		next
			jmp		Summation
next		add.w	R8, R8
			mov.w	R8, R5

			;finish Xcalcby dobling the value and adding it to accumulator R8,
			;repeat the loop with a-1, a-2 (in R5) till lower value a=0
			;save the Xcalc results in R5

Fcalc		mov.w 	R5, R7		;start F calculation
			add.w	#27, R7
			rrc.w	R7
			;finish Fcalc by adding the constant 50 and dividing by 4 (hint shift twice to the right with carry=0)

loop		jmp 	loop		;loop in place



;Absolute subroutine take a value form R5 and converts it to its absolute value
ABSOL:
			tst 	R5
			jn		twoscompl
			ret
twoscompl	inv 	R5
			inc		R5
ABSOLend	ret



;Factorial subroutine takes number n form R6 and compute/save n! in R6
;You need to replace the NOP with your actual n! calculation as given in class
;You must push/pop all registers
FACTO:
			push.w	R5
			push.w	R10
			tst		R5						; test to make sure our i isnt zero
			jz		Zero					; if it is, jump to zero where 0! = 1
			jn		Neg						; if -! = 0
			mov		R5, R10					; move i into R10 for calculation
Loop		dec 	R5						; dec i
			jz		FACTOend						; check if i = 0 if done go to end
			call	#MULT
			jmp		Loop
Zero		mov		#1, R6
			jmp		FACTOend
Neg			mov 	#0, R6
			jmp		FACTOend
FACTOend	pop.w	R10
			pop.w	R5
			ret



;The multiplier subroutine based on shift and add
;It takes R5 as the multiplier and R6 as the multiplicand
;to avoid multiplication overflow, both R5 and R6 should be limited to one byte and thus ANDed with 0X00FF.
;but due to factorial calculation, we will not mask R6 to let it grow beyond 255
MULT:
			push.w	R5;
			push.w	R7;
			push.w 	R8;
			mov.w	#8, R8		;8 bit multiplication, so we loop 8 times
			clr.w	R7			;additive accumulator should start with zero
			and.w	#0x00FF, R5	;clear upper 8 bits of multiplier
			;and.w 	#0x00FF, R6	;clear upper 8 bits of multiplicand


nextbit		rrc.w	R5			;shift multiplier bits one at a time to the carry
			jnc		twice		;if no carry skip the add
addmore		add.w	R6, R7		;add a copy of the multiplicand to the accumulator
twice		add.w	R6, R6		;multiplicand times 2, (shifted 1 bit left)
			dec.w 	R8			;dec loop counter
			jnz		nextbit		;jump to check next bit of the multiplier
			mov.w 	R7, R6		;save the result in R6

			pop.w	R8;
			pop.w	R7;
			pop.w 	R5;

MULTend		ret

;-------------------------------------------------------------------------------
; Stack Pointer definition
;-------------------------------------------------------------------------------
            .global __STACK_END
            .sect   .stack
            
;-------------------------------------------------------------------------------
; Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET
            
