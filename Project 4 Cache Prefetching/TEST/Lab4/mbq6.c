#include <stdio.h>

int main(int argc, char *argv[]) {
	
	// Config: 64 sets in cache, 2-way, 64 bytes per blk
	
	int total_array_size = 10000000;
	char array [total_array_size];
	int i, stride;

	for (i = 0; i < 100000; i+=stride){	//Create an access pattern
			array[i]++;
			stride += 500;
	}
	return 0;
}
