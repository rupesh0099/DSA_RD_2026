#include <stdio.h>
#include <stdlib.h>

void accept(int *p, int size){
    for(int i = 0; i < size; i++){
        scanf("%d", &p[i]);
    }
}

void display(int *p, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", p[i]);
    }
    printf("\n");
}

int main() {

    int *arr1, *arr2, *arr3;
    int n1, n2, i, j, temp;

    printf("Enter size of first array: ");
    scanf("%d", &n1);

    printf("Enter size of second array: ");
    scanf("%d", &n2);

    arr1 = (int*)malloc(n1 * sizeof(int));
    arr2 = (int*)malloc(n2 * sizeof(int));
    int n3 = n1 + n2;
    arr3 = (int*)malloc((n3) * sizeof(int));

    if(arr1 == NULL || arr2 == NULL || arr3 == NULL){
        printf("Memory allocation failed\n");
        return 0;
    }

    printf("Enter elements of first array:\n");
    accept(arr1, n1);

    printf("Enter elements of second array:\n");
    accept(arr2, n2);

    for(i = 0; i < n1; i++){
        arr3[i] = arr1[i];
    }
    for(i = 0; i < n2; i++){
        arr3[n1 + i] = arr2[i];
    }

    for(i = 0; i < n3 - 1; i++){
        for(j = 0; j < n3 - i - 1; j++){
            if(arr3[j] > arr3[j + 1]){
                temp = arr3[j];
                arr3[j] = arr3[j + 1];
                arr3[j + 1] = temp;
            }
        }
    }

    printf("\nMerged and Sorted Array:\n");
    display(arr3, n3);

    free(arr1);
    free(arr2);
    free(arr3);

    return 0;
}