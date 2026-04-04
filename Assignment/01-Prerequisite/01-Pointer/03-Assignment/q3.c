#include<stdio.h>
#include<stdlib.h>
int main(){

    int n;

    printf("Enter Size of Array : ");
    scanf("%d", &n);

    int *ptr1 = (int*)malloc(n*sizeof(int));

    if(ptr1 == NULL){
        printf("Memory Allocation Failed..!");
        return 0;
    }

    printf("\nEnter the Array elements:\n");

    for(int i=0;i<n;i++){
      scanf("%d",&ptr1[i]);
    }

    for(int i=0;i<n;i++){
        printf("\n%d) Array elements is: %d and address is: %p\n",i+1,ptr1[i],&ptr1[i]);
    }

    free(ptr1);

  return 0;
}