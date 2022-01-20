// 1137. 第 N 个泰波那契数
#include <iostream>
#include <vector>
//动态规划
int tribonacci(int n)
{
    long long dp[10000];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 0; i < n; i++)
    {
        dp[i + 3] = dp[i] + dp[i + 1] + dp[i + 2];
    }
    return dp[n];
}
//递归法
//记忆化递归
int cache[50];
int tribonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    if (!cache[n])
        cache[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    return cache[n];
}
//矩阵快速幂
class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n <= 2)
            return 1;
        std::vector<std::vector<long>> q = {{1, 1, 1},
                                            {1, 0, 0},
                                            {0, 1, 0}};
        std::vector<std::vector<long>> res = pow(q, n);
        return res[0][2];
    }
    std::vector<std::vector<long>> pow(std::vector<std::vector<long>> &a, long n)
    {
        std::vector<std::vector<long>> ret = {{1, 0, 0},
                                              {0, 1, 0},
                                              {0, 0, 1}};
        while (n > 0) //快速幂
        {
            if ((n & 1) == 1)
            {
                ret = multply(ret, a);
            }
            n = n >> 1;
            a = multply(a, a); // a*a
        }
        return ret;
    }
    std::vector<std::vector<long>> multply(std::vector<std::vector<long>> &a, std::vector<std::vector<long>> &b)
    {
        std::vector<std::vector<long>> c(3, std::vector<long>(3));
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
            }
        }
        return c;
    }
};