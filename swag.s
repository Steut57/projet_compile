	.data
temp_0: .asciiz "calcul 10 / 4 : \n"
temp_1: .asciiz "resultat donne : "
temp_2: .word 10
temp_3: .word 4
temp_4: .word 0
temp_5: .asciiz "\n"
temp_6: .word 5
a: .word 0
temp_7: .asciiz "valeur de a : "
temp_8: .asciiz "\n"


	.text
main :
li $v0,4
la $a0,temp_0
syscall
li $v0,4
la $a0,temp_1
syscall
lw $t0,temp_2
lw $t1,temp_3
div $t2,$t0,$t1
sw $t2,temp_4
li $v0,1
lw $a0,temp_4
syscall
li $v0,4
la $a0,temp_5
syscall
lw $t0,temp_6
sw $t0,a
li $v0,4
la $a0,temp_7
syscall
li $v0,1
lw $a0,a
syscall
li $v0,4
la $a0,temp_8
syscall
li $v0,10
syscall
