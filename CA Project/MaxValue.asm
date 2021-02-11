.data
    msg: .asciiz "\nInserire numero: "
    out: .asciiz "\nMax: "
    out2: .asciiz "\tMin: "
.text
.globl main
main:
    subiu  $sp, $sp, 20
	
    la $a0, ($sp)	
    jal riempi_array
	
    la $a0, ($sp)	
    jal trova_max_min
    move $s0, $v0
    move $s1, $v1
	
    li $v0, 4	
    la $a0, out
    syscall
	
    li $v0, 1	
    move $a0, $s1
    syscall
	
    li $v0, 4	
    la $a0, out2
    syscall
	
    li $v0, 1	
    move $a0, $s0
    syscall
	
    li $v0, 10	
    syscall
	
	riempi_array:
		li $t0, 0 	# i = 0
		move $t1, $a0	# t1 = stack pointer
		loop:
			beq $t0, 5, exit	# while i < 5 -> loop
			
			li $v0, 4	# prints
			la $a0, msg
			syscall
			
			li $v0, 5	# reads
			syscall
			
			sw $v0, ($t1)	# saves read number
			
			addi $t0, $t0, 1	# i++
			addiu $t1, $t1, 4	# sp++
			j loop
		exit:
			jr $ra		
		
	trova_max_min:
		li $t0, 0		#i = 0
		move $t1, $a0		#t1 = sp
		
		lw $t3, 0($a0)	# t3 = max = arr[0]
			max:
				beq $t0, 5, exit1
				
				lw $t4, 4($t1) 	#check max
				
				bgt $t3, $t4, notmax
				move $t3, $t4	#max = read value
				
				addi $t0, $t0, 1
				addiu $t1, $t1, 4
				
				j max
				
				notmax:
					addi $t0, $t0, 1
					addiu $t1, $t1, 4
					j max
				exit1:
					move $v1, $t3
				
				min:
				addiu $t1, $t1, -20     # starts from 0' element of the array
				lw $t2, 0($t1)		# t2 = min = arr[0]
				li $t0, 0               # i = 0
	
					loop1:
					beq $t0, 5, final
				
					lw $t5, 4($t1)         # load arr[i+1] in t5
				
					blt $t2, $t5, notmin   #check min
					move $t2, $t5	#min = read value
				
					addi $t0, $t0, 1
					addiu $t1, $t1, 4
				
					j loop1
					
				notmin:
					addi $t0, $t0, 1
					addiu $t1, $t1, 4
					j loop1
				
				final:
					move $v0, $t2
					jr $ra