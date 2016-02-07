#include "lab2.h"


void readMatrix(char * filename, int * matrix)
{
    FILE *file = fopen(filename, "r");
    int i = 0;
    while (i++ < MATSIZE*MATSIZE)
    {
        fscanf(file, "%d", matrix++);
    }
    fclose(file);
    return;
}

void printMatrix(int n, int *A)
{
    int i = 0;
    while (i++ < n*n)
    {
        printf("%d ", *A++);
        if (i%n == 0)
        {
            printf("\n");
        }
    }
    return;
}

void sum(int *A, int *B, int *res, int n)
{
    int i = 0;
    while (i++ < n*n)
    {
        *res++ = (*A++) + (*B++);
    }
    return;
}

void sub(int *A, int *B, int *res, int n)
{
    int i = 0;
    while (i++ < n*n)
    {
        *res++ = (*A++) - (*B++);
    }
    return;
}

int determinant(int n, int *matrix)
{
    if (n == 1)
    {
        return *matrix;
    }
    else if (n == 2)
    {
        return (*matrix * (*(matrix + 3))) - ((*(matrix + 1)) * (*(matrix + 2)));                                     /* reset other files before submission */
    }
    else
    {
        int res = 0, i = 0, n2 = n - 1;
        for (i = 0; i < n; i++)
        {
            int newmatrix[n2][n2];
            int *p = newmatrix;
            int j = 0, k = 0, row = 0, col = 0;
            for (j = 0; j < n; j++)
            {
                for (k = 0; k < n; k++)
                { 
                    if (k == i)
                    {
                        continue;
                    }
                    *p++ = *(matrix + n + n*j + k);
                }
            }
                                                                                                                    /*
                                                                                                                    printf("n2 is %d \n", n2);
                                                                                                                    printMatrix(n2, (int*)newmatrix);
                                                                                                                    printf("\n");*/
            res += pow(-1, i) * (determinant(n2, (int *)newmatrix)) * (*(matrix + i));
                                                                                                                    /*printf("test i:%d res:%d \n", i, res);*/
        }
        return res;
    }
}