// 826. 安排工作以达到最大收益
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
// 贪心
class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int n = difficulty.size(), m = worker.size();
        int i = n - 1, j = m - 1;
        int ret = 0;
        vector<pair<int, int>> dif;
        for (int k = 0; k < n; k++)
            dif.push_back({difficulty[k], profit[k]});
        sort(begin(dif), end(dif), [&](const auto &a, const auto &b)
             { return a.second < b.second; });
        sort(begin(worker), end(worker));
        while (i >= 0 && j >= 0)
        {
            if (j >= 0 && dif[i].first <= worker[j])
            {
                j--;
                ret += dif[i].second;
            }
            else
            {
                i--;
            }
        }
        return ret;
    }
};