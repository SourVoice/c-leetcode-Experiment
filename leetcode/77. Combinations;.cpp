// 77. 组合
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
// 回溯法
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> t;
        vector<vector<int>> res;
        dfs(res, t, n, k, 1);
        return res;
    }
    void dfs(vector<vector<int>> &res, vector<int> &gen, int n, int k, int idx)
    {
        if (gen.size() == k)
        {
            res.push_back(gen);
            return;
        }
        for (int i = idx; i <= n; i++)
        {
            gen.push_back(i);
            dfs(res, gen, n, k, i + 1);
            gen.pop_back();
        }
    }
};
// 二刷
// dfs
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        this->totalNum = n;
        dfs(1, k);
        return ret;
    }
    void dfs(int index, int k)
    {
        if (gen.size() == k)
        {
            ret.push_back(gen);
        }
        for (int i = index; i <= totalNum; i++)
        {
            gen.push_back(i);
            dfs(i + 1, k);
            gen.pop_back();
        }
    }

private:
    int totalNum;
    vector<vector<int>> ret;
    vector<int> gen; // 记录一次的组合
};
