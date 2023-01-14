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
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        vector<int> ret;
        while (l < r)
        {
            int s = nums[l] + nums[r];
            if (s > target)
                r--;
            else if (s < target)
                l++;
            else
                return vector<int>{nums[l], nums[r]};
        }
        return vector<int>{};
    }
};