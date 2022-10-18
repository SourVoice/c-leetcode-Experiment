// 238. 除自身以外数组的乘积
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
// 双指针
// 常量空间
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);
        int l = 1, r = 1;
        for (int i = 1; i < n; i++)
        {
            l *= nums[i - 1];
            ans[i] = l;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            r = nums[i + 1] * r;
            ans[i] *= r;
        }
        return ans;
    }
};
// 优化
// 常量空间, 线性时间
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);
        int l = 1, r = 1;
        for (int i = 0; i < n; i++)
        {
            ans[i] *= l;
            ans[n - 1 - i] *= r;
            l *= nums[i];
            r *= nums[n - 1 - i];
        }
        return ans;
    }
};