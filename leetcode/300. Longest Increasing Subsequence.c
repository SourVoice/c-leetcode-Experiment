// 300. 最长递增子序列

#include <limits.h>
#include <stdbool.h>
#include <math.h>

//动态规划法
int lengthOfLIS(int *nums, int numsSize)
{
    int dp[11000];
    for (int i = 0; i < numsSize; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = fmax(dp[i], dp[j] + 1);
            }
        }
    }
    int max = 0;
    for (int i = 0; i < 11000; i++)
    {
        if (dp[i] > max)
            max = dp[i];
    }
    return max;
}
//贪心+二分
