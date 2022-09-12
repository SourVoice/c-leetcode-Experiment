// 209. 长度最小的子数组
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
// 滑动窗口
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        int len = INT_MAX;
        int j = 0;
        if (accumulate(begin(nums), end(nums), 0) < target)
            return 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            while (sum >= target)
            {
                len = min(len, i - j + 1);
                sum -= nums[j++];
            }
        }
        return len;
    }
};
// TODO: 前缀和 + 二分查找