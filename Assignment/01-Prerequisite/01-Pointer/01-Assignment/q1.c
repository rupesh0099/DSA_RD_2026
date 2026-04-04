#include <stdio.h>
#include <stdlib.h>

void swapArrays(int *arr1, int *arr2, int size) {
    int temp;
    for(int i = 0; i < size; i++) {
        temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i]= temp;
    }
}

int main() {
    int n;

    printf("Enter Size of Array : ");
    scanf("%d", &n);

    int *arr1 = (int*)malloc(n*sizeof(int));
    int *arr2 = (int*)malloc(n*sizeof(int));

    if(arr1 == NULL || arr2 == NULL) {
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

    swapArrays(arr1, arr2, n);

    printf("After swapping : \n");

    printf("First array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }

    printf("\nSecond array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }

    free(arr1);
    free(arr2);

    return 0;
}