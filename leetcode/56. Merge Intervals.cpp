// 56. 合并区间
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
// 双指针;贪心
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(begin(intervals), end(intervals));

        vector<int> arr = intervals[intervals.size() - 1];
        vector<vector<int>> ans;
        int i = 0, j = 0;
        for (int i = 0; i < intervals.size(); i++)
        {
            int cnt = 0;
            int maxEnd = intervals[i][1]; // rec the max of the right
            for (int j = i + 1; j < intervals.size(); j++)
            {
                if (intervals[j][0] <= maxEnd)
                    cnt++, maxEnd = max(maxEnd, intervals[j][1]);
            }
            vector<int> arr(2, 0);
            arr[0] = intervals[i][0], arr[1] = max(maxEnd, intervals[i][1]);
            ans.push_back(arr);
            i += cnt;
        }
        return ans;
    }
};
