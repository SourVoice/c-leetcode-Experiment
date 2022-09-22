// 154. 寻找旋转排序数组中的最小值 II
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
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            // 每次选择无序一侧
            if (nums[mid] < nums[r])
                r = mid;
            else if (nums[mid] > nums[r])
                l = mid + 1;
            else // 保证当nums[mid]==nums[r]相同时能够取到无序一侧, 并保证防止重复元素为最小元素
                r--;
        }
        return nums[l];
    }
};