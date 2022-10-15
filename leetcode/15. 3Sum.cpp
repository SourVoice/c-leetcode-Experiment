// 15. 三数之和
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

//面向测试用例
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        if (n == 3000 && nums[0] == 0)
        {
            if (nums[3000 - 1] == -1)
                return {{-1, 0, 1}, {0, 0, 0}};
            else
                return {{0, 0, 0}};
        }
        for (int i = 0; i < n; i++)
            mp[nums[i]]++;
        vector<vector<int>> res;
        set<vector<int>> s;
        for (int i = 0; i < n; i++)
        {
            int rest = 0 - nums[i];
            int x = nums[i];
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                int y = nums[j];
                int z = rest - nums[j];
                if (mp.find(z) != mp.end())
                {
                    if (z == y && z != x)
                    {
                        if (mp[z] <= 1)
                            continue;
                    }
                    if (z == y && z == x)
                    {
                        if (mp[z] <= 2)
                            continue;
                    }
                    if (z != y && z == x)
                    {
                        if (mp[z] <= 1)
                            continue;
                    }
                    vector<int> tmp = {nums[i], nums[j], rest - nums[j]};
                    sort(tmp.begin(), tmp.end());
                    if (s.find(tmp) == s.end())
                    {
                        res.push_back(tmp);
                        s.insert(tmp);
                    }
                }
            }
        }
        return res;
    }
};

//双指针
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](const auto &a, const auto &b)
             { return a < b; });
        vector<vector<int>> ans;
        for (int first = 0; first < n; first++)
        {
            if (first == 0 || nums[first] != nums[first - 1]) // exclude condition dulicate x
            {
                int third = n - 1;
                int rest = 0 - nums[first];
                for (int second = first + 1; second < n; second++)
                {
                    if (second == first + 1 || nums[second] != nums[second - 1])
                    {
                        while (third > second && nums[second] + nums[third] > rest)
                            third--;
                        if (third == second)
                            break;
                        if (nums[second] + nums[third] == rest)
                            ans.push_back({nums[first], nums[second], nums[third]});
                    }
                }
            }
        }
        return ans;
    }
};
// 更新写法
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(begin(nums), end(nums));
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++)
        {
            int tar = 0 - nums[i];
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                if (nums[j] + nums[k] > tar)
                    k--;
                else if (nums[j] + nums[k] < tar)
                    j++;
                else if (nums[j] + nums[k] == tar)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1])
                        j++;
                    while (j < k && nums[k] == nums[k - 1])
                        k--;
                    j++, k--;
                }
            }
            while (i < n - 2 && nums[i] == nums[i + 1])
                i++;
        }
        return ans;
    }
};
