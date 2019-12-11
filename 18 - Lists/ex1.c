#include "Lib.h"

#define ASTERISK '*'

LLL * MostInRow(LLL ** manager)
{
    LLL * pos = *manager;
    LLL * max_word = pos;
    LLL * temp_word = pos;
    unsigned int max_count = ZERO;
    unsigned int temp_count = ZERO;
    while ((*pos).next != NULL)
    {
        if ((*pos).value.char_ == ASTERISK)
        {
            if (temp_count > max_count)
            {
                max_word = temp_word;
                max_count = temp_count;
            }
            temp_count = ZERO;
            temp_word = (*pos).next;
        }
        temp_count++;
        pos = (*pos).next;
    }
    
    return (max_word);
}

void main(void)
{

}