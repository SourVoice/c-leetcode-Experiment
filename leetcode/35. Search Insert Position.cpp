/// 35. ËÑË÷²åÈëÎ»ÖÃ
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int ans = nums.size();
        while (left <= right)
        {
            int mid = (left - right) / 2 + right, ret = nums[mid];
            if (ret <= target)
                left = mid + 1;
            else if (ret >= target)
                right = mid - 1, ans = mid;
        }
        return ans;
    }
};