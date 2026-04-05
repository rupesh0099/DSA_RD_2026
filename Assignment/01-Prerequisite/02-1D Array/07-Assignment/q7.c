#include<stdio.h>
#include<stdlib.h>

int main(){

    int size=0;
    int key=0;

    printf("Enter the Size of Array:\n");
    scanf("%d",&size);

    if(size <= 0){
        printf("Array Size cannot be Zero..!");
        return 0;
    }

    int *arr = (int*)malloc((size)*sizeof(int));

    if(arr == NULL){
        printf("Memory Allocation is Failed..!");
        return 0;
    }

    printf("Enter the Array Elements:\n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter the Element to be search:\n");
    scanf("%d",&key);

    for(int i=0;i<size;i++)
    {
        if(key==arr[i]){
            printf("Key found at %d index",i);
        }
    }

    free(arr);
    arr=NULL;

    return 0;
}