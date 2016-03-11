#include <stdio.h>
#include <stdlib.h>
#include "lab6.h"

struct Heap * initMinHeap()
{
    struct Heap * res = (struct Heap *)malloc(sizeof(struct Heap));
    res->count = 0;
    int i;
    for(i=0; i<MaxHeapSize; i++)
    {
        res->heapArray[i].data.data = -1;
    }
    return res;
}

void insertMinHeap(struct Heap * h, struct Data d)
{
    struct Node res;
    res.data = d;
    h->heapArray[h->count + 1] = res;

    int childIndex = h->count + 1;
    int parentIndex = childIndex/2;
    struct Data tempData;
    while(h->heapArray[parentIndex].data.data > h->heapArray[childIndex].data.data)
    {
        if(parentIndex == 0) break;
        tempData = h->heapArray[parentIndex].data;
        h->heapArray[parentIndex].data = h->heapArray[childIndex].data;
        h->heapArray[childIndex].data = tempData;
        childIndex = parentIndex;
        parentIndex = childIndex/2;
    }
    h->count += 1;
}

struct Data removeMinHeap(struct Heap * h)
{
    struct Data res = h->heapArray[1].data;
    h->heapArray[1] = h->heapArray[h->count];
    h->heapArray[h->count].data.data = -1;
    
    int parentIndex = 1;
    int childIndex = parentIndex*2;
    struct Data tempData;
    h->count -= 1;
    while(h->heapArray[parentIndex].data.data > h->heapArray[childIndex].data.data || h->heapArray[parentIndex].data.data > h->heapArray[childIndex+1].data.data)
    {
        if(childIndex > h->count) break;
        else if(childIndex + 1 > h->count)
        {
            if(h->heapArray[childIndex].data.data > h->heapArray[parentIndex].data.data) break;
        }
        else if(h->heapArray[childIndex].data.data > h->heapArray[childIndex + 1].data.data)
        {
            childIndex = childIndex + 1;
        }
        
        tempData = h->heapArray[parentIndex].data;
        h->heapArray[parentIndex].data = h->heapArray[childIndex].data;
        h->heapArray[childIndex].data = tempData;
        parentIndex = childIndex;
        childIndex = parentIndex*2;
    }
    return res;
}

void freeMinHeap(struct Heap * h)
{
    free(h);
}