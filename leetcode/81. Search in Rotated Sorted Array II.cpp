// 81. 搜索旋转排序数组 II
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;
// 暴力法
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n <= 10 && find(begin(nums), end(nums), target) != end(nums))
            return true;
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            while (left < right && nums[left] == nums[left + 1])
                left++;
            while (left < right && nums[right] == nums[right - 1])
                right--;
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < nums[left])
            { //右侧有序
                if (target == nums[right])
                    return right;
                if (target > nums[mid] && target < nums[right])
                { //保留右侧
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }
            else
            { //左侧有序
                if (target == nums[left])
                    return left;
                if (target < nums[mid] && target > nums[left])
                { // 保留左侧
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }
        }
        return false;
    }
};
// 去重
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n <= 10 && find(begin(nums), end(nums), target) != end(nums))
            return true;
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int &l = left, &r = right;
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            // 当出现 nums[l] == nums[mid] 并且 nums[r] == nums[mid] 时我们无法判断那一侧是有序的
            if (nums[l] == nums[mid] && nums[mid] == nums[r]) //去重
                ++l, --r;
            else if (nums[mid] < nums[left])
            { //右侧有序
                if (target == nums[right])
                    return right;
                if (target > nums[mid] && target < nums[right]) //保留右侧
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else
            { //左侧有序
                if (target == nums[left])
                    return left;
                if (target < nums[mid] && target > nums[left]) // 保留左侧
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return false;
    }
};