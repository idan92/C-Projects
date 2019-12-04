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
    if ((*sk).items > ZERO)
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

int SumStack(struct stack * sk)
{
    int sum = ZERO;
    int * item;
    struct stack temp_sk;
    InitializeStack(&temp_sk);
    CopyStack(sk, &temp_sk);
    while (!IsEmptyStack(&temp_sk))
    {
        item = PopStack(&temp_sk);
        sum += *item;
    }

    return (sum);
}

BOOLEAN FindInStack(struct stack * sk, void * item)
{
    int sum = ZERO;
    struct stack temp_sk;
    InitializeStack(&temp_sk);
    CopyStack(sk, &temp_sk);
    while (!IsEmptyStack(&temp_sk) && PopStack(&temp_sk) != item);

    return (sum);
}

void UnionStack(struct stack * sk1, struct stack * sk2)
{
    CopyStack(sk1, sk2);
}

void main(void)
{
    struct stack s;
    InitializeStack(&s);
    int num1 = 4, num2 = 5, num3 = 6;
    PushStack(&s, &num1);
    PushStack(&s, &num2);
    PushStack(&s, &num3);
    printf("%hu\n", ItemsStack(&s));
    printf("%p\n", PopStack(&s));
    printf("%hu\n", PopStack(&s));
    printf("%hu\n", PopStack(&s));
}