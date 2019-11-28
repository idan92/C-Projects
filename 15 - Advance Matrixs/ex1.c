#include "PointersLibs.h"


int SlantSum(int *ptr_mat, unsigned short rows, unsigned short cols)
{
    int sum = ZERO;
    cols++;
    for ( ;rows; rows--)
    {
        sum += *ptr_mat;
        ptr_mat += cols;
    }

    return (sum);
}

int SlantWithMaxSum(int *ptr_mat, unsigned short rows, unsigned short cols)
{
    int max = MainSlantSum(ptr_mat, rows, cols);
    int temp;
    unsigned short slats;
    ptr_mat++;
    for (slats = ONE; slats < cols; slats++)
    {
        temp = SlantSum(ptr_mat++, rows, cols);
        max = (temp > max) ? temp : max;
    }

    return (max);
}

void main(void)
{

}