NUMX		DCD		0x4
NUMY		DCD		0x3
ANS		FILL		4
Start	MOV		SP,#0xFFFFFFFC ;initialise stack pointer
		MOV		R0,#0x100
		LDR		R1,[R0]
		STR		R1,[SP,#-4]! ;move NumX onto stack
		ADD		R0,R0,#4
		LDR		R1,[R0]
		STR		R1,[SP,#-4]! ;move NumY onto stack
		ADD		R0,R0,#4
		STR		R0,[SP,#-4]! ;move address of Ans onto stack
		BL		MySub
		LDR		R0,[SP,#-4]
		ADD		SP, SP, #12 ;remove everything you've added in main: NumX, NumY, [Ans]
		
		
		end
MySub	STMFD	SP!, {R0-R3} ;(s1) save registers R0, R1, R2, R3
		;R3
		;R2
		;R1
		;R0
		;[Ans]
		;NumY
		;NumX
		LDR		R0, [SP, #24]  ;(s2)	retrieve NumX from stack
		LDR		R1, [SP, #20]  ;(s3)	retrieve NumY from stack
		
		;compute	NumX*NumY using successive addition
		;add		R0 to R3 for R1 times
		MOV		R3, #0
loop		ADD		R3, R3, R0
		SUBS		R1, R1, #1
		BNE		loop
		
		;(s4a)	move the result directly to
		;(s4b)	the memory variable Ans
		LDR		R2, [SP, #16]
		STR		R3, [R2]
		
		;restore	saved registers
		LDMFD	SP!, {R0-R3}
		
		Mov		PC,LR ;(s6)	return to calling program
		
