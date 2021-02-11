.data 

m1: .asciiz " **** Welcome to C Scientific Calculator **** \n"
m2: .asciiz " Please select one of the below options\n"
m3: .asciiz " Enter 1  for Subtraction\n"
m4: .asciiz " Enter 2 symbol for Division \n"
m5: .asciiz " Enter 0 to exit the program \n"
m6: .asciiz " your choice "
m7:.asciiz"done\n" 
msg1: .asciiz "\Enter the first number: "
msg2: .asciiz "Enter the second number: "
result: .asciiz "The result is: "
 
 .text 
 
 main :
 
       li $t0 ,0
       li $t1 , 1
       li $t2 , 2
         
      jal  displayOperations
      
      move $t4 , $v0 
      
     beq $t4 ,$t0 , done
     
     beq $t4 , $t1 , subtraction
     
     beq $t4 , $t2 , division 
     
   
 
 
 displayOperations:
     li $v0,4 
     la $a0,m1
     syscall 
    li $v0,4 
     la $a0,m2
     syscall
     li $v0,4 
     la $a0,m3
     syscall 
     li $v0,4 
     la $a0,m4
     syscall 
      li $v0,4 
     la $a0,m5
     syscall 
     li $v0,4 
    la $a0,m6
    syscall
   # get ch.num
     li $v0,5
    syscall
     
 
 
 
   subtraction :
    # message to enter first number  
   li $v0,4 
   la $a0,msg1
  syscall
 # get f.num 
   li $v0,5
   syscall
 # store f.num in t1 
   move $t1,$v0

 # message to enter second number 
   li $v0,4 
   la $a0,msg2
   syscall
 # get s.num
   li $v0,5
   syscall
 # store s.num in t2
  move $t2,$v0
 # t3 = t1 - t2
   sub $t3,$t1,$t2

 # message result 
   li $v0,4
  la $a0,result 
   syscall

 # show Subtraction result
     li $v0,1
    move $a0,$t3
    syscall 
     li $v0,10
     syscall
 
 
 
 
  division : 
 # message to enter first number  
li $v0,4 
la $a0,msg1
syscall
 # get f.num 
li $v0,5
syscall
 # store f.num in t1 
move $t1,$v0

 # message to enter second number 
li $v0,4 
la $a0,msg2
syscall
 # get s.num
li $v0,5
syscall
 # store s.num in t2
move $t2,$v0
 # t3 = t1 \ t2
div $t3,$t1,$t2

 # message result 
li $v0,4
la $a0,result 
syscall

 # show division result
li $v0,1
move $a0,$t3
syscall

 # program is done 
li $v0,10
syscall
  li $v0,10
    syscall
    
    done :
     li $v0,4 
     la $a0,m7
     syscall 
      li $v0,10
    syscall
     