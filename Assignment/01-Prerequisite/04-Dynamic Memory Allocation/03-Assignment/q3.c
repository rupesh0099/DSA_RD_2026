#include<stdio.h>
#include<stdlib.h>

int main(){

    int *ptr=NULL;
    int size,sum=0;

    printf("\nEnter the array size:\n");
    scanf("%d",&size);

    ptr=(int*)malloc(sizeof(int)*size);

    printf("\nEnter the array elements:\n");
    for(int i=0;i<size;i++){
        scanf("%d",&ptr[i]);
    }
    for(int i=0;i<size;i++){
        sum=sum+ptr[i];
    }

    printf("Sum of all Element is:%d",sum);
    free(ptr);
    ptr=NULL;
    
    return 0;
}