// 287. 寻找重复数
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
// 快慢指针
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;
        for (; slow != fast || fast == 0;)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        // nums不是有序的, 所以不一定在入口处相碰
        for (int i = 0; i != slow; i = nums[i])
        {
            slow = nums[slow];
        }
        return slow;
    }
};
// 二分, 抽屉原理
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int left = 1, right = nums.size() - 1;
        auto count = [&](const vector<int> &nums, int mid) -> int
        {
            int cnt = 0;
            for (auto &num : nums)
            {
                if (num <= mid)
                    cnt++;
            }
            return cnt;
        };
        while (left < right)
        {
            int mid = ((right - left) >> 1) + left;
            if (count(nums, mid) <= mid)
                left = mid + 1;
            else // 大于mid的数严格大于mid, 表示重复的数一定在左区间
                right = mid;
        }
        return left;
    }
};
