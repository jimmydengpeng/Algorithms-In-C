#ifndef ARRAY_H
#define ARRAY_H

#define SUCCESS 0

// +-------------------------------------+
// |           Define Array              |
// +-------------------------------------+

typedef struct Array
{
    int *array;
    int length;
} Array;

Array *
getRandomArray(int lower_bound, 
               int upper_bound, 
               int length);

int
growArrayWithRandomBoundValue(Array *A, int lower_bound, int upper_bound);

// +-------------------------------------+
// |              Display                |
// +-------------------------------------+
int 
displayArray(Array *A);
	
#endif
