#include "lab4.h"

struct Vehicle * initVehicle(int wheels, char * model, struct vInterface vInt)
{
    struct Vehicle * res = (struct Vehicle *)malloc(sizeof(struct Vehicle));
    res->numWheels = wheels;
    res->model = model;
    res->vehInt = vInt;
}

void cleanUpVehicle(struct Vehicle * v)
{
    free(v);
}

