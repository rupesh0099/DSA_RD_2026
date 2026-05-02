// Accept elements in 4*4 matrix and display the Transpose of matrix

#include <stdio.h>
void display(int arr[4][4]);
int main()
{
    int arr[4][4];
    printf("Enter value of array: ");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Transpose of Matrix:\n");
    display(arr);
    return 0;
}

void display(int arr[4][4])
{
    printf("\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            printf(" %d", arr[j][i]);
        }
        printf("\n");
    }
}