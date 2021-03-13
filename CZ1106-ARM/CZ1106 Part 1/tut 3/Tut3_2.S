NUMX		DCD		0x4
NUMY		DCD		0x3
ANS		FILL		4
Start	MOV		SP,#0xFFFFFFFC
		MOV		R0,#0x100
		LDR		R1,[R0]
		STR		R1,[SP,#-4]!
		ADD		R0,R0,#4
		LDR		R1,[R0]
		STR		R1,[SP,#-4]!
		ADD		R0,R0,#4
		STR		R0,[SP,#-4]!
		BL		MySub
		LDR		R0,[SP,#-4]
		
		
		end
MySub
		
		
		
		Mov		PC,LR
