// 704. 二分查找
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
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l - r) / 2 + r, ret = nums[mid];
            if (ret < target)
                l = mid + 1;
            else if (ret > target)
                r = mid - 1;
            else
                return mid;
        }
        return -1;
    }
};