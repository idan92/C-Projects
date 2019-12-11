#include "Lib.h"


LLL * RemoveDuplicate(LLL ** manager)
{
    unsigned short arr[TEN] = { ZERO };
    LLL * pos = *manager;
    while ((*pos).next != NULL)
    {
        (arr[(*(*pos).next).value.int_] == ONE) ? DeleteList(pos) : arr[(*(*pos).next).value.int_]++;
        pos = (*pos).next;
    }
}

void main(void)
{

}
