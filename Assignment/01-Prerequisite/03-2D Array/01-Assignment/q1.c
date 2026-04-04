#include <stdio.h>

void diagonal(int arr[][10], int r, int c);
void sort(int *d, int r);

int main()
{
    int column, row, sum = 0, sumColumn = 0;

    printf("Enter no of column: ");
    scanf("%d", &column);

    printf("\nEnter no of Row: ");
    scanf("%d", &row);

    int arr[10][10];

    printf("\nEnter value: ");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d", &arr[i][j]);
            sum += arr[i][j];
            if (j == 1)
                sumColumn += arr[i][j];
        }
    }

    printf("\n\nSum of all Element: %d", sum);
    printf("\nSum of 2nd Column Element: %d", sumColumn);

    diagonal(arr, row, column);

    return 0;
}

void diagonal(int arr[][10], int r, int c)
{
    int sum = 0, large = 0, small = arr[0][0];

    int ld[r], rd[r];

    printf("\nLeft diagonal:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {

            if (i == j)
            {
                printf(" %d", arr[i][j]);
                if (large < arr[i][j])
                    large = arr[i][j];
                if (small > arr[i][j])
                    small = arr[i][j];
                sum += arr[i][j];
                ld[i] = arr[i][j];
            }
        }
    }

    printf("\n\nSorted Left Diagonal: ");
    sort(ld, r);

    for (int i = 0; i < r; i++)
    {
        printf(" %d", ld[i]);
    }

    printf("\n\nSum of Left Diagonal: %d", sum);
    printf("\nLarger Element: %d", large);
    printf("\nSmaller Element: %d", small);

    printf("\nRight diagonal:\n");
    sum = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i + j == c - 1)
            {
                printf(" %d", arr[i][j]);
                if (large < arr[i][j])
                    large = arr[i][j];
                if (small > arr[i][j])
                    small = arr[i][j];
                sum += arr[i][j];
                rd[i] = arr[i][j];
            }
        }
    }

    printf("\n\nSum of Right Diagonal: %d", sum);
    printf("\nLarger Element: %d", large);
    printf("\nSmaller Element: %d", small);

    printf("\n\nSorted Right Diagonal: ");
    sort(rd, r);

    for (int i = 0; i < r; i++)
    {
        printf(" %d", rd[i]);
    }
}

void sort(int *d, int r)
{
    int temp = 0;

    for (int i = 0; i < r - 1; i++)
    {
        for (int j = i + 1; j < r; j++)
        {
            if (d[i] > d[j])
            {
                temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }
}
