#include <stdio.h>
#include <stdlib.h>

void sumArrays(int *ptr1, int *ptr2 , int *ptr3 , int size) {
    for(int i = 0 ; i < size ; i++ ){
        ptr3[i] = ptr1[i] + ptr2[i];
    }
}

int main() {
    int n;

    printf("Enter size of Array : ");
    scanf("%d", &n);

    int *arr1 = (int *)malloc(n * sizeof(int));
    int *arr2 = (int *)malloc(n * sizeof(int));
    int *arr3 = (int *)malloc(n * sizeof(int));

    if(arr1 == NULL || arr2 == NULL || arr3 == NULL) {
        printf("Memory allocation failed!\n");
        return 0;
    }

    printf("Enter elements of first array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter elements of second array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    sumArrays(arr1, arr2, arr3 , n);

    printf("\nSum of arrays:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr3[i]);  
    }

    free(arr1);
    free(arr2);
    free(arr3);

    return 0;
}