// 1220. 统计元音字母序列的数目
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>

//法一:动态规划
// #define mod_num (1e9 + 7)
int countVowelPermutation(int n)
{
    long long mod_num = 1e9 + 7;
    long long *dp;
    dp = (long long *)malloc(sizeof(long long) * 5);
    for (int i = 0; i < 5; i++)
    {
        dp[i] = 1;
    }

    long long *ndp;
    ndp = (long long *)malloc(sizeof(long long) * 5);
    for (int i = 2; i <= n; i++)
    {
        // 1,2,3,4,5 in dp represent end as 'a','e','i','o','u'

        // before 'a' can be 'e','u','i'
        ndp[0] = (dp[1] + dp[2] + dp[4]) % mod_num;
        // before 'e' can be 'a','i'
        ndp[1] = (dp[0] + dp[2]) % mod_num;
        // before 'i' can be 'e','o'
        ndp[2] = (dp[1] + dp[3]) % mod_num;
        // before 'o' can be 'i'
        ndp[3] = (dp[2]) % mod_num;
        // before 'u' can be 'i','o'
        ndp[4] = (dp[2] + dp[3]) % mod_num;

        memcpy(dp, ndp, sizeof(long long) * 5);
    };
    long long ans = 0;
    for (int i = 0; i < 5; i++)
    {
        ans = (ans + dp[i]) % mod_num;
    }

    return ans;
}

//矩阵快速幂
typedef long long LL;
typedef LL *Mat;
#define index(x, y, col) ((x) * (col) + (y))

Mat multiply(const Mat matrixA, int matrixARowSize, int matrixAColSize,
             const Mat matrixB, int matrixBRowSize, int matrixBColSize,
             LL mod)
{
    Mat res = (LL *)malloc(sizeof(LL) * matrixARowSize * matrixBColSize);
    memset(res, 0, sizeof(LL) * matrixARowSize * matrixBColSize);

    for (int i = 0; i < matrixARowSize; i++)
    {
        for (int j = 0; j < matrixBColSize; j++)
        {
            for (int k = 0; k < matrixAColSize; k++)
            {
                res[index(i, j, matrixAColSize)] =
                    (res[index(i, j, matrixAColSize)] +
                     matrixA[index(i, k, matrixAColSize)] * matrixB[index(k, j, matrixBColSize)]) %
                    mod;
            }
        }
    }
    return res;
}
Mat fastPow(const Mat a, int matrixRowSize, LL n, LL mod)
{
    Mat res = (LL *)malloc(sizeof(LL) * matrixRowSize * matrixRowSize);
    Mat curr = (LL *)malloc(sizeof(LL) * matrixRowSize * matrixRowSize);

    memset(res, 0, sizeof(LL) * matrixRowSize * matrixRowSize);
    memset(curr, 0, sizeof(LL) * matrixRowSize * matrixRowSize);
    memcpy(curr, a, sizeof(LL) * matrixRowSize * matrixRowSize);

    for (int i = 0; i < matrixRowSize; i++) //对角线置1
    {
        res[index(i, i, matrixRowSize)] = 1;
    }
    while (n != 0)
    {
        if (n & 1)
        {
            Mat temp = multiply(curr, matrixRowSize, matrixRowSize,
                                res, matrixRowSize, matrixRowSize,
                                mod);
            res = temp;
        }

        n >>= 1;
        Mat temp = multiply(curr, matrixRowSize, matrixRowSize,
                            curr, matrixRowSize, matrixRowSize,
                            mod);
        curr = temp;
    }
    for (int i = 0; i < matrixRowSize * matrixRowSize; i++)
        printf("%d ", res[i]);
    return res;
}
int countVowelPermutation(int n)
{
    LL base[25] = {
        0, 1, 0, 0, 0,
        1, 0, 1, 0, 0,
        1, 1, 0, 1, 1,
        0, 0, 1, 0, 1,
        1, 0, 0, 0, 0};

    long long mod = 1e9 + 7;

    Mat res = fastPow(base, 5, n - 1, mod);
    int ans = 0;
    for (int i = 0; i < 25; i++)
    {
        ans = (ans + res[i]) % mod;
    }
    return ans;
}