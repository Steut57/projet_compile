	.data
temp_0: .word 5
temp_1: .word 6
temp_2: .word 0
temp_3: .asciiz "toto \n"
temp_4: .word 5
temp_5: .word 6
temp_6: .word 0
temp_7: .word 5
temp_8: .word 30
temp_9: .word 0


	.text
main :
lw $t0,temp_0
lw $t1,temp_1
add $t2,$t0,$t1
sw $t2,temp_2
li $v0,4
la $a0,temp_3
syscall
lw $t0,temp_4
lw $t1,temp_5
add $t2,$t0,$t1
sw $t2,temp_6
li $v0,1
move $a0,$t2
syscall
lw $t0,temp_7
lw $t1,temp_8
mul $t2,$t0,$t1
sw $t2,temp_9
li $v0,1
move $a0,$t2
syscall
li $v0,10
syscall
