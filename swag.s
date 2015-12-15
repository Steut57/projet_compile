	.data
cst_0: .word 6
cst_1: .word 2
temp_2: .word 0
cst_2: .word 2
x: .word 0
cst_3: .word 3
cst_4: .word 0
cst_5: .word 5
y: .word 0
cst_6: .word 5
cst_7: .word 2
temp_8: .word 0
cst_8: .word 2
z: .word 0
temp_10: .word 0
temp_12: .word 0


	.text
main :
lw $t0,cst_2
sw $t0,x
lw $t0,x
lw $t1,cst_3
add $t2,$t0,$t1
sw $t2,cst_4
lw $t0,cst_4
sw $t0,x
lw $t0,cst_5
sw $t0,y
lw $t0,cst_8
sw $t0,z
li $v0,10
syscall
