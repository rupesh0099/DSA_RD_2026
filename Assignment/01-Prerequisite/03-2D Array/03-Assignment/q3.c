//Accept elements in two n*m matrix and display the multiplication of two matrix
#include<stdio.h>
#include<stdlib.h>
void multiplication(int arr1[][10],int arr2[][10],int r,int c);
void display(int arr[][10],int r,int c);

int main(){
    int arr1[10][10],arr2[10][10];
    int r,c;
    printf("Enter Row & Column: ");
    scanf("%d %d",&r,&c);

    printf("\nEnter Values of Array1: ");

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    display(arr1,r,c);
    printf("\nEnter Values of Array2: ");

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&arr2[i][j]);
        }
    }
    display(arr2,r,c);
    
    printf("Multiplication of Two Array is:\n");
    multiplication(arr1,arr2,r,c);
    return 0;
}

void multiplication(int arr1[][10],int arr2[][10],int r,int c){
    int arr3[10][10]={0};
    
   for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        for(int k=0;k<c;k++)
        arr3[i][j]+=arr1[i][k]*arr2[k][j]; 
    }
   }
    printf("\n");
    display(arr3,r,c);
}

void display(int arr[][10],int r,int c){
    printf("\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf(" %d",arr[i][j]);
        }
        printf("\n");
    }
}
