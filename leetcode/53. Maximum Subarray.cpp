// 53. 最大子数组和
#include <vector>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size(), ret = nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]); // wether nums[i] as single or be added to former
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};