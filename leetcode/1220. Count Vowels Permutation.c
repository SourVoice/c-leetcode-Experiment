// 1220. ͳ��Ԫ����ĸ���е���Ŀ
//��̬�滮
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>

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

//���������
typedef long long LL;
typedef LL *Mat;
#define IDX(x, y, col) ((x) * (col)) + (y)

Mat *multiply(const Mat matrixA, int matrixARowSize, int matrixColSize,
              const Mat matrixB, int matrixBRow, int matrixBColSize,
              LL mod)
{
    Mat res = (LL *)malloc(sizeof(LL) * matrixARowSize * matrixBColSize);
}
