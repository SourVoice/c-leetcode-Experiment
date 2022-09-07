// 33. 搜索旋转排序数组
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;
// 二分查找
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
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
        return -1;
    }
};