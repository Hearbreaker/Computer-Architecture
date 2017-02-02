#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,temp,sum, q1, q2;
	q1 = 0; q2 = 0; temp = 0; sum = 0;
	
	for(i=0; i < 10000; i++){
		q1=q1+2; 
		q2=q2+q1; //double cycle stall
		temp = temp+4; 
		sum = sum+q2; //single cycle stall
		sum= temp+sum; //double cycle stall
	}
	
	printf("temp is: %d", temp);
	printf("sum is: %d", sum);
	printf("q1 is: %d", q1);
	printf("q2 is: %d", q2);
		
	return 0;
}

//We found double cycle stalls of ~30,000 and single cycle stalls of ~10,000 which match our microbenchmark and assembly code.
/*

	move	$17,$0  	//initialize variables. 
	move	$18,$0
	move	$5,$0
	move	$16,$0
	li	$2,0x0000270f		
$L25:				//loop begins here
	addu	$17,$17,2
	addu	$18,$18,$17	//double cycle stall, r17
	addu	$5,$5,4
	addu	$16,$16,$18	//single cycle stall, r18
	addu	$16,$16,$5	//double cyle stall, r16
	subu	$2,$2,1
	bgez	$2,$L25		//double cycle stall, r2. From the loop.
	la	$4,$LC0
*/
