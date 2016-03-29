#include "assignment3.h"

struct flowNetwork * initFlowNetwork(){
    int i;
    struct flowNetwork * res = (struct flowNetwork *)malloc(sizeof(struct flowNetwork));
    res->adjMatrix = initAdjMatrix();
    for(i=0; i<NODES; i++)
    {
        res->visitedNodes[i] = 0;
        res->parent[i] = -1;
    }
    return res;
}

void deleteFlowNetwork(struct flowNetwork * fN){
    deleteAdjMatrix(fN->adjMatrix);
    free(fN);
}

int breadthFirstPathSearch(struct flowNetwork * fN, int s, int t){
    struct Queue * flowQ;
    struct Data tempData;
    int currNode;
    int i;
    
    initQueue(&flowQ);
    tempData.vertex = s;
    
    enqueue(flowQ, tempData);
    while(isQueueEmpty(flowQ) == 0)
    {
        dequeue(flowQ, &tempData);
        currNode = tempData.vertex;
        fN->visitedNodes[currNode] = 1;
        for(i=0; i<NODES; i++)
        {
            if(fN->visitedNodes[i] != 1 && fN->adjMatrix[currNode][i].flowCap - fN->adjMatrix[currNode][i].flow > 0)
            {
                tempData.vertex = i;
                enqueue(flowQ, tempData);
                fN->visitedNodes[i] = 1;
                fN->parent[i] = currNode;
            }
        }
        
    }
    free(flowQ);
    return fN->visitedNodes[t];
}

void maximizeFlowNetwork(struct flowNetwork * fN, int s, int t){
    while(breadthFirstPathSearch(fN, s, t) == 1)
    {
        int i = t;
        int j = 0;
        int flowRestriction;
        int path[NODES];
        
        while(i != -1)
        {
           path[j] = i;
           i = fN->parent[i];
           j += 1;
        }
        
        j -= 1;
        i = j;
        flowRestriction = fN->adjMatrix[path[j]][path[j-1]].flowCap;
        while(j>0)
        {
            if (fN->adjMatrix[path[j]][path[j-1]].flowCap - fN->adjMatrix[path[j]][path[j-1]].flow < flowRestriction)
            {
                flowRestriction = fN->adjMatrix[path[j]][path[j-1]].flowCap - fN->adjMatrix[path[j]][path[j-1]].flow;
            }
            j -= 1;
        }
        
        while(i>0)
        {
            fN->adjMatrix[path[i]][path[i-1]].flow += flowRestriction;
            i-=1;
        }
        
        for(i=0; i<NODES; i++)
        {
            fN->visitedNodes[i] = 0;
            fN->parent[i] = -1;
        }
    }
}