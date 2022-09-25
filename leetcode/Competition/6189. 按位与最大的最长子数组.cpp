//
// 与运算, 脑筋急转弯,
// 与运算会逐渐减小运算值, 一个数组与运算最大为数组全体元素
// 我们只需要找到连续最大元素的个数即可
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
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int max_ = *max_element(begin(nums), end(nums));
        int cnt = 0, ret = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == max_)
                cnt++;
            else
                ret = max(cnt, ret), cnt = 0;
        }
        return max(cnt, ret);
    }
};