		MOV		R0,#9
		STMFD	SP!,{R0}
		BL		Fib
		END
		
Fib		STMFD	SP!,{R4-R6,LR}	;Store regs to stack
		LDR		R4 ,[SP,#16]		;Read Value of n
		CMP		R4 ,#1			;Compare with 1 (if n==1)
		MOVEQ	R12,#0			;Assign result with 0
		CMP		R4 ,#2			;Compare with 2 (if n==2)
		MOVEQ	R12,#1			; Assign result with 1
		BLE		Done				; if n less than equal 2 finish
		SUB		R5,R4,#1			; Get n-1
		STMFD	SP!,{R5}			;Push n-1 to stack
		BL		Fib				; calculate Fib(n-1)
		LDMFD	SP!,{R5}			; Pop from stack
		MOV		R6,R12			;Save result in temp register
		SUB		R5,R4,#2			; Get n-2
		STMFD	SP!,{R5}			;Push n-2 to stack
		BL		Fib				; calculate Fib (n-2)
		LDMFD	SP!,{R5}			; Pop from stack
		ADD		R12,R12,R6		; Calculate Fib(n-1) + Fib(n-2)
Done		LDMFD	SP!,{R4-R6,LR}		; Restore registers
		MOV		PC, LR			; same as bx lr
