// 2022. 将一维数组转变成二维数组

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **construct2DArray(int *original, int originalSize, int m, int n, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    if (originalSize != m * n)
        return NULL;
    *returnColumnSizes = (int *)malloc(sizeof(int) * m);
    int **ans = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++)
    {
        (*returnColumnSizes)[i] = n;
        ans[i] = (int *)malloc(sizeof(int) * n);
    }
    int row = 0;
    int col = 0;

    for (int i = 0; i < originalSize; i++)
    {
        if (col == n)
            row++;
        col = col % n;
        ans[row][col] = original[i];
        col++;
    }
    *returnSize = m;
    return ans;
}