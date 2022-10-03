// 1488. 避免洪水泛滥
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <list>
using namespace std;
// 贪心;哈希表;二分查找
// 正确做法, 超时
class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        int n = rains.size();
        map<int, int> mp; // 记录湖最后一次的下雨日子
        vector<int> ans(n, -1);
        set<int> dryDay;
        for (int i = 0; i < n; i++)
        {
            int lake = rains[i];
            if (lake == 0)
            {
                dryDay.insert(i);
                ans[i] = 1;
                continue;
            }
            if (mp.find(lake) != mp.end())
            {
                // 取 在mp[rains[i]] 和i 之间的最小
                // 即 第一个大于mp[rains[i]]的
                auto it = lower_bound(begin(dryDay), end(dryDay), mp[lake]);
                if (it == dryDay.end())
                    return {};
                ans[*it] = lake;
                dryDay.erase(it);
            }
            mp[lake] = i;
        }
        return ans;
    }
};
// 改掉lower_bound
class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        int n = rains.size();
        map<int, int> mp; // 记录湖最后一次的下雨日子
        vector<int> ans(n, -1);
        set<int> dryDay;
        for (int i = 0; i < n; i++)
        {
            int lake = rains[i];
            if (lake == 0)
            {
                dryDay.insert(i);
                ans[i] = 1;
                continue;
            }
            if (mp.find(lake) != mp.end())
            {
                // 取 在mp[rains[i]] 和i 之间的最小
                // 即 第一个大于mp[rains[i]]的
                auto it = dryDay.lower_bound(mp[lake]);
                if (it != dryDay.end())
                    ans[*it] = lake, dryDay.erase(it);
                else
                    return vector<int>();
            }
            mp[lake] = i;
        }
        return ans;
    }
};