#include "data_generator.h"

/**
Shuffles the deck of length <size> a number of
<cuts> times. You can shuffle more times than the
length of the deck, like a real thing really.
*/
int getRandomInteger()
{
	return rand()%MAX_RAND_GEN_NUM;
}


void shuffle(int *array, int size, int cuts)
{
#ifdef USE_RANDOM_SEED
	struct timeval time;
	gettimeofday(&time, NULL);
	srand(time.tv_usec);
#endif
	for(int i = 0; i < cuts; i++){
		int first = getRandomInteger() % size;
		int second = first;
		while(second == first)
			second = getRandomInteger() % size;
			
		array[first] = array[first] ^ array[second];
		array[second] = array[second] ^ array[first];
		array[first] = array[second] ^ array[first];
	}
}

int *generate(int size, int type)
{
	int *array = malloc(sizeof(int) * size);

	if(type == INVERSELY_ORDERED){
		for(int i = 0; i < size; i++)
			array[i] = size - 1 - i;
	}
	else{
		for(int i = 0; i < size; i++)
			array[i] = i;

		if(type == ORDERED)
			return array;
		if(type == PARTIALLY_ORDERED)
			shuffle(array, size, (int)(size * 0.15));
		else	//this is the RANDOM enum
			shuffle(array, size, size);

		return array;
	}

	return array;
}
