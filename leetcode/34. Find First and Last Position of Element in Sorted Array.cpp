// 34. 在排序数组中查找元素的第一个和最后一个位置
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//二分查找
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        if (nums.size() == 1 && target == nums[0])
            return vector<int>{0, 0};
        if (nums.empty())
            return vector<int>{-1, -1};
        int first = -1, last = -1, first_find = 0;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] >= target)
            {
                right = mid;
                if (nums[mid] == target)
                    first = mid, first_find = 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (first_find == 0 && nums[nums.size() - 1] == target)
            first = nums.size() - 1;
        left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target)
                right = mid - 1;
            else
            {
                left = mid + 1;
                if (nums[mid] == target)
                    last = mid;
            }
        }
        return vector<int>{first, last};
    }
};