#include <stdio.h>
#include <stdlib.h>
#include "lab6.h"

struct Heap * initMinHeap()
{
    struct Heap * res = (struct Heap *)malloc(sizeof(struct Heap));
    res->count = 0;
    return res;
}

void insertMinHeap(struct Heap * h, struct Data d)
{
    struct Node res;
    res.data = d;
    h->heapArray[count + 1];
    count += 1;
    //put bubblin here
}

struct Data removeMinHeap(struct Heap * h)
{
}

void freeMinHeap(struct Heap * h)
{
}