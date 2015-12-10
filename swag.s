	.data
temp_0: .float 6.000000
b: .float 0.000000
temp_1: .asciiz "valeur de b : "


	.text
main :
la $a1,temp_O
l.s $f1,($a1)
sw $f0,b
li $v0,4
la $a0,temp_1
syscall
li $v0,2
l.s $f12,b
syscall
li $v0,10
syscall
