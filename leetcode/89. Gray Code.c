// 89. 格雷编码
//动态规划+数学公式

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//数学公式法
int *grayCode(int n, int *returnSize)
{
    *returnSize = 1 << n;

    int *res = (int *)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++)
        res[i] = (i >> 1) ^ i;

    return res;
}
//动态规划法:
int *grayCode(int n, int *returnSize)
{
    int *ans = (int *)malloc(sizeof(int) * (1 << n));

    ans[0] = 0;
    ans[1] = 1;
    int count = 2;
    for (int i = 1; i < n; i++)
    {
        int size = 1 << i;
        for (int j = 0; j < size; j++)
            ans[count++] = size + ans[size - j - 1];
    }
    *returnSize = 1 << n;
    return ans;
}