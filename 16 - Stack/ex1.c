#include "PointersLibs.h"

/*struct stack
{
    void ** values;
    unsigned int items;
};*/


void InitializeStack(struct stack * sk)
{
    (*sk).items = ZERO;
}

BOOLEAN IsEmptyStack(struct stack * sk)
{
    return (!(*sk).items);
}

void PushStack(struct stack * sk , void * item)
{
    if (!((*sk).items))
    {
        (*sk).values = malloc((++((*sk).items)) * sizeof(item));
    }
    else
    {
        (*sk).values = realloc((*sk).values, ((++((*sk).items)) * sizeof(item)));
    }
    *((*sk).values + (*sk).items - ONE) = item;
}

void * PopStack(struct stack * sk)
{
    void * item = NULL;
    if (!((*sk).items >= ONE))
    {
        item = *((*sk).values + (*sk).items - ONE);
        (*sk).values = realloc((*sk).values, ((--((*sk).items)) * sizeof(item)));
    }
    else
    {
        free((*sk).values);
    }

    return (item);
}

void EmptyStack(struct stack * sk)
{
    while (!IsEmptyStack(sk))
    {
        PopStack(sk);
    }
}

void CopyStack(struct stack * sk, struct stack * copy)
{
    struct stack temp1_sk;
    void * item;
    InitializeStack(&temp1_sk);

    while (!IsEmptyStack(sk))
    {
        PushStack(&temp1_sk, PopStack(sk));
    }
    while (!IsEmptyStack(&temp1_sk))
    {
        item = PopStack(&temp1_sk);
        PushStack(copy, item);
        PushStack(sk, item);
    }
}

void OppositeStack(struct stack * sk)
{
    struct stack temp_sk;
    InitializeStack(&temp_sk);
    CopyStack(sk, &temp_sk);
    EmptyStack(sk);
    while (!IsEmptyStack(&temp_sk))
    {
        PushStack(sk, PopStack(&temp_sk));
    }
}

BOOLEAN IsEqualsStack(struct stack * sk1, struct stack * sk2)
{
    BOOLEAN flag = TRUE;
    void * item_sk1;
    void * item_sk2;
    struct stack temp_sk;
    InitializeStack(&temp_sk);
    while (!IsEmptyStack(sk1) && !IsEmptyStack(sk2) && flag)
    {
        item_sk1 = PopStack(sk1);
        item_sk2 = PopStack(sk2);
        // flag = (*item_sk1 == *item_sk2); //BlackBox
    }
}

unsigned int ItemsStack(struct stack * sk)
{
    unsigned int counter = ZERO;
    struct stack temp_sk;
    InitializeStack(&temp_sk);
    CopyStack(sk, &temp_sk);
    while (!IsEmptyStack(&temp_sk))
    {
        PopStack(&temp_sk);
        counter++;
    }

    return (counter);
}

void main(void)
{
    struct stack s;
    InitializeStack(&s);
    PushStack(&s, 4);
    PushStack(&s, 5);
    PushStack(&s, 6);
    printf("%hu\n", PopStack(&s));
    printf("%hu\n", PopStack(&s));
    printf("%hu\n", PopStack(&s));
}