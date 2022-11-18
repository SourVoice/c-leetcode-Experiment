// 90. 子集 II
#include <string>
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
using namespace std;
// 朴素的
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(begin(nums), end(nums));
        vector<int> gen;
        for (int i = 0; i < n; i++)
            dfs(nums, ans, gen, i);
        return ans;
    }
    void dfs(vector<int> &nums, vector<vector<int>> &ans, vector<int> &gen, int i)
    {
        if (st.find(gen) == st.end())
        {
            st.emplace(gen);
            ans.push_back(gen);
        }
        for (int j = i; j < nums.size(); j++)
        {
            gen.push_back(nums[j]);
            dfs(nums, ans, gen, j + 1);
            gen.pop_back();
        }
    }

private:
    set<vector<int>> st;
};
// 改进
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> gen;
        sort(begin(nums), end(nums));
        dfs(nums, ans, gen, 0);
        return ans;
    }
    void dfs(vector<int> &nums, vector<vector<int>> &ans, vector<int> &gen, int i)
    {
        if (st.find(gen) == st.end())
        {
            st.emplace(gen);
            ans.push_back(gen);
        }
        for (int j = i; j < nums.size(); j++)
        {
            gen.push_back(nums[j]);
            dfs(nums, ans, gen, j + 1);
            gen.pop_back();
        }
    };

private:
    set<vector<int>> st;
};
// 继续优化
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> gen;
        sort(begin(nums), end(nums)); // 去重必要条件
        dfs(nums, ans, gen, 0);
        return ans;
    }
    void dfs(vector<int> &nums, vector<vector<int>> &ans, vector<int> &gen, int i)
    {
        ans.push_back(gen);
        for (int j = i; j < nums.size(); j++)
        {
            if (j > i && nums[j] == nums[j - 1]) // 去重
                continue;
            gen.push_back(nums[j]);
            dfs(nums, ans, gen, j + 1);
            gen.pop_back();
        }
    };
};