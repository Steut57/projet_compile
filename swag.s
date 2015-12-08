	.data
temp_0: .word 5
temp_1: .word 6
temp_2: .word 0
temp_3: .asciiz "calcul 10 / 4 : \n"
temp_4: .asciiz "resultat donne : "
temp_5: .word 10
temp_6: .word 4
temp_7: .word 0
temp_8: .asciiz "\n"
temp_9: .asciiz "calcul 5 - 7 : \n"
temp_10: .asciiz "resultat donne : "
temp_11: .word 5
temp_12: .word 7
temp_13: .word 0
temp_14: .asciiz "\n"


	.text
main :
lw $t0,temp_0
lw $t1,temp_1
add $t2,$t0,$t1
sw $t2,temp_2
li $v0,4
la $a0,temp_3
syscall
li $v0,4
la $a0,temp_4
syscall
lw $t0,temp_5
lw $t1,temp_6
div $t2,$t0,$t1
sw $t2,temp_7
li $v0,1
move $a0,$t2
syscall
li $v0,4
la $a0,temp_8
syscall
li $v0,4
la $a0,temp_9
syscall
li $v0,4
la $a0,temp_10
syscall
lw $t0,temp_11
lw $t1,temp_12
sub $t2,$t0,$t1
sw $t2,temp_13
li $v0,1
move $a0,$t2
syscall
li $v0,4
la $a0,temp_14
syscall
li $v0,10
syscall
