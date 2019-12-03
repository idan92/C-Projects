#include "PointersLibs.h"

/*int *PointerMaxSumInSlant(int *ptr_mat, unsigned short rows, unsigned short cols)
{
    int *ptr_max_mat = ptr_mat; // Save the pointer of start max
    int max = *ptr_max_mat;

    unsigned short steps = cols + ONE;

    int *ptr_temp_mat = ptr_mat + steps; // For checking
    int temp_max = max,
        temp;

    rows--;
    for (; rows; rows--)
    {
        temp = temp_max + *ptr_temp_mat;
        if (temp < temp_max)
        {
            if (temp_max > max)
            {
                max = temp_max;
                ptr_max_mat = ptr_temp_mat;
            }
            temp_max = ZERO;
        }
        temp_max += *ptr_temp_mat;
        ptr_temp_mat += steps;
    }

    return (ptr_max_mat);
}*/

int MaxSumInSlant(int *ptr_mat, unsigned short rows, unsigned short cols)
{
    int *ptr_max_mat = ptr_mat; // Save the pointer of start max
    int max = *ptr_max_mat;

    unsigned short steps = cols + ONE;

    int *ptr_temp_mat = ptr_mat + steps; // For checking
    int temp_max = max,
        temp;

    rows--;
    for (; rows; rows--)
    {
        temp = temp_max + *ptr_temp_mat;
        if (temp < temp_max || temp_max > temp)
        {
            if (temp_max > max)
            {
                max = temp_max;
                ptr_max_mat = ptr_temp_mat;
            }
            temp_max = ZERO;
        }
        temp_max += *ptr_temp_mat;
        ptr_temp_mat += steps;
    }

    return (max);
}

void main(void)
{
    int mat[4][5] = {
        {1,2,3,4,5},
        {2,3,4,5,6},
        {3,4,-1,6,7},
        {4,5,6,7,8}
    };

    printf("%d\n", MaxSumInSlant(mat, 4, 5));
}