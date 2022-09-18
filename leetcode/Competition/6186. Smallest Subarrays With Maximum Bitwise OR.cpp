// 6186. 按位或最大的最小子数组长度
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
using namespace std;
// 贪心
class Solution
{
public:
    vector<int> smallestSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> pos(32, 0); // pos[i] 记录该处bit 1最早在nums出现的位置
        for (int i = n - 1; i >= 0; i--)
        {
            int num = nums[i];
            for (int bitwise = 0; bitwise < 32; bitwise++)
            {
                if ((1 << bitwise) & num)
                {
                    pos[bitwise] = i;
                }
            }
            for (int bitwise = 0; bitwise < 32; bitwise++)
            {
                ans[i] = max(ans[i], pos[bitwise] - i + 1);
            }
        }
        return ans;
    }
};