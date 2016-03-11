#include "assignment1.h"

double ** choleskyDecomp(double ** A, int n, int i)
{
    if (identity(A, n) == 1) return A;

    double ** L = NULL;
    double v[n-i-1], vvt[n-i-1][n-i-1], sqrt_a00;
    sqrt_a00 = sqrt(A[i][i]);
    initMatrix(&L, n);
    
    
    /*making col/row vector*/
    int j, k;
    for(j=i+1; j<n; j++)
    {
        printf("test_forloop\n");
        v[j-i-1] = A[j][i];
        A[j][i] = 0;
        A[i][j] = 0;
    }
    printf("test1\n");
    
    /*making v times v_transpose*/
    for(j=0; j<n-i-1; j++)
    {
        for(k=0; k<n-i-1; k++)
        {
            vvt[j][k] = ((v[j] * v[k]) / A[i][i]);
        }
    }
    printf("test2\n");
    
    /*making the "B" portion of A*/
    for(j=i+1; j<n; j++)
    {
        for(k=i+1; k<n; k++)
        {
            A[j][k] = (A[j][k] - vvt[j-i-1][k-i-1]);
        }
    }
    printf("test3\n");
    
    /*making L an identity matrix*/
    for(j=0; j<n; j++)
    {
        for(k=0; k<n; k++)
        {
            if(j==k)
            {
                L[j][k] = 1;
            }
            else
            {
                L[j][k] = 0;
            }
        }
    }
    printf("test4\n");
    
    /*setting specific values for L*/
    L[i][i] = sqrt_a00;
    for(j=i+1; j<n; j++)
    {
        L[j][i] = (v[j-i-1] / sqrt_a00);
    }
    printf("test5\n");
    
    
    A[i][i] = 1;
    printMatrix(A, n);
    printf("---------------------\n");
    return mult(L, choleskyDecomp(A, n, i+1), n);
}

double ** mult(double ** L1,double ** L2, int n)
{
    int i, j, k, sum = 0;
    double ** res = (double **)malloc(n*sizeof(double *));
    for(i=0; i<n; i++)
    {
        res[i] = (double *)malloc(n*sizeof(double));
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            double sum = 0;
            for(k=0; k<n; k++)
            {
                sum += L1[i][k] * L2[k][j];
            }
            res[i][j] = sum;
        }
    }
    if(L1 != L2)
    {
        freeMatrix(L2, n);
    }
    freeMatrix(L1, n);
    return res;
}

int identity(double ** A, int n)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        if(A[i][i] != 1) return 0;
        for(j=0; j<n; j++)
        {
            if(i == j) continue;
            if(A[i][j] != 0) return 0;
        }
    }
    return 1;
}


void initMatrix(double ***mat,int n)
{
    int i, j;
    double **res = (double **)malloc(n*sizeof(double *));
    for(i=0; i<n; i++)
    {
        res[i] = (double *)malloc(n*sizeof(double));
        for(j=0; j<n; j++)
        {
            res[i][j] = 0;
        }
    }
    *mat = res;
}

double **readMatrix(char * filename)
{
    int i, j;
    double ** res = (double **)malloc(MATSIZE*sizeof(double *));
    for(i=0; i<MATSIZE; i++)
    {
        res[i] = (double *)malloc(MATSIZE*sizeof(double));
    }
    
    FILE *file = fopen(filename, "r");
    
    for(i=0; i<MATSIZE; i++)
    {
        for(j=0; j<MATSIZE; j++)
        {
            fscanf(file, "%lf",  &res[i][j]);
        }
    }
    fclose(file);
    return res;
}

void freeMatrix(double ** matrix, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
       free(matrix[i]);
    }
    free(matrix);
}

void printMatrix(double ** A, int n)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%f ", A[i][j]);
        }
        printf("\n");
    }
}