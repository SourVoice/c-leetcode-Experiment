// 560. 和为 K 的子数组
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
// 哈希表;前缀和
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        prefix[1] = nums[0];
        for (int i = 1; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        int ans = 0;
        unordered_map<int, int> mp;
        for (auto &num : prefix)
        {
            int tar = num - k;
            if (mp.count(tar))
                ans += mp[tar];
            mp[num]++;
        }
        return ans;
    }
};
