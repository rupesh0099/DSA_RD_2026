#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = NULL;
    int size;

    printf("Enter size of array:\n");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid size!\n");
        return 0;
    }

    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 0;
    }

    printf("Enter array elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int maxSum = arr[0];
    int Sum = arr[0];

    int start = 0, end = 0, temp = 0;

    for (int i = 1; i < size; i++)
    {
        if (Sum + arr[i] < arr[i])
        {
            Sum = arr[i];
            temp = i;
        }
        else
        {
            Sum += arr[i];
        }

        if (Sum > maxSum)
        {
            maxSum = Sum;
            start = temp;
            end = i;
        }
    }

    printf("\nMaximum Subarray Sum = %d\n", maxSum);

    printf("Subarray is: ");
    for (int i = start; i <= end; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);
    arr = NULL;

    return 0;
}