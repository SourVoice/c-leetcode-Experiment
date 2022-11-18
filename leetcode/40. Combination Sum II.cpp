// 40. 组合总和 II
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
// 递归;回溯;去重
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(begin(candidates), end(candidates));
        int n = candidates.size();
        vector<int> visited(n, 0);
        dfs(candidates, visited, 0, target);
        return ans;
    }
    void dfs(vector<int> &candidates, vector<int> &visited, int i, int target)
    {
        if (target == 0)
        {
            ans.push_back(gen);
            return;
        }
        if (target < 0)
            return;
        for (int j = i; j < candidates.size(); j++)
        {
            if (j > 0 && candidates[j - 1] == candidates[j] && !visited[j - 1]) // 去重
                continue;
            visited[j] = 1;
            target -= candidates[j];
            gen.push_back(candidates[j]);
            dfs(candidates, visited, j + 1, target); // 不可重复使用
            target += candidates[j];
            gen.pop_back();
            visited[j] = 0;
        }
    }

private:
    vector<vector<int>> ans;
    vector<int> gen;
};