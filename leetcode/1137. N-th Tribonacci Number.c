// 1137. 第 N 个泰波那契数

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