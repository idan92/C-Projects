#include "Lib.h"

int SectionOne(stack * sk)
{
    stack temp_sk;
    InitializeStack(&temp_sk);
    CopyStack(&temp_sk, sk);
    int last_number = PopStack(&temp_sk).int_;
    int this_number = PopStack(&temp_sk).int_;
    while (this_number >= last_number)
    {
        last_number = this_number;
        this_number = PopStack(&temp_sk).int_;
    }

    return (this_number);
}

int SectionOne(stack * sk)
{
    stack temp_sk;
    InitializeStack(&temp_sk);
    CopyStack(&temp_sk, sk);
    unsigned int counter = ZERO;
    int number = SectionOne(&temp_sk);
    while (PopStack(&temp_sk).int_ != number)
    {
        counter++;
    }

    return (counter);
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