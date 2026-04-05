#include<stdio.h>
#include<stdlib.h>

int main(){

    int *ptr=NULL;
    int size=0;

    printf("Enter the size of element:\n");
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
    
    printf("\nEnter the array elements Array:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &ptr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if(ptr[i]>ptr[j])
            {
                int temp=ptr[i];
                ptr[i]=ptr[j];
                ptr[j]=temp;
            }
        }
    }

    printf("Second Largest Element is:%d",ptr[size-2]);

    free(ptr);
    ptr=NULL;
    
    return 0;
}