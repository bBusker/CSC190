#include "queue.h"

struct Queue initQueue()
{
    /* struct Queue * res = (struct Queue *)malloc(sizeof(struct Queue)); */
    struct Queue res;
    res.currSize = 0;
    res.front = NULL;
    res.rear = NULL;
    return res;
}

void enqueue(struct Queue *qPtr, struct Data d)
{
    struct Node * res = (struct Node *)malloc(sizeof(struct Node));
    res->data = d;
    res->next = NULL;
    if(qPtr->currSize == 0)
    {
        qPtr->front = res;
        qPtr->rear = res;
        qPtr->currSize += 1;
        return;
    }
    else
    {
        qPtr->rear->next = res;
        qPtr->rear = res;
        qPtr->currSize += 1;
    }
}

struct Data dequeue(struct Queue *qPtr)
{
    struct Node * res = qPtr->front;
    qPtr->front = qPtr->front->next;
    qPtr->currSize -= 1;
    struct Data temp = res->data;
    free(res);
    return temp;
}

void freeQueue(struct Queue *qPtr)
{
    while(qPtr->currSize != 0)
    {
        dequeue(qPtr);
    }
}
