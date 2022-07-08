// 213. 打家劫舍 II
#include <vector>
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
        vector<int> a(nums.begin(), nums.end() - 1), b(nums.begin() + 1, nums.end()); //不能偷窃第一间房屋为 [1 , n - 1], 不能偷窃最后一间为 [0 , n- 2]
        return fmax(helper(a), helper(b));
    }
    int helper(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return fmax(nums[0], nums[1]);
        vector<int> dp(n + 1, 0);
        dp[0] = nums[0], dp[1] = fmax(nums[0], nums[1]);
        int ret = 0;
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }
};