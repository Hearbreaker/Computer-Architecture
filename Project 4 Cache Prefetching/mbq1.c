#include <stdio.h>

int main(int argc, char *argv[]){


	//64B cache line, 4 way, 64Sets
	//Traverse array in less than B chunks are hits
	//Traverse array in great than 64B chunkcs are misses
	//char is 1 byte

	char foo[1000000];
	int i;

	int step = atoi(argv[1]);
	for(i = 0; i < 1000000; i+= step){
		foo[i] = 0;
	}


	return 0;
}