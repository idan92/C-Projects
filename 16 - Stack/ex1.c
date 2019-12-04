#include "Lib.h"


void main(void)
{
    stack s;
    InitializeStack(&s);
    Data_Type num1 = {.int_ = 4}, num2 = {.int_ = 5}, num3 = {.int_ = 6};
    PushStack(&s, num1);
    PushStack(&s, num2);
    PushStack(&s, num3);
    printf("%hu\n", SumStack(&s));
    printf("%hu\n", PopStack(&s).int_);
    printf("%hu\n", PopStack(&s).int_);
    printf("%hu\n", PopStack(&s).int_);
}