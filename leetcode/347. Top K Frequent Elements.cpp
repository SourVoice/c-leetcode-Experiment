// 347. 前 K 个高频元素
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
// 哈希表+优先队列
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        map<int, int> counter;
        for (auto e : nums)
            ++counter[e];
        auto cmp = [&](const auto &a, const auto &b) -> bool
        {
            return a.second > b.second;
        };
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (auto &[val, times] : counter)
        {
            pq.push({val, times});
            if (pq.size() > k)
                pq.pop();
        }
        while (!pq.empty())
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};