#include "lab2.h"

void p1(void)
{
    int matrix[MATSIZE][MATSIZE];
    readMatrix("matrix1.txt", (int *)matrix);
    printMatrix(MATSIZE,(int *)matrix);
}

void p2(void)
{
    int matrix1[MATSIZE][MATSIZE];
    int matrix2[MATSIZE][MATSIZE];
    int sumMatrix[MATSIZE][MATSIZE];
    readMatrix("matrix1.txt", (int *)matrix1);
    readMatrix("matrix2.txt", (int *)matrix2);
    sum((int *)matrix1, (int *)matrix2,(int *)sumMatrix,MATSIZE);
    printMatrix(MATSIZE,(int *)matrix1);
    printMatrix(MATSIZE,(int *)matrix2);
    printMatrix(MATSIZE,(int *)sumMatrix);
}

void p3(void)
{
    int matrix1[MATSIZE][MATSIZE];
    int matrix2[MATSIZE][MATSIZE];
    int subMatrix[MATSIZE][MATSIZE];
    readMatrix("matrix1.txt", (int *)matrix1);
    readMatrix("matrix2.txt", (int *)matrix2);
    sub((int *)matrix1, (int *)matrix2,(int *)subMatrix,MATSIZE);
    printMatrix(MATSIZE,(int *)matrix1);
    printMatrix(MATSIZE,(int *)matrix2);
    printMatrix(MATSIZE,(int *)subMatrix);
}

void p4(void)
{
    int matrix1[MATSIZE][MATSIZE];
    readMatrix("matrix1.txt", (int *)matrix1);
    printMatrix(MATSIZE,(int *)matrix1);
    printf("The determinant of the matrix is %d\n",determinant(MATSIZE,(int *)matrix1));
}

/* void p5(void)
{
    int matrix[1] = {3};
    printf("%d \n", determinant(1, (int *)matrix));
    int matrix1[2][2] = {{1, 2}, {3, 4}};
    printf("%d \n", determinant(2, (int *)matrix1));
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        printf("%G \n", pow(-1, i));
    }
    printf("\n");
    int matrix2[3][3] = {{6, 1, 1}, {4, -2, 5}, {2, 8, 7}};
    printf("The determinant of the matrix is %d\n",determinant(3, (int *)matrix2));
} */

int main( int argc, char *argv[] )
{
    if( argc < 2 )
   	{
        printf("Expecting at least one argument. Please try again\n");
   	}
    else if(argc==2)
    {
        if(atoi(argv[1])==1)
        {
            p1();
        }
        else if(atoi(argv[1])==2)
        {
            p2();
        }
        else if(atoi(argv[1])==3)
        {
            p3();
        }
        else if(atoi(argv[1])==4)
        {
            p4();
        }
        else if(atoi(argv[1])==5)
        {
            p5();
        }
        else
        {
            printf("Incorrect argument supplied.\n");
        }
    }
    else
    {
        printf("Expecting one argument. Please try again.\n");
    }
}
