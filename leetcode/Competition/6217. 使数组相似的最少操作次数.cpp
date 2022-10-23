
#include <string>
#include <stack>
#include <bitset>
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
// 贪心;奇偶讨论
class Solution
{
public:
    typedef long long ll;
    long long makeSimilar(vector<int> &nums, vector<int> &target)
    {
        int n = nums.size();
        sort(begin(nums), end(nums));
        sort(begin(target), end(target));
        ll ans = 0;
        int jodd = 0, jeven = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] & 1) // odd
            {
                while (!(target[jodd] & 1))
                    jodd += 1;
                ans += abs(target[jodd] - nums[i]);
                jodd++;
            }
            else
            {
                while (target[jeven] & 1)
                    jeven++;
                ans += abs(target[jeven] - nums[i]);
                jeven++;
            }
        }
        return ans / 4;
    }
};
// 简化
class Solution
{
public:
    typedef long long ll;
    long long makeSimilar(vector<int> &nums, vector<int> &target)
    {
        int n = nums.size();
        sort(begin(nums), end(nums));
        sort(begin(target), end(target));
        ll ans = 0;
        int j[2] = {0}; // 使用数组记录奇偶下标
        for (auto &num : nums)
        {
            int s = num & 1;
            while ((target[j[s]] & 1) != s)
                j[s]++;
            ans += abs(target[j[s]] - num);
            j[s]++;
        }
        return ans / 4;
    }
};