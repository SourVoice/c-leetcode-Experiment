/*范围求和*/
#include <stdio.h>
#include <stdlib.h>
int maxCount(int m, int n, int **ops, int opsSize, int *opsColSize)
{
    int minrow = m;
    int mincol = n;
    for (int row = 0; row < opsSize; row++)
    {
        if (minrow > ops[row][0])
            minrow = ops[row][0];
        if (mincol > ops[row][1])
            mincol = ops[row][1];
    }
    return minrow * mincol;
}
int main()
{
    int opsSize = 2; //操作次数
    int *opsColSize; //每个操作包含步骤
    *opsColSize = 2;
    int ops[2][2] = {
        {2, 2}, {3, 3}};
    int m = 3, n = 3;
    maxCount(m, n, ops, 2, opsSize, opsColSize);
}