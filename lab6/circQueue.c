#include <stdio.h>
#include <stdlib.h>
#include "lab6.h"

void initQueue(struct Queue ** qPtr)
{
    *qPtr = (struct Queue *)malloc(sizeof(struct Queue));
    (*qPtr)->currSize = 0;
    (*qPtr)->front = 0;
    (*qPtr)->rear = 0;
}

int isEmpty(struct Queue * Q)
{
    if(Q->currSize == 0) return 1;
    else return 0;
}

void enqueue(struct Queue * Q, struct Data d)
{
    if(Q->currSize == MaxQueueSize) return;
    
    struct Node res;
    res.data = d;
    
    Q->queueArray[Q->rear] = res;
    Q->rear += 1;
    Q->rear = (Q->rear)%MaxQueueSize;
    Q->currSize += 1;
}

void dequeue(struct Queue * Q, struct Data *d)
{
    if(isEmpty(Q) == 1) return;
    
    *d = Q->queueArray[Q->front].data;
    Q->front += 1;
    Q->front = (Q->front)%MaxQueueSize;
    Q->currSize -= 1;
}

void freeQueue(struct Queue * q){
    free(q);
}