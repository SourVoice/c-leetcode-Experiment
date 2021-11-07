int maxCount(int m, int n, int **ops, int opsSize, int *opsColSize)
{
    int **matrix = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * n);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 0;
        }
    }
    for (int row = 0; row < opsSize; row++)
    {
        for (int i = 0; i < ops[row][0]; i++)
        {
            for (int j = 0; j < ops[row][1]; j++)
            {
                matrix[i][j]++;
            }
        }
    }
    int *count = (int *)malloc(sizeof(int) * (matrix[0][0] + 1));
    for (int i = 0; i < matrix[0][0] + 1; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            count[matrix[i][j]]++;
        }
    }
    return count[matrix[0][0]];
}