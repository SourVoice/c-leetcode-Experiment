// 797. 所有可能的路径
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
// 回溯;深度优先搜索
class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> ans;
        vector<int> gen;
        gen.push_back(0);
        for (int i = 0; i < graph[0].size(); i++)
        {
            gen.push_back(graph[0][i]);
            dfs(graph, graph[0][i], ans, gen);
            gen.pop_back();
        }
        return ans;
    }
    void dfs(vector<vector<int>> &graph, int j, vector<vector<int>> &ans, vector<int> &gen)
    {
        if (j == graph.size() - 1)
            ans.push_back(gen);
        for (int i = 0; i < graph[j].size(); i++)
        {
            gen.push_back(graph[j][i]);
            dfs(graph, graph[j][i], ans, gen);
            gen.pop_back();
        }
    }
};