# code section
.text
# ======================== start of function: main
# int main() {
main:
# int i=1;
li $t0, 1

# while (i<=10) {
li $t7, 10
_loop:

# if t0 is above 10, branch out of loop
bgt $t0, $t7, _endloop

# int sq = i*i;
# compute t0*t0 and put result in t1
mul $t1, $t0, $t0 #compute t0*t0 and put result in t1

# printf("%d %d\n",i,sq); # we’ll do this in four stages
# (print i)
li $v0, 1 # load the print integer syscall code into $v0
move $a0, $t0 # move the value of i into $a0
syscall # print i

# (print space)
li $v0, 4 # load the print string syscall code into $v0
la $a0, str_space # load the ASCII code for space into $a0
syscall # print space

# (print sq)
li $v0, 4 # load the print integer syscall code into $v0
la $a0, str_newline # load the ASCII code for newline into $a0
syscall # print newline

#i++;
#increment t0
addi $t0, $t0, 1

#} //end of lop
# branch to top of the loop unconditionaly
j _loop

_endloop:
li $v0, 0
jr $ra


.data
str_space: .asciiz " "
str_newline: .asciiz "\n"
