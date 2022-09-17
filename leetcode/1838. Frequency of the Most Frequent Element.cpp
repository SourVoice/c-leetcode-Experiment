// 1838. 最高频元素的频数
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
// 滑动窗口+前缀和
class Solution
{
public:
    typedef long long ll;
    int maxFrequency(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end(), std::less<int>());
        int i = 0, j = 1, ret = 1;
        ll sum_prefix = nums[0];
        while (j < n)
        {
            sum_prefix += nums[j];
            // 我们假设k分配给了前缀和部分的数组, 使这一部分数全部变为nums[j]
            while (j > i && ((static_cast<ll>(nums[j]) * static_cast<ll>(j - i + 1)) - sum_prefix) > k)
                sum_prefix -= nums[i++];
            ret = max(ret, j - i + 1);
            j++;
        }
        return ret;
    }
};