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


// +-------------------------------------+
// |             Return Array            |
// +-------------------------------------+

Array *
getRandomArray(int lower_bound, 
               int upper_bound, 
               int length);

Array *
initArrayWithList(int *list, int length);

// +-------------------------------------+
// |              Modify                 |
// +-------------------------------------+

int
growArrayWithRandomBoundValue(Array *A, int lower_bound, int upper_bound);

// +-------------------------------------+
// |              Display                |
// +-------------------------------------+

int 
displayArray(Array *A);
	
#endif
