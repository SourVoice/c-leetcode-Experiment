// 973. 最接近原点的 K 个点
#include <vector>
#include <map>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <deque>
#include <queue>
using namespace std;
// 优先队列
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        auto cmp = [](const auto &a, const auto &b) -> bool
        {
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < points.size(); i++)
        {
            int d_2 = powl(points[i][0], 2) + powl(points[i][1], 2);
            pq.push({i, d_2});
            if (pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while (!pq.empty())
        {
            ans.push_back(points[pq.top().first]);
            pq.pop();
        }
        return ans;
    }
};