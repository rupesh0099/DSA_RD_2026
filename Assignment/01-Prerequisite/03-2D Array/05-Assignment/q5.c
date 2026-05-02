#include <stdio.h>


void magic(int arr[3][3]);

int main() {
    int arr[3][3];

    printf("Enter values of the 3x3 matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    magic(arr);  
    return 0;
}

void magic(int arr[3][3]){
    int sum = 0;

    for (int i = 0; i < 3; i++) {
        sum += arr[0][i];
    }

    for (int i = 0; i < 3; i++) {
        int rowSum = 0;
        for (int j = 0; j < 3; j++) {
            rowSum += arr[i][j];
        }
        if (rowSum != sum) {
            printf("\nNot a Magic Square Rows do not have the same sum.\n");
            return;
        }
    }

    for (int i = 0; i < 3; i++) {
        int colSum = 0;
        for (int j = 0; j < 3; j++) {
            colSum += arr[j][i];
        }
        if (colSum != sum) {
            printf("\nNot a Magic Square Columns do not have the same sum.\n");
            return;
        }
    }

    int diag1Sum = 0;
    for (int i = 0; i < 3; i++) {
        diag1Sum += arr[i][i];
    }
    if (diag1Sum != sum) {
        printf("\nNot a Magic Square  Main diagonal does not have the same sum.\n");
        return;
    }

    int diag2Sum = 0;
    for (int i = 0; i < 3; i++) {
        diag2Sum += arr[i][i];
    }
    if (diag2Sum != sum) {
        printf("\nNot a Magic Square Secondary diagonal does not have the same sum.\n");
        return;
    }

    printf("\nMagic Square: All rows, columns, and diagonals have the same sum: %d\n", sum);
}
