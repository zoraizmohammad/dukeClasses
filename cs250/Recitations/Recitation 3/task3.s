.text
main:
    li $t0, 0
    li $t1, 11 # load immediate

_loop:
    li $v0, 1 # print an integer
    move $a0, $t0 # move $t0 to $a0
    syscall

    li $v0, 4 # print a string
    la $a0, newline
    syscall 

    addi $t0, $t0, 1 #$t0 = $t0 + 1
    beq $t0, $t1, _done #if $t0 == $t1, exit loop

    j _loop # jump to _loop
_done:  
    li $v0, 0 # exit
    jr $ra #return

.data 
newline: .asciiz "\n"