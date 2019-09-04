#include <stdio.h>
#include <limits.h>
#include <time.h>


typedef struct MaxSubarray
{
    int left;
    int right;
    long sum;
} MaxSubarray;

MaxSubarray Maximum_Subarray_Brute_Force(int *A, int length)
{
    MaxSubarray maxsub;
    
    maxsub.sum = LONG_MIN;
    for (int i = 0; i < length; i++)
    {
        long sum = 0;
        for (int j = i; j < length; j++)
        {
            sum += A[j];
            if (sum > maxsub.sum)
            {
                maxsub.left = i;
                maxsub.right = j;
                maxsub.sum = sum;
            }
        }
    }
    return maxsub;
}

int main()
{
    clock_t start_t, end_t, total_t;
    // printf("starting: %ld.\n", start_t);

    int A[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int length = 16;
    MaxSubarray res_maxsub;

    start_t = clock();
    res_maxsub = Maximum_Subarray_Brute_Force(A, length);
    end_t = clock();

    printf("%d, %d, %ld.\n", res_maxsub.left, res_maxsub.right, res_maxsub.sum);

    // printf("ending: %ld.\n", end_t);

    printf("total time used: %f.\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);
}
