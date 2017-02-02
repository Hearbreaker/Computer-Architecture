#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){


	//64B cache line, 4 way, 64Sets
	//Traverse array in less than B chunks are hits
	//Traverse array in great than 64B chunkcs are misses
	//char is 1 byte

	char foo[1000000];
	int i;
	int step = atoi(argv[1]);
	int pattern[10];

	for(i = 0; i < 10; i++){
		pattern[i] = rand() % 2200 + 1;
	}


	if(step < 1000000 && step > 0){ //predict stride correctly
			printf("step\n");
		for(i = 0; i < 1000000; i+=step){
			foo[i] = 0;
		}
	}
	else if(step > 1000000){ //predict pattern correctly
		printf("pattern\n");
		for(i = 0; i < 1000000; i+=pattern[i%10]){
			foo[i] = 0;
		}
	}
	else{ //can't predict randomly as well
		printf("random\n");

		for(i=0; i < 1000000; i+=step){
			foo[i] = 0;
			//random accessing 
			step += rand() % 2000;
		}
		
	}
	


	return 0;
}