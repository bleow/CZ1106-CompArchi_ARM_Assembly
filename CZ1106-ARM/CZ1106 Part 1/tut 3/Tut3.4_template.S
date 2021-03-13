N1		DCD		0x3
M1		DCD		0xFFFFFFFF,0X111
M2		DCD		0x2,0x600
M3		DCD		0x222,0x100
		
START	MOV		SP, #0xFFFFFFFC


		

		
		END
		
SubA		
		
		
		STR		R4,[SP]
		
		
		
		
Loop		
		
		
		
		
		
		
		
		
		
		
		BEQ		Done
		ADD		R4,R4,#8
		B		Loop
Done		LDR		R5,[SP,#4]
		LDR		R6,[SP,#8]
		STR		R5,[R4]
		STR		R6,[R4,#4]
		
		
		MOV		PC,LR