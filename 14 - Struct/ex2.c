#include "PointersLibs.h"
#include <malloc.h>

#define TWO_THOUSAND 2000
#define NINETEEN 1900

struct book
{
    string name;
    string wrtier;
    string company;
    int year;
    int price;
    int id;
};

void AddBook(struct book *ptr_vec, unsigned short *vec_length)
{
    struct book b;
    // I/O book
    // Check I/O book - if I/O is ok = do realloc : out from fun
    ptr_vec = realloc(ptr_vec, ++(*vec_length) * sizeof(struct book));
    *(ptr_vec + (*vec_length) - ONE) = b;
}

struct book * SearchByName(struct book *ptr_vec, unsigned short vec_length, string *name)
{
    while (!StringCompare((*(ptr_vec++)).name, *name) && vec_length--);

    return (--ptr_vec);
}

struct book * SearchByWriter(struct book *ptr_vec, unsigned short vec_length, string *writer)
{
    while (!StringCompare((*(ptr_vec++)).wrtier, *writer) && vec_length--);

    return (--ptr_vec);
}

struct book * SearchByNameAndWriter(struct book *ptr_vec, unsigned short *vec_length, string *name, string *writer)
{

}

struct book * TwentyCentury(struct book *ptr_vec, unsigned short vec_length, struct book *ptr_new_vec)
{
    ptr_new_vec = malloc(sizeof(struct book));
    unsigned int length = ONE;
    unsigned short counter;
    for (counter = ZERO; counter < vec_length; counter++)
    {
        if ((*ptr_vec).year >= 1900 && (*ptr_vec).year >= 2000)
        {
            *(ptr_new_vec + (length++)) = *ptr_vec;
            ptr_new_vec = realloc(ptr_new_vec, sizeof(struct book) * length);
        }
        ptr_vec++;
    }
    ptr_new_vec = realloc(ptr_new_vec, sizeof(struct book) * (--length));

    return (ptr_new_vec);
}

void main(void)
{
    
}