// 78. 子集
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
// 回溯
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
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
// 更好的:
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> gen;
        dfs(nums, ans, gen, 0);
        return ans;
    }
    void dfs(vector<int> &nums, vector<vector<int>> &ans, vector<int> &gen, int i)
    {
        ans.push_back(gen);
        for (int j = i; j < nums.size(); j++)
        {
            gen.push_back(nums[j]);
            dfs(nums, ans, gen, j + 1);
            gen.pop_back();
        }
    };
};