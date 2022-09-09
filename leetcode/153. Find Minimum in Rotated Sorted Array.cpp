// 153. 寻找旋转排序数组中的最小值
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;
// 8 ms, 在所有 C++ 提交中击败了 6.43 % 的用户
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return min(nums[0], nums[1]);
        if (nums[right] > nums[left])
            return nums[left];
        while (right - left > 1)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[left])
                left = mid;
            else if (nums[mid] < nums[right])
                right = mid;
        }
        return min(nums[left], nums[left + 1]);
    }
};
// 简化
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = (r - l) / 2 + l;
            if (nums[mid] < nums[r])
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return nums[l];
    }
};