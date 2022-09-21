// 162. 寻找峰值
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
// 递归分治
class Solution
{
public:
    int search(vector<int> &nums, int start, int end)
    {
        if (end - start < 2)
            return -1;
        int i = (start + end) / 2;
        if (i > 0 && i < nums.size() - 1 && nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
            return i;
        if (start == 0 && nums[start] > nums[start + 1])
            return start;
        if (end == nums.size() - 1 && nums[end] > nums[end - 1])
            return end;
        int l = search(nums, start, (start + end) / 2);
        int r = search(nums, (start + end) / 2, end);
        return l == -1 ? r : l;
    }
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        if (n == 2)
            return nums[0] > nums[1] ? 0 : 1;
        return search(nums, 0, n - 1);
    }
};
// 二分
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};