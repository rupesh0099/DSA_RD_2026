 #include<stdio.h>
#include<stdlib.h>

int main(){

    int *ptr=NULL;
    int size=0;

    printf("Enter the size of element:\n");
    scanf("%d", &size);

    if (size <= 1)
    {
        printf("Array size must be greater than 1!");
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
        for (int j = i+1; j < size; j++)
        {
            if(ptr[i] > ptr[j])
            {
                int temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }

    int largest = ptr[size-1];
    int slag = -1;

    for (int i = size-2; i >= 0; i--)
    {
        if(ptr[i] != largest)
        {
            slag = ptr[i];
            break;
        }
    }

    if(slag == -1)
        printf("No second largest element (all elements same)");
    else
        printf("Second Largest Element is: %d", slag);

    free(ptr);
    ptr = NULL;

    return 0;
}