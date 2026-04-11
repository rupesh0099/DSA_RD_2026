#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = NULL;
    int size = 0;

    printf("Enter the size of array:\n");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid size!\n");
        return 0;
    }

    ptr = (int *)malloc(sizeof(int) * size);
    if (ptr == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return 0;
    }

    printf("Enter %d unique elements:\n", size);

    for (int i = 0; i < size; i++)
    {
        int value, flag;

        while (1)
        {
            flag = 0;
            scanf("%d", &value);

            for (int j = 0; j < i; j++)
            {
                if (ptr[j] == value)
                {
                    flag = 1;
                    break;
                }
            }

            if (flag)
            {
                printf("Duplicate not allowed! Enter again:\n");
            }
            else
            {
                ptr[i] = value;
                break;
            }
        }
    }

    printf("\nUnique array elements are:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", ptr[i]);
    }

    free(ptr);
    ptr = NULL;

    return 0;
}