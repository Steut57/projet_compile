	.data
a: .space 8
temp_1: .word 1
temp_2: .word 0
temp_3: .word 2
temp_4: .word 1
temp_5: .space 0
temp_6: .asciiz "\n"


	.text
main :
#----------ARRAY_AFFECT-----------
lw $t0,temp_1
la $t1,a
lw $t2,temp_2
li $t3,4
mult $t3,$t2
mflo $t4
add $t5,$t1,$t4
sw $t0,($t5)
#---------FIN ARRAY_AFFECT----------
#----------ARRAY_AFFECT-----------
lw $t0,temp_3
la $t1,a
lw $t2,temp_4
li $t3,4
mult $t3,$t2
mflo $t4
add $t5,$t1,$t4
sw $t0,($t5)
#---------FIN ARRAY_AFFECT----------
#----------PRINTTAB-----------
li $v0,4
la $a0,temp_6
syscall
li $v0,10
syscall
