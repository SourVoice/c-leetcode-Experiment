// 46. È«ÅÅÁÐ
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> visited(nums.size(), 0);
        vector<int> gen;
        dfs(nums, ans, visited, gen);
        return ans;
    }
    void dfs(vector<int> &nums, vector<vector<int>> &res, vector<int> &visited, vector<int> &gen)
    {
        if (nums.size() == gen.size())
        {
            res.push_back(gen);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i])
            {
                continue;
            }
            visited[i] = 1;
            gen.push_back(nums[i]);
            dfs(nums, res, visited, gen);
            gen.pop_back();
            visited[i] = 0;
        }
    }
};