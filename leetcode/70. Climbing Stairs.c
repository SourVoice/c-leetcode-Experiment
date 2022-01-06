// 70. 爬楼梯
//简单动态规划
int climbStairs(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    long dp[1000];
    memset(dp, 0, 1000 * sizeof(1000));
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n - 1];
}