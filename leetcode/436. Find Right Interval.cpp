// 436. 寻找右区间
#include <map>
#include <vector>
#include <iostream>
#include <unordered_map>
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

// 双指针