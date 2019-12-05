#include "Lib.h"

void DeleteItem(stack * sk, Data_Type item)
{
    Data_Type temp_item;
    stack temp_sk;
    InitializeStack(&temp_sk);
    while (!IsEmptyStack(sk))
    {
        temp_item = PopStack(sk);
        if (temp_item.int_ != item.int_)
        {
            PushStack(&temp_sk, temp_item);
        }
    }
    while (!IsEmptyStack(&temp_sk))
    {
        PushStack(sk, PopStack(&temp_sk));
    }
}

void DeleteDuplicates(stack * sk)
{
    Data_Type item;
    stack temp_sk;
    InitializeStack(&temp_sk);
    while (!IsEmptyStack(sk))
    {
        item = PopStack(sk);
        DeleteItem(sk, item);
        PushStack(&temp_sk, item);
    }
    while (!IsEmptyStack(&temp_sk))
    {
        PushStack(sk, PopStack(&temp_sk));
    }
}

void main(void)
{
    stack s;
    InitializeStack(&s);
    Data_Type num1 = {.int_ = 4}, num2 = {.int_ = 5}, num3 = {.int_ = 6};
    PushStack(&s, num1);
    PushStack(&s, num2);
    PushStack(&s, num3);
}