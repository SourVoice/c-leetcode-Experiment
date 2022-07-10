// 740. 删除并获得点数
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int n = nums.size();
        int siz_e = *max_element(nums.begin(), nums.end());
        vector<int> sum(siz_e + 1, 0);
        for (auto elem : nums)
        {
            sum[elem] += elem;
        }
        vector<int> dp(sum.size(), 0);
        dp[0] = sum[0], dp[1] = max(sum[0], sum[1]);
        for (int i = 2; i < sum.size(); i++)
        {
            dp[i] = max(dp[i - 2] + sum[i], dp[i - 1]);
        }
        return dp[sum.size() - 1];
    }
};