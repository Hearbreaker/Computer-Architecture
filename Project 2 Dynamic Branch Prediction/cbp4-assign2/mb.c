#include<stdio.h>

int main(){

	int i;
	int temp, sum;
	temp = 0; sum = 0;
	for (i = 0 ; i < 1000000; i++){
		if (i%2 == 0 ) //predict correctly. TNTNTN.
			temp = 1;
		if (i%10 == 0){ //predict incorrectly because 10 bit pattern.
			temp = 0; //1 misprediction every 10 branches
		}
		if (temp == 1){ //10 bit pattern.
			sum++; //1 misprediciton every 10 branches
		}
		sum++;
	}

	printf("temp is: %d", temp);
	printf("sum is : %d", sum);
	
	
	return 0;

}

//Used -O2 to compile
/*
main:
.L2:					 	//First if statement. Comes here if statement taken. 
	xorl	%esi, %esi
	cmpl	%eax, %ecx
	je	.L3
.L5:						//Third if statement. Comes here if statement taken. 
	addl	$1, %ebx
	movl	$1, %esi
.L3:					
	addl	$1, %ecx
	addl	$1, %ebx
	cmpl	$1000000, %ecx
	je	.L16 				//exits loop. Only mispredict once when it exits. 
.L4:  						//Beginning of for loop	
	movl	%ecx, %eax
	imull	%edi
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$2, %edx
	subl	%eax, %edx
	leal	(%rdx,%rdx,4), %eax
	addl	%eax, %eax
	testb	$1, %cl
	je	.L2					//first if statement
	cmpl	%eax, %ecx
	je	.L6					//second if statement
	cmpl	$1, %esi
	je	.L5					//third if statement
	addl	$1, %ecx
	addl	$1, %ebx
	cmpl	$1000000, %ecx
	jne	.L4
.L16:						//outside of for loop. 
	movl	$.LC0, %edi
	xorl	%eax, %eax
	call	printf
	movl	%ebx, %esi
	movl	$.LC1, %edi
	xorl	%eax, %eax
	call	printf
	xorl	%eax, %eax
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L6:					//second if statement. Comes here if statement taken. 
	.cfi_restore_state
	xorl	%esi, %esi
	jmp	.L3
*/
