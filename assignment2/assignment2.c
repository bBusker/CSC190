#include "assignment2.h"

double calcAverageWaitingTime(struct Simulation * S)
{
    int count = (S->eventQueue).currSize;
    double totalWaitTime = 0;
    struct Data tempdata;
    struct Queue tempQ = S->eventQueue;
    //int i = 0;
    //printf("test1 \n");
    while(tempQ.currSize > 0)
    {
        tempdata = dequeue(&tempQ);
        totalWaitTime += tempdata.departureTime - tempdata.arrivalTime;
        //printf("%d : %f \n", i++, tempdata.departureTime - tempdata.arrivalTime);
    }
    return totalWaitTime/count;
    
    /*struct Queue tempQ = S->eventQueue;
    struct Node * nextPtr = tempQ.front;
    int count = 0;
    double totalWaitTime = 0;
    while(nextPtr != NULL)
    {
        count += 1;
        totalWaitTime += (nextPtr->data).departureTime - (nextPtr->data).arrivalTime;
        nextPtr = nextPtr->next;
    }
    return totalWaitTime/count;*/
}

struct Simulation initSimulation(double arrivalRate, double serviceTime, double simTime)
{
    struct Simulation res;
    res.currTime = 0;
    res.arrivalRate = arrivalRate;
    res.serviceTime = serviceTime;
    res.timeForNextArrival = getRandTime(res.arrivalRate);
    res.timeForNextDeparture = res.timeForNextArrival + res.serviceTime;
    res.totalSimTime = simTime;
    res.buffer = initQueue();
    res.eventQueue = initQueue();
    return res;
}

double runSimulation(double arrivalRate, double serviceTime, double simTime)
{
    struct Simulation sim = initSimulation(arrivalRate, serviceTime, simTime);
    //int i = 0;
    while(sim.currTime < sim.totalSimTime)
    {
        if(sim.timeForNextArrival < sim.timeForNextDeparture)
        {
            sim.currTime = sim.timeForNextArrival;
            struct Data pktdata;
            pktdata.arrivalTime = sim.currTime;
            /* pktdata.departureTime = -1; */
            enqueue(&sim.buffer, pktdata);
            //printf("%d, arrival: %f \n", ++i, sim.currTime);
            sim.timeForNextArrival = sim.currTime + getRandTime(sim.arrivalRate);
        }
        else if(sim.buffer.currSize == 0)
        {
            sim.currTime = sim.timeForNextArrival;
            //printf("%d, skip: %f \n", i, sim.currTime);
            sim.timeForNextDeparture = sim.currTime + sim.serviceTime;
        }
        else if(sim.timeForNextArrival >= sim.timeForNextDeparture)
        {
            sim.currTime = sim.timeForNextDeparture;
            struct Data tempdata = dequeue(&sim.buffer);
            tempdata.departureTime = sim.currTime;
            enqueue(&sim.eventQueue, tempdata);
            //printf("%d, departure: %f \n", i, sim.currTime);
            if(sim.buffer.currSize == 0) sim.timeForNextDeparture = sim.timeForNextArrival + sim.serviceTime;
            else if(sim.buffer.currSize != 0) sim.timeForNextDeparture = sim.currTime + sim.serviceTime;
        }
    }
    double res = calcAverageWaitingTime(&sim);
    freeQueue(&sim.buffer);
    return res;
}