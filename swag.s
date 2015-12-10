	.data
temp_0: .float 6.100000
a: .float 0.000000


	.text
main :
l.s $f0,temp_0
s.s $f0,a
li $v0,2
l.s $f12,a
syscall
li $v0,10
syscall
