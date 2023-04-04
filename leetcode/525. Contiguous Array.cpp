// 525. 连续数组
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp; // record each prefix's first appear pos
        mp[0] = -1;
        int prefix_sum = 0;
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            prefix_sum += (nums[i] == 1 ? 1 : -1);
            if (!mp.count(prefix_sum))
            {
                mp[prefix_sum] = i;
            }
            else
            {
                ret = max(ret, i - mp[prefix_sum]);
            }
        }
        return ret;
    }
};