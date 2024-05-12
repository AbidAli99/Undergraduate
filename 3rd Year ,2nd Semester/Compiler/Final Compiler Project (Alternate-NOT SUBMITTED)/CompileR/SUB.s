	.text

#----------FUNCTION sub_fun----------
	.globl	sub_fun
	.ent	sub_fun
	.type	sub_fun, @function
sub_fun:
#ALLOCATING STACK
	addiu	$sp, $sp,-86
	sw	$ra,82($sp)
	sw	$fp,78($sp)
	move	$fp, $sp
#FUNCTION BODY
	li	$2, 10
#local var counter = 1
	sw	$2, 16($fp)	#Storing variable a
	li	$2, 5
#local var counter = 2
	sw	$2, 20($fp)	#Storing variable b
#locked: 8
	lw	$2, 16($fp)
	nop
	lw	$8, 20($fp)
	nop
	sub	$2, $2, $8	#Sub Operator
#unlocked: 8
	b sub_fun_function_end_1	#Return statement
sub_fun_function_end_1:
#DEALLOCATING STACK
	move	$sp, $fp
	lw	$ra,82($sp)
	nop
	lw	$fp,78($sp)
	nop
	addiu	$sp, $sp,86
	j	$ra
	nop

	.end	sub_fun

