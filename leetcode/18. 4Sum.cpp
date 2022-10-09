// 18. 四数之和
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
// 暴力
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                for (int k = j + 1; j < nums.size(); k++)
                    for (int v = k + 1; v < nums.size(); v++)
                    {
                        if (nums[i] + nums[j] + nums[k] + nums[v] == target)
                        {
                            if (!st.count({nums[i], nums[j], nums[k], nums[v]}))
                                ans.push_back({nums[i], nums[j], nums[k], nums[v]});
                        }
                    }
        return ans;
    }
};
// 双指针
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                // 双指针
                int l = j + 1, r = n - 1;
                long tar = static_cast<long>(target) - nums[i] - nums[j];
                while (l < r)
                {
                    if (nums[l] + nums[r] == tar)
                    {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l + 1] == nums[l])
                            l++;
                        l++;
                        while (l < r && nums[r - 1] == nums[r])
                            r--;
                        r--;
                    }
                    else if (nums[l] + nums[r] < tar)
                        l++;
                    else if (nums[l] + nums[r] > tar)
                        r--;
                }
                while (j < n - 1 && nums[j + 1] == nums[j])
                    j++;
            }
            while (i < n - 2 && nums[i + 1] == nums[i])
                i++;
        }
        return ans;
    }
};
// 双指针优化;剪枝
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++)
        {
            // 剪枝
            if (static_cast<long>(nums[i]) + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if (static_cast<long>(nums[i]) + nums[n - 1] + nums[n - 2] + nums[n - 3] < target)
                continue;
            for (int j = i + 1; j < n - 2; j++)
            {
                // 剪枝
                if (static_cast<long>(nums[i]) + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                if (static_cast<long>(nums[i]) + nums[j] + nums[n - 1] + nums[n - 2] < target)
                    continue;

                // 双指针
                int l = j + 1, r = n - 1;
                long tar = static_cast<long>(target) - nums[i] - nums[j];
                while (l < r)
                {
                    if (nums[l] + nums[r] == tar)
                    {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        // 去重
                        while (l < r && nums[l + 1] == nums[l])
                            l++;
                        l++;
                        while (l < r && nums[r - 1] == nums[r])
                            r--;
                        r--;
                    }
                    else if (nums[l] + nums[r] < tar)
                        l++;
                    else if (nums[l] + nums[r] > tar)
                        r--;
                }
                // 去重
                while (j < n - 2 && nums[j + 1] == nums[j])
                    j++;
            }
            // 去重
            while (i < n - 3 && nums[i + 1] == nums[i])
                i++;
        }
        return ans;
    }
};
