// 39. 组合总和
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
// 回溯;递归
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        dfs(candidates, 0, target);
        return ans;
    }
    void dfs(vector<int> &candidates, int i, int target)
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
            target -= candidates[j];
            gen.push_back(candidates[j]);
            dfs(candidates, j, target); // 保留重复选用
            target += candidates[j];
            gen.pop_back();
        }
    }

private:
    vector<vector<int>> ans;
    vector<int> gen;
};