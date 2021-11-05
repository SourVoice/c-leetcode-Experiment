/*最长定差子序列*/
int longestSubsequence(int *arr, int arrSize, int difference)
{
    int dp[400001];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < arrSize; i++)
    {
        int v = arr[i] + 200000;
        dp[v] = dp[v - difference] + 1;
    }
    int max = 0;
    for (int i = 0; i < 210000; i++)
    {
        if (dp[i] > max)
        {
            max = dp[i];
        }
    }
    return max;
}
int longestSubsequence_Simplify(int *arr, int arrSize, int difference) //简化
{
    int dp[400001];
    memset(dp, 0, sizeof(dp));
    int max = 0;
    for (int i = 0; i < arrSize; i++)
    {
        int v = arr[i] + 200000;
        dp[v] = dp[v - difference] + 1;
        max = dp[v] > max ? dp[v] : max;
    }
    return max;
}