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
// 二分
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        int leftB = 0;
        // 左边界
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        } // 第一个小于目标
        leftB = l;
        l = 0, r = nums.size() - 1;
        int rightB = 0;
        // 右边界
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        rightB = l;
        return rightB - leftB;
    }
};