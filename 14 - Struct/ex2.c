#include "PointersLibs.h"
#include <malloc.h>

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
    // Check I/O book
    ptr_vec = realloc(ptr_vec, ++(*vec_length));
    *(ptr_vec + (*vec_length) - ONE) = b;
}

struct book * SearchByName(struct book *ptr_vec, unsigned short *vec_length, string *name)
{
    while (!StringCompare((*(ptr_vec++)).name, *name));

    return (--ptr_vec);
}

struct book * SearchByWriter(struct book *ptr_vec, unsigned short *vec_length, string *writer)
{
    while (!StringCompare((*(ptr_vec++)).wrtier, *writer));

    return (--ptr_vec);
}

void main(void)
{
    
}