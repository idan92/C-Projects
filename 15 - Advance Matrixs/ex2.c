#include "PointersLibs.h"

int SumInSlantUntilNegative(int *ptr_mat, unsigned short rows, unsigned short cols)
{
    int max = *ptr_mat;
    int steps = cols + ONE;

    while (rows-- && (*ptr_mat < ZERO))
    {
        max += *ptr_mat;
        ptr_mat += steps;
    }

    return (max - *ptr_mat);
}

int MaxSumSlant(int *ptr_mat, unsigned short rows, unsigned short cols)
{
    unsigned int area = rows * cols;
    int max = *ptr_mat;
    

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