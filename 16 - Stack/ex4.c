#include "Lib.h"

#define MAX 21

typedef struct
{
    string name;
    unsigned int amount;
} VegBox;

//---------------------------------------------------------------------------------------
//                                     AddBox
//                                     -------
//
// General         : The function added new box to the tower of boxes in some Circumstances.
//
// Parameters     : Tower - A stack with boxes inside.(in)
//                  box   - A item from the type VegBox that needed to be add to the tower. 
//
// Return Value : None.
//
//---------------------------------------------------------------------------------------
// Programer    : Cohen Idan
// Student No.  : 211675038
// Date         : 05.12.2019
//---------------------------------------------------------------------------------------
void AddBox(stack * sk, VegBox vb)
{
    Data_Type item = PopStack(sk);
    Data_Type new_item;
    stack temp_sk;
    InitializeStack(&temp_sk);
    while (!IsEmptyStack(sk) && !StringCompare((*(VegBox *)(item.pointer)).name, vb.name))
    {
        item = PopStack(sk);
        PushStack(&temp_sk, item);
    }
    if (!StringCompare((*(VegBox *)(item.pointer)).name, vb.name))
    {
        while ((*(VegBox *)(item.pointer)).amount++ < MAX && vb.amount-- > ZERO);
    }
    while (!IsEmptyStack(&temp_sk))
    {
        PushStack(sk, PopStack(&temp_sk));
    }
    if (vb.amount > ZERO)
    {
        *(VegBox * )new_item.pointer = vb;
        PushStack(sk, new_item);
    }
}

void main(void)
{
    
}