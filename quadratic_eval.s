#
# Code to evaluate a quadratic
#

	.data
X:	.word 3
A:	.word 7
B:	.word 5
C:	.word 4	
ans:	.asciiz "Answer = "
nl:	.asciiz "\n"

	.text
	
main:
	lw $t0, X
	lw $t1, A
	lw $t2, B
	lw $t3, C

	# mul $t0, $t0, $t4  # X**2 nothing has been initialized in the t4 temporary register, we're just multiplying x by itslef.
	mul $t4, $t0, $t0  # X**2
	# mul $t1, $t4, $t4  # A*X**2  we are multiplying A by x squared. x squared is currently stored in 
	# in t4 and a is stored in t1.  
	# so the parameters would have to be t1 and t4, not t4 twice. 
	mul $t1, $t1, $t4  # A*X**2
	
	
	# mul $t0, $t2, $t5   # B*X nothing is being stored in t5 yet. we are multiplying b by x which 
	# means we will need to use t2 and t0 as parameters
	mul $t2, $t2, $t0   # B*X
	
	#add $t4, $t5, $t4  # A*X**2 + B*X # ax*x is stored is stored in t1, and bx is stored in t2 
	# so the destination could be t0 and the operands could be t0 and t1.
	add $t1, $t1, $t2  # A*X**2 + B*X
	
	# add $t3, $t4, $t4  # A*X**2 + B*X + C 
	# A*X**2 + B*X is stored in t1 and c is stored in t3. so the parameters should be t1 and t3

	add $t3, $t1, $t3  # A*X**2 + B*X + C
	
	la $a0, ans        # print a string
	li $v0, 4			# system call code for print_str
	syscall

	move $a0, $t3      # now the result
	li $v0, 1			#system call code for print_int
	syscall

	la $a0, nl         # and a newline
	li $v0, 4			# nl is a string so we are doing the system call for a new string. 
	syscall

	li $v0, 10         # g'bye 
						# 10 is the system call for the program to end. 
	syscall

#	.data   the data needs to be initialized above the program in order for the program to be able to use it. 
         #X:	.word 3
                 #A:	.word 7
#B:	.word 5
#C:	.word 4
#ans:	.asciiz "Answer = "
#nl:	.asciiz "\n"
	
