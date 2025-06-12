#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

void alokuj(int rows, int cols)
{
    int **arr = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        arr[i] = malloc(cols * sizeof(int));
}
void print_2d_array(int **arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%3d ", arr[i][j]);
        printf("\n");
    }
}
void read_2d_array(int **arr, int rows, int cols)
{
    printf("Enter %d x %d elements:\n", rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &arr[i][j]);
}
void odwroc_kolumny(int n, int m, int tab[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m / 2; j++)
        {
            int temp = tab[i][j];
            tab[i][j] = tab[i][m - 1 - j];
            tab[i][m - 1 - j] = temp;
        }
    }
}
void odwroc_wiersze(int n, int m, int tab[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m / 2; j++)
        {
            int temp = tab[i][j];
            tab[i][j] = tab[i][m - 1 - j];
            tab[i][m - 1 - j] = temp;
        }
    }
}

int main()
{
}