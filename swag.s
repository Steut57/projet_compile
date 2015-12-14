	.data
x: .word 0
temp_0: .word 3
y: .word 0
z: .word 0


	.text
main :
lw $t0,temp_0
sw $t0,x
lw $t0,x
sw $t0,y
li $v0,1
lw $a0,x
syscall
li $v0,10
syscall
