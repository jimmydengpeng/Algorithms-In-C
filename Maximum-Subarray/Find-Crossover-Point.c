#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include "Array.h"

/* This prints a ✓. */
#define PRINTCHECK printf("\xE2\x9C\x93");

/* This prints a x. */
#define PRINTCROSS printf("\xE2\x9D\x8C");

typedef struct MaxSubarray
{
    int left;
    int right;
    long sum;
} MaxSubarray;

MaxSubarray Maximum_Subarray_Brute_Force(Array *Arr)
{
    int *A = Arr->array;
    int length = Arr->length;
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

MaxSubarray Maximum_Subarray_Recurrsive(Array *Arr)
{
    int *A = Arr->array;
    int length = Arr->length;
    return Find_Maximum_Subarray(A, 0, length-1);
}

bool isEqualResult(MaxSubarray sb1, MaxSubarray sb2)
{
    if (sb1.left == sb2.left &&
        sb1.right == sb2.right &&
        sb1.sum == sb2.sum)
        return true;
    else 
        return false;
}

double calculateAverageRunningTime(Array *A, MaxSubarray (*findmaxsub)(Array *))
{
    //int testTimes = 10;
    MaxSubarray maxsub;
    double time_spent = 0.0;
    clock_t start_t, end_t;
    //clock_t sum_t = 0;
    //for (int i = 0; i < testTimes; i++)
    start_t = clock();
        
    maxsub = findmaxsub(A);

    end_t = clock();
    //printf(" <%d : %d> %ld ", maxsub.left, maxsub.right, maxsub.sum);
    time_spent += (double)(end_t - start_t) / CLOCKS_PER_SEC;
	//printf("Time is %f seconds\n", time_spent);
    //double averageTime = (double)sum_t / (CLOCKS_PER_SEC * testTimes);
    //printf("in for loop averageTime: %f", averageTime);
    return time_spent;
}

double *calculateAverageRunningTimeBoth(Array *A)
{
    double *res = (double*)malloc(sizeof(double) * 2);
    res[0] = calculateAverageRunningTime(A, Maximum_Subarray_Brute_Force);
    res[1] = calculateAverageRunningTime(A, Maximum_Subarray_Recurrsive);
    return res;
}

int main()
{
    int lower_bound = -20;
    int upper_bound = 20;
    int length = 5;

    //int array_b[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    //Array *A = initArrayWithList(array_b, 16);
    

    int testtimes = 500;
    int looptimes = 150;
    for (int j = 0; j < testtimes; j++)
    {
        Array *A = getRandomArray(lower_bound, upper_bound, length);
        for (int i = length; i < length + looptimes; i++)
        {
            //printf("length -> %d  ", i);
            //displayArray(A);
            //printf("\n");

            double *times = calculateAverageRunningTimeBoth(A);
            //printf("Brute Force:%f\nRecurrsive:%f\n", times[0], times[1]);
            double time_diff = times[0] - times[1];
            if (time_diff > 0)
            {
                printf("+");
            }
            else if (time_diff < 0)
            {
                printf(" ");
            }
            else
            {
                printf("=");
            }
            /*
            if (times[0] > times[1])
            { 
                printf("%d -> ", i);
                displayArray(A);
                printf("\n");
                printf("Brute Force:%f\nRecurrsive:%f\n", times[0], times[1]);
                //break;
            }

            if (checkIdenticalResult(bf_maxsub, rc_maxsub))
            {   
                //PRINTCHECK
                printf("\n\n");
            }
            else
            {   PRINTCROSS   }
            */

            growArrayWithRandomBoundValue(A, lower_bound, upper_bound);
        }
        printf("\n");
    }
}
