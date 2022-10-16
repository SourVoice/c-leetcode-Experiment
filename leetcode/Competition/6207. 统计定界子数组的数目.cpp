// 第 315 场周赛
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
// 贪心, 双指针
// 思路: leetcode user@灵茶山艾府
class Solution
{
public:
    typedef long long ll;
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        ll ans = 0L;
        int lastMinPos = -1, lastMaxPos = -1, t0 = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == minK)
                lastMinPos = i;
            if (nums[i] == maxK)
                lastMaxPos = i;
            if (nums[i] < minK || nums[i] > maxK)
                t0 = i;
            if (min(lastMinPos, lastMaxPos) < t0)
                continue;
            ans += min(lastMinPos, lastMaxPos) - t0;
        }
        return ans;
    }
};
