// 198. 打家劫舍
#include <vector>
#include <cmath>
using namespace std;
//动态规划
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return fmax(nums[0], nums[1]);
        vector<int> dp(n + 1, 0);
        dp[0] = nums[0], dp[1] = fmax(nums[0], nums[1]); // 打劫的第二家需要从nums[0], nums[1]中取最大的
        int ret = 0;
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }
};