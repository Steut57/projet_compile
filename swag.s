	.data
g: .space 16
temp_1: .word 4
temp_2: .word 2
temp_3: .word 2
temp_4: .word 1
temp_5: .word 5
temp_6: .word 3
temp_7: .word 1
temp_8: .word 0
f: .word 0
y: .word 0
x: .word 0
z: .word 0
temp_9: .word 0
temp_10: .word 1
temp_11: .word 2
temp_12: .word 3
temp_13: .asciiz "valeur de f (1 normalement) "
temp_14: .asciiz "\nvaleur de x (2 normalement) "
temp_15: .asciiz "\nvaleur de y (4 normalement) "
temp_16: .asciiz "\nvaleur de z (5 normalement) "
temp_17: .asciiz "\n"


	.text
main :
#----------ARRAY_AFFECT-----------
lw $t0,temp_1
la $t1,g
lw $t2,temp_2
li $t3,4
mult $t3,$t2
mflo $t4
add $t5,$t1,$t4
sw $t0,($t5)
#---------FIN ARRAY_AFFECT----------
#----------ARRAY_AFFECT-----------
lw $t0,temp_3
la $t1,g
lw $t2,temp_4
li $t3,4
mult $t3,$t2
mflo $t4
add $t5,$t1,$t4
sw $t0,($t5)
#---------FIN ARRAY_AFFECT----------
#----------ARRAY_AFFECT-----------
lw $t0,temp_5
la $t1,g
lw $t2,temp_6
li $t3,4
mult $t3,$t2
mflo $t4
add $t5,$t1,$t4
sw $t0,($t5)
#---------FIN ARRAY_AFFECT----------
#----------ARRAY_AFFECT-----------
lw $t0,temp_7
la $t1,g
lw $t2,temp_8
li $t3,4
mult $t3,$t2
mflo $t4
add $t5,$t1,$t4
sw $t0,($t5)
#---------FIN ARRAY_AFFECT----------
#----------ARRAY_ACCESS-----------
lw $t2,temp_9
la $t1,g
li $t3,4
mult $t3,$t2
mflo $t4
add $t5,$t1,$t4
lw $t0,($t5)
sw $t0,f
#---------FIN ARRAY_ACCESS----------
#----------ARRAY_ACCESS-----------
lw $t2,temp_10
la $t1,g
li $t3,4
mult $t3,$t2
mflo $t4
add $t5,$t1,$t4
lw $t0,($t5)
sw $t0,x
#---------FIN ARRAY_ACCESS----------
#----------ARRAY_ACCESS-----------
lw $t2,temp_11
la $t1,g
li $t3,4
mult $t3,$t2
mflo $t4
add $t5,$t1,$t4
lw $t0,($t5)
sw $t0,y
#---------FIN ARRAY_ACCESS----------
#----------ARRAY_ACCESS-----------
lw $t2,temp_12
la $t1,g
li $t3,4
mult $t3,$t2
mflo $t4
add $t5,$t1,$t4
lw $t0,($t5)
sw $t0,z
#---------FIN ARRAY_ACCESS----------
li $v0,4
la $a0,temp_13
syscall
li $v0,1
lw $a0,f
syscall
li $v0,4
la $a0,temp_14
syscall
li $v0,1
lw $a0,x
syscall
li $v0,4
la $a0,temp_15
syscall
li $v0,1
lw $a0,y
syscall
li $v0,4
la $a0,temp_16
syscall
li $v0,1
lw $a0,z
syscall
li $v0,4
la $a0,temp_17
syscall
li $v0,10
syscall
