// 264. 丑数 II
//动态规划,三指针法
int nthUglyNumber(int n)
{
    int *dp = (int *)calloc(n + 1, sizeof(int));
    dp[1] = 1;

    int p2 = 1;
    int p3 = 1;
    int p5 = 1;
    for (int i = 2; i <= n; i++)
    {
        int num2 = dp[p2] * 2; //下一个丑数
        int num3 = dp[p3] * 3; //
        int num5 = dp[p5] * 5; //
        dp[i] = fmin(fmin(num2, num3), num5);
        if (dp[i] == num2) //更新三个指针
            p2++;
        if (dp[i] == num3)
            p3++;
        if (dp[i] == num5)
            p5++;
    }
    return dp[n];
}
//优先队列