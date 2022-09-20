// 436. 寻找右区间
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

// 哈希表
class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        map<int, int> mp; // must use map instead of unordered_map
        for (int i = 0; i < intervals.size(); i++)
        {
            mp[intervals[i][0]] = i;
        }
        vector<int> ans;
        for (int i = 0; i < intervals.size(); i++)
        {
            auto it = mp.lower_bound(intervals[i][1]); //返回map中第一个大于或等于key的迭代器指针
            if (it == mp.end())
                ans.push_back(-1);
            else
                ans.push_back(it->second);
        }
        return ans;
    }
};
// 二分查找
class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        vector<pair<vector<int>, int>> vec;
        int n = intervals.size();
        for (int i = 0; i < n; i++)
            vec.push_back({intervals[i], i});
        sort(begin(vec), end(vec), [&](const auto &a, const auto &b)
             { return a.first[0] < b.first[0]; });
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++)
        {
            auto it = upper_bound(vec.begin(), vec.end(), intervals[i][1],
                                  [&](auto a, const pair<vector<int>, int> &b)
                                  { return a <= b.first[0]; });
            if (it != vec.end())
                ans[i] = (*it).second;
        }
        return ans;
    }
};