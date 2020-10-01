#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data_generator.h"


void pretty(int *array, int arraySize)
{
	for(int i = 0; i < arraySize; i++)
		printf("%d ", array[i]);
	printf("\n");
}

int main(int argc, char **argv)
{
	printf("start data generator test...\n");

	int *data;
	int dataSize = 600;

	printf("generate orderd...\n");
	data = generate(dataSize, ORDERED);
	pretty(data, dataSize);

	printf("generated inversely ordered...\n");
	data = generate(dataSize, INVERSELY_ORDERED);
	pretty(data, dataSize);
	
	printf("generate partially orderd\n");
	data = generate(dataSize, PARTIALLY_ORDERED);
	pretty(data, dataSize);

	printf("generate randomly ordered...\n");
	data = generate(dataSize, RANDOM);
	pretty(data, dataSize);
	
	return 0;
}
