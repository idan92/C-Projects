#include "PointersLibs.h"

struct stack
{
    void ** values;
    unsigned int items;
};


void PushStack(struct stack * sk , void * item)
{
    (*sk).values = realloc((*sk).values, (++((*sk).items) * sizeof(item)));
    *((*sk).values + (*sk).items) = item;
}