#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <math.h>

typedef struct MaxSubarray
{
    int left;
    int right;
    long sum;
} MaxSubarray;

MaxSubarray Find_Max_Crossing_Subarray(int *A, int low, int mid, int high)
{
    MaxSubarray maxsub;

    long left_sum = LONG_MIN;
    long sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += A[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            maxsub.left = i;
        }
    }

    long right_sum = LONG_MIN;
    sum = 0;
    for (int j = mid + 1; j <= high; j++)
    {
        sum += A[j];
        if (sum > right_sum)
        {
            right_sum = sum;
            maxsub.right = j;
        }
    }
    
    maxsub.sum = left_sum + right_sum;
    return maxsub;
}

MaxSubarray Find_Maximum_Subarray(int *A, int low, int high)
{

    if (high == low)
    {
        MaxSubarray maxsub;
        maxsub.left = low;
        maxsub.right = high;
        maxsub.sum = A[low];
        return maxsub;
    }
    else
    {
        int mid = floor((low + high) / 2);

        MaxSubarray leftsub;
        leftsub = Find_Maximum_Subarray(A, low, mid);

        MaxSubarray rightsub;
        rightsub = Find_Maximum_Subarray(A, mid+1, high);
        
        MaxSubarray crosssub;
        crosssub = Find_Max_Crossing_Subarray(A, low, mid, high);

        if (leftsub.sum >= rightsub.sum && leftsub.sum >= crosssub.sum)
        {
            return leftsub;
        }
        else if (rightsub.sum >= leftsub.sum && rightsub.sum >= crosssub.sum)
        {
            return rightsub;
        }
        else
        {
            return crosssub;
        }
    }
}

int main()
{   
    clock_t start_t, end_t, total_t;
    start_t = clock();
    // printf("starting: %ld.\n", start_t);

    int A[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int length = 16;
    MaxSubarray res_maxsub;
    res_maxsub = Find_Maximum_Subarray(A, 0, length -1);
    printf("%d, %d, %ld.\n", res_maxsub.left, res_maxsub.right, res_maxsub.sum);

    end_t = clock();

    printf("total time used: %f.\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);
}
