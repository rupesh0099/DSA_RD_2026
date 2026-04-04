#include<stdio.h>
int main(){
    int arr1[10],arr2[10];
    int *ptr1=arr1;
    int *ptr2=arr2;
    printf("\nEnter the 5 Array elements for 1st:\n");
    for(int i=0;i<5;i++){
      scanf("%d",&ptr1[i]);
    }
    printf("\nEnter the 5 Array elements for 2nd:\n");
    for(int i=0;i<5;i++){
      scanf("%d",&ptr2[i]);
    }
    
    for(int i=0,j=i;i<5,j<5;i++,j++){
        int temp=ptr1[i];
        ptr1[i]=ptr2[j];
        ptr2[j]=temp;
        temp=0;
     }
    printf("\nAfter the swaping two array elements:\n");
    printf("1st Array:\n");
    for(int i=0;i<5;i++){
        printf("%d ",ptr1[i]);
      }
    printf("\n2nd Array:\n");
    for(int i=0;i<5;i++){
         printf("%d ",ptr2[i]);
    }
  return 0;
}

