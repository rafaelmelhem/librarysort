/**
Data generator for exercises.
This shall generate integer arrays of length 10, 100, ... 10^n with
certain characteristics:
- no repeated values
- ordered
- inversely ordered
- partially ordered
- random
*/

#include <math.h>
#include <stdlib.h>
#include <sys/time.h>

#define THRESHOLD			89
#define MAX_DATA_LEN		1000000
#define MAX_RAND_GEN_NUM 	MAX_DATA_LEN

typedef enum{
	ORDERED = 0,
	INVERSELY_ORDERED,
	PARTIALLY_ORDERED,
	RANDOM
}array_type;

int *generate(int size, int type);
void shuffle(int *array, int size, int cuts);
