// 77. 组合

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