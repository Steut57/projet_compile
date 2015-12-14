	.data
temp_0: .word 3
x: .word 0
temp_1: .word 3
temp_2: .word 5
temp_3: .word 0
temp_4: .float 3.100000
z: .float 0.000000
temp_5: .float 1.500000
temp_6: .float 0.700000
temp_7: .word 0
g: .space 4
temp_9: .word 1
temp_10: .word 3
temp_11: .asciiz "lol\n"


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
l.s $f0,temp_5
l.s $f1,temp_6
div.s $f2,$f0,$f1
s.s $f2,temp_7
lw $t0,temp_7
sw $t0,z
li $v0,4
la $a0,temp_11
syscall
li $v0,1
lw $a0,x
syscall
li $v0,2
l.s $f12,z
syscall
li $v0,10
syscall
