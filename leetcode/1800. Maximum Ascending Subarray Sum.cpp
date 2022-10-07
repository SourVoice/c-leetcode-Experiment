#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <list>
using namespace std;
// ¶¯Ì¬¹æ»®
class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        int ans = nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > nums[i - 1])
                dp[i] = dp[i - 1] + nums[i];
            else
                dp[i] = nums[i];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
