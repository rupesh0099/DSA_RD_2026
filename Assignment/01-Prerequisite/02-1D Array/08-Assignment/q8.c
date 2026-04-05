#include <stdio.h>
#include <stdlib.h>

void accept(int *arr, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
}

void display(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void leftRotate(int *arr, int n, int k){

    k = k % n; 

    for(int i = 0; i < k; i++){
        int first = arr[0];
        for(int j = 0; j < n-1; j++){
            arr[j] = arr[j+1];
        }
        arr[n-1] = first;
    }
}

void rightRotate(int *arr, int n, int k){
    k = k % n;  

    for(int i = 0; i < k; i++){
        int last = arr[n-1];
        for(int j = n-1; j > 0; j--){
            arr[j] = arr[j-1];
        }
        arr[0] = last;
    }
}

int main(){
    
    int *arr;
    int n, k;

    printf("Enter Size of Array : ");
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));

    if(arr == NULL){
        printf("Memory allocation failed..!");
        return 0;
    }

    printf("Enter elements:\n");
    accept(arr, n);

    printf("Enter number of rotations: ");
    scanf("%d", &k);

    leftRotate(arr, n, k);
    printf("Array after left rotation:\n");
    display(arr, n);

    rightRotate(arr, n, k); 
    printf("Array after right rotation:\n");
    display(arr, n);

    free(arr);

    return 0;
}