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
// 排序
class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        sort(begin(nums), end(nums));
        int pre = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == pre)
                return pre;
            pre = nums[i];
        }
        return 0;
    }
};
// 哈希
class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto num : nums)
        {
            if (mp.count(num))
                return num;
            mp[num]++;
        }
        return 0;
    }
};
// O(1)空间, 原地哈希
class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        for (int i = 0; i < nums.size();)
        {
            if (nums[i] == i) // 只有相等时i才增加
            {
                i++;
                continue;
            }
            if (nums[nums[i]] == nums[i])
                return nums[i];
            swap(nums[nums[i]], nums[i]); // 使i处索引对应的值为i
        }
        return 0;
    }
};