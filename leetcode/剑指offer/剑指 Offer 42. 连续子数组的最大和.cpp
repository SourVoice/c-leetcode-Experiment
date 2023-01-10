#include <string>
#include <stack>
#include <functional>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int maxsum = nums[0];
        for (int i = 1; i < n; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            maxsum = max(maxsum, dp[i]);
        }
        return maxsum;
    }
};