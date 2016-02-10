#include "lab3.h"

int testBits(int * a, int n, unsigned int regVar)
{
    int i;
    for(i=0; i<n; i++)
    {
        unsigned int temp = 1 << a[i];
        if ((regVar & temp) != temp)
        {
            return 0;
        }
    }
    return 1;
}

void setBits(int * a, int n, unsigned int * regVar)
{
    int i;
    for(i=0; i<n; i++)
    {
        unsigned int temp = 1 << a[i];
        *regVar = (*regVar | temp);
    }
}

void clearBits(int * a, int n, unsigned int * regVar)
{
    int i;
    for(i=0; i<n; i++)
    {
        unsigned int temp = 1 << a[i];
        *regVar = (*regVar & (~temp));
    }
}
