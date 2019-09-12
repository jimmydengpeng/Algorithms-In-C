#include <stdio.h>
#include <limits.h>
#include "Array.h"

typedef struct MaxSubarray
{
    int left;
    int right;
    long sum;
} MaxSubarray;

MaxSubarray Max_Subarray_Linear(Array *A)
{
    MaxSubarray maxsub;
    int* arr = A->array;
    
    long max = LONG_MIN;
    long sum = LONG_MIN;
    int low = 0;
    int current_low = 0;
    int high = 0;
    int current_high = 0;
    for (int i = 0; i < A->length; i++)
    {
        current_high = i;
        if (sum > 0)
        {
            sum += arr[i];
        }
        else
        {
            current_low = i;
            sum = arr[i];
        }
        if (sum > max)
        {
            max = sum;
            low = current_low;
            high = current_high;
        }
    }
    maxsub.left = low;
    maxsub.right = high;
    maxsub.sum = max;
    return maxsub;
}

int main()
{
    int array_b[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    Array *A = initArrayWithList(array_b, 16);

    MaxSubarray res_maxsub = Max_Subarray_Linear(A);

    printf("(%d, %d): %ld\n", res_maxsub.left, res_maxsub.right, res_maxsub.sum);
}
