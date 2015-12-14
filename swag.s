	.data
temp_0: .word 3
x: .word 0
temp_1: .word 3
temp_2: .word 5
temp_3: .word 0
temp_4: .float 8.410000
z: .float 0.000000
temp_5: .asciiz "lol\n"


	.text
main :
lw $t0,temp_0
sw $t0,x
lw $t0,temp_1
lw $t1,temp_2
add $t2,$t0,$t1
sw $t2,temp_3
lw $t0,temp_3
sw $t0,x
l.s $f0,temp_4
s.s $f0,z
li $v0,4
la $a0,temp_5
syscall
li $v0,1
lw $a0,x
syscall
li $v0,2
l.s $f12,z
syscall
li $v0,10
syscall
