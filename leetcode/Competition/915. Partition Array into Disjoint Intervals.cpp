// 915. 分割数组
#include <string>
#include <stack>
#include <bitset>
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
    int partitionDisjoint(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> helper(n);
        helper[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            helper[i] = min(helper[i + 1], nums[i]);
        // 左边最大的小于等于右边最小
        int maxL = 0;
        for (int i = 0; i < n - 1; i++)
        {
            maxL = max(nums[i], maxL);
            if (maxL <= helper[i + 1])
                return i + 1;
        }
        return 0;
    }
};