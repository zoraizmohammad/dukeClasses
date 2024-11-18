.text

main:
    addi $sp, $sp, -4
    sw $ra, 0($sp)

    li $t0, 1
    li $t1, 2

    move $a0, $t0
    move $a1, $t1

    addi $sp, $sp, -8
    sw $t0, 0($sp)
    sw $t0, 4($sp)

    jal foo #jal -> jumps to foo, sets $ra to line 7

    lw $t0, 0($sp)
    lw $t0, 4($sp)
    addi $sp, $sp, 8

    move $t1, $v0

    li $v0, 1
    move $a0, $t1
    syscall

    lw $ra, 0 ($sp)
    addi $sp, $sp, 4
    jr $ra

foo:
    add $v0, $a0, $a1
    jr $ra 

.data 