// 451. 根据字符出现频率排序
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
// 优先队列;哈希表
class Solution
{
public:
    string frequencySort(string s)
    {
        int n = s.size();
        map<char, int> counter;
        for (auto ch : s)
            ++counter[ch];
        auto cmp = [&](const auto &a, const auto &b) -> bool
        {
            return a.second < b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        for (auto &[val, times] : counter)
            pq.push({val, times});
        string ans;
        while (!pq.empty())
        {
            char ch = pq.top().first;
            for (int i = 0; i < pq.top().second; i++)
                ans.push_back(ch);
            pq.pop();
        }
        return ans;
    }
};