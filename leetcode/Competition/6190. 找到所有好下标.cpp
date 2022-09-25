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
// 3.超时
class Solution
{
public:
    vector<int> goodIndices(vector<int> &nums, int k)
    {
        vector<int> arr(nums.begin() + k, nums.end() - k);
        int n = nums.size();
        vector<int> ans;
        bool up = false, down = false;
        for (int i = k; i < n - k; i++)
        {
            for (int m = i - k; m + 1 < i; m++)
            {
                if (nums[m] >= nums[m + 1])
                    up = false;
                else
                {
                    up = true;
                    break;
                }
            }
            if (up)
                continue;
            for (int m = i + k; m - 1 > i; m--)
            {
                if (nums[m] >= nums[m - 1])
                    down = false;
                else
                {
                    down = true;
                    break;
                }
            }
            if (down)
                continue;
            if (!up && !down)
                ans.push_back(i);
        }
        return ans;
    }
};
// 状态记录, dp
class Solution
{
public:
    vector<int> goodIndices(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        vector<int> l(n, 1), g(n, 1); //以i结尾的非递增和非递减的长度
        for (int i = 1; i < n - 1; i++)
            if (nums[i - 1] >= nums[i])
                l[i] = l[i - 1] + 1;
        for (int i = n - 1; i > 0; i--)
            if (nums[i - 1] <= nums[i])
                g[i - 1] = g[i] + 1;
        for (int i = k; i < n - k; i++)
            if (l[i - 1] >= k && g[i + 1] >= k)
                ans.push_back(i);
        return ans;
    }
};
