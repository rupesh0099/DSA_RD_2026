#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = NULL;
    int size = 0;

    printf("\nEnter the size of an array:\n");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Array size cannot be Zero..!");
        return 0;
    }

    ptr = (int *)malloc(sizeof(int) * size);

    if(ptr == NULL){
        printf("Memory Allocation Failed..!");
        return 0;
    }

    printf("\nEnter the array elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &ptr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (ptr[i] == ptr[j])
            {
                if(i>j){
                    break;
                }
                count++;
            }
        }
        if(count==1){
            printf("\nUnique Elements is %d\n",ptr[i],count);
        }
    }

  free(ptr);
  ptr=NULL;

    return 0;
}