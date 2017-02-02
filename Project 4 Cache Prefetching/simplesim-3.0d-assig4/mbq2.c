#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){


	//64B cache line, 4 way, 64Sets
	//Traverse array in less than B chunks are hits
	//Traverse array in great than 64B chunkcs are misses

	int foo[1000000];
	int i;


	int step = atoi(argv[1]);
	if(step < 1000000){

		for(i = 0; i < 1000000; i+= step){
		foo[i] = 0;
		}
	}
	else{
		for(i = 0; i < 1000000; i+=step){
			foo[i] = 0;
			//random accessing 
			step = rand() % 2000;
		}


	}




	return 0;
}