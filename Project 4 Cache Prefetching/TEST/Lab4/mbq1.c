#include <stdio.h>

int main(int argc, char *argv[]) {

	// Config: 64 sets in cache, 2-way, 64 bytes per blk
	
	int stride = atoi(argv[1]);
	
	int total_array_size = 100000000;
	char array[total_array_size];
	int i;


	for (i = 0; i < total_array_size; i+=stride){	//equal stride length, depends on user input
		array[i]++;
	}
	return 0;
}
