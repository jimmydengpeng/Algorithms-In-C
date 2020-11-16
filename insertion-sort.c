#include <stdio.h>

void insertion_sort(int *arr, int lenth)
{
    for (int j = 2; j < lenth; j++)
    {
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}

void print_arr(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d", arr[i]);
        if (i < length - 1)
        {
            printf(", ");
        }
    }
    printf("\n");
}

int main()
{
    int arr[6] = {2, 6, 5, 1, 4, 3};
    int length = 6;

    printf("Input:\n");
    print_arr(arr, length);
    insertion_sort(arr, length);
    printf("Output:\n");
    print_arr(arr, length);

    return 0;
}
