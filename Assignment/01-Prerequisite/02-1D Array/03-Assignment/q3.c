
#include <stdio.h>
#include <stdlib.h>

void accept(int *arr, int n)
{
    printf("\nEnter the vlaue of the Array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void removeDuplicate(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == -1)
            {
                if (arr[j] != -1)
                {
                    arr[i] = arr[j];
                }
            }
            if (arr[i] == arr[j])
            {
                arr[j] = -1;
            }
        }
    }
}

void display(int *arr, int n)
{
    printf("\n\nThe value of the array are: ");
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != -1)
            printf(" %d", arr[i]);
    }
}


int main()
{
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Array size cannot be Zero..!");
        return 0;
    }

    int *arr = (int *)malloc(sizeof(int) * n);

     if(arr == NULL){
        printf("Memory Allocation Failed..!");
        return 0;
    }

    accept(arr, n);
    removeDuplicate(arr, n);
    display(arr, n);

    free(arr);
    arr=NULL;

    return 0;
}

