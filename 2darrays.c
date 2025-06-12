#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

int **alokuj(int rows, int cols)
{
    int **arr = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        arr[i] = malloc(cols * sizeof(int));
    return arr;
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
void odwroc_kolumny(int n, int m, int **tab)
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
void odwroc_wiersze_dynamic(int n, int m, int **tab)
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
void remove_given(int **tab, int n, int m, int p, int r)
{
    int **arr = alokuj(n - 1, m);
    int new_i = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == p)
        {
            continue;
        }
        int new_j = 0;

        for (int j = 0; j < m; j++)
        {

            if (j == r)
            {
                continue;
            }
            arr[new_i][new_j] = tab[i][j];
            new_j++;
        }
        new_i++;
    }
    print_2d_array(arr, n - 1, m - 1);
}

int main()
{
    int **tab = alokuj(3, 4);
    int liczby = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            *(*(tab + i) + j) = liczby;
            liczby++;
        }
    }
    remove_given(tab, 3, 4, 0, 1);
}