#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Array.h"

Array *
getRandomArray(int lower_bound,
               int upper_bound, 
               int length)
{
    Array *A = (Array*)malloc(sizeof(Array));
    int *array = (int*)malloc(length * sizeof(int));
    
    assert(upper_bound > lower_bound);
    int bound_size = upper_bound - lower_bound + 1;

    for (int i = 0; i < length; i++)
    {
        int v = lower_bound + arc4random_uniform(bound_size);
        array[i] = v;
    }

    A->array = array;
    A->length = length;
    
    return A;
}

int
growArrayWithRandomBoundValue(Array *A, int lower_bound, int upper_bound)
{
    //printf("in growArrayWithRandomBoundValue: before grow A->array's address: %p\n", A->array);

    // memcpy
    /*
    int *growed_array = (int*)malloc((A->length + 1) * sizeof(int));

    memcpy(growed_array, A->array, (A->length) * sizeof(int));
    int *p = A->array;
    A->array = growed_array;
    free(p);
    */

    // realloc
    A->array = (int*)realloc(A->array, (A->length+1) * sizeof(int));
    //printf("in growArrayWithRandomBoundValue: after grow A->array's address: %p\n", A->array);

    assert(upper_bound > lower_bound);
    int bound_size = upper_bound - lower_bound + 1;
    int v = lower_bound + arc4random_uniform(bound_size);
    A->array[A->length] = v;
    A->length += 1;
    return SUCCESS;
}

int 
displayArray(Array *A)
{
    printf("[");
    for (int i = 0; i < A->length; i++)
    {
        printf(" %d", A->array[i]);
    }
    printf(" ]\n");
    return SUCCESS;
}

int main()
{
    int lower_bound = -10;
    int upper_bound = 10;
    int length = 10;
    Array *A = getRandomArray(lower_bound, upper_bound, length);
    displayArray(A);

    growArrayWithRandomBoundValue(A, lower_bound, upper_bound);
    displayArray(A);

    growArrayWithRandomBoundValue(A, lower_bound, upper_bound);
    displayArray(A);

    growArrayWithRandomBoundValue(A, lower_bound, upper_bound);
    displayArray(A);

}
