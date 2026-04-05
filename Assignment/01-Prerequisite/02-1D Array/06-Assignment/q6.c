#include<stdio.h>
#include<stdlib.h>

int main(){

    int size=0;

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

    for(int i=0,j=size-1;i<j;i++,j--)
    {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
    }

    printf("Revert Array is:\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

    free(arr);
    arr=NULL;

    return 0;
}