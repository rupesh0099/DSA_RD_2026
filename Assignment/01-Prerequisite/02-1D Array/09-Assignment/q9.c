#include <stdio.h>
#include<stdlib.h>

int main()
{

    int size = 0 , sum1 = 0 , sum2 = 0 , sum3 = 0;

    printf("Enter the Size of Array:\n");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Array Size cannot be Zero..!");
        return 0;
    }

    int *arr = (int *)malloc((size) * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory Allocation is Failed..!");
        return 0;
    }

    printf("Enter the Array Elments:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }


    for (int i = 0; i < size / 2; i++)
    {
        sum1 = sum1 + arr[i];
    }


    for (int i = size / 2; i < size; i++)
    {
        sum2 = sum2 + arr[i];
    }


    sum3 = sum2 - sum1;
    printf("Differance between the sum of 1st half and 2nd half is : %d", sum3);

    free(arr);
    arr=NULL;

    return 0;
}