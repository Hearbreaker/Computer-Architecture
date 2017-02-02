#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {

	// Config: 64 sets in cache, 2-way, 64 bytes per blk
	
	int stride = atoi(argv[1]);
	
	int total_array_size = 100000000;
	char array[total_array_size];
	int i;

	if(stride != 0){	//	for any stride value, the stride prefetcher would have 0.0% miss rate
		for (i = 0; i < total_array_size; i+=stride){
			array[i]++;
		}
		return 0;
	}
	else{	// for random data access pattern, stride prefetcher would not work very well
		for (i = 0; i < total_array_size; i+=stride){ 
			array[i]++;
			stride = rand() % 500;
		}
	}
}
