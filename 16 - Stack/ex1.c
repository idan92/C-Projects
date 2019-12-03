#include "PointersLibs.h"

struct stack
{
    void ** values;
    unsigned int items;
};

void CreateStack(struct stack * sk)
{
    (*sk).items = ZERO;
    (*sk).values = malloc(((*sk).items + ONE) * sizeof(*((*sk).values)));
}

void PushStack(struct stack * sk , void * item)
{
    (*sk).values = realloc((*sk).values, ((++((*sk).items) + ONE) * sizeof(item)));
    *((*sk).values + (*sk).items) = item;
}

void * PopStack(struct stack * sk)
{
    void * item = NULL;
    if ((*sk).items)
    {
        item = *((*sk).values + (*sk).items);
        (*sk).values = realloc((*sk).values, ((--((*sk).items) + ONE) * sizeof(item)));
    }

    return (item);
}

void main(void)
{
    struct stack s;
    CreateStack(&s);
    PushStack(&s, 4);
    PushStack(&s, 5);
    PushStack(&s, 6);
    printf("%hu\n", PopStack(&s));
    printf("%hu\n", PopStack(&s));
    printf("%hu\n", PopStack(&s));
}