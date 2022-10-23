// 316场周赛
// 6216. 使数组相等的最小开销
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
// 中位数贪心       (462题)
class Solution
{
public:
    typedef long long ll;
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        int n = nums.size();
        vector<pair<ll, ll>> arr(n);
        ll sumCost = 0;
        for (int i = 0; i < n; i++)
        {
            arr[i] = {nums[i], cost[i]};
            sumCost += cost[i];
        }
        ll mid = sumCost / 2; // 总开销中位数
        sort(arr.begin(), arr.end());
        ll ans = 0;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += (ll)arr[i].second; // 数组两侧开销平分
            if (sum >= mid)
            {
                for (int j = 0; j < n; j++)
                    ans += (ll)arr[j].second * (ll)(abs(arr[j].first - arr[i].first));
                return ans;
            }
        }
        return ans;
    }
};
// 枚举
class Solution
{
public:
    typedef long long ll;
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        int n = nums.size();
        vector<pair<ll, ll>> arr(n);
        ll sumCost = 0;
        for (int i = 0; i < n; i++)
        {
            arr[i] = {nums[i], cost[i]};
            sumCost += cost[i];
        }
        sort(begin(arr), end(arr));
        ll totalCost = 0;
        for (int i = 0; i < n; i++)
            totalCost += abs(arr[i].first - arr[0].first) * arr[i].second;
        ll ans = totalCost;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                /// @brief erroe
                /// @param nums
                /// @param cost
                /// @return
                sumCost -= (arr[i].first - arr[j].first) * arr[j].second;
                totalCost += sumCost * (arr[j].first - arr[i].first) - 2 * (arr[i].first - arr[j].first) * arr[j].second;
                ans = min(totalCost, ans);
            }
        }
        return ans;
    }
};
// error
class Solution
{
public:
    typedef long long ll;
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        int n = nums.size();
        vector<pair<ll, ll>> arr(n);
        ll sumCost = 0;
        for (int i = 0; i < n; i++)
        {
            arr[i] = {nums[i], cost[i]};
            sumCost += cost[i];
        }
        sort(begin(arr), end(arr));
        ll totalCost = 0;
        for (int i = 0; i < n; i++)
            totalCost += abs(arr[i].first - arr[0].first) * arr[i].second;
        ll ans = totalCost;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                ll d = arr[i].first - arr[j].first;
                sumCost -= arr[j].second * 2;
                totalCost -= sumCost * d;
                ans = min(totalCost, ans);
            }
        }
        return ans;
    }
};
// 二分
class Solution
{
public:
    typedef long long ll;
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        int n = nums.size();
        ll l = *min_element(begin(nums), end(nums));
        ll r = *max_element(begin(nums), end(nums));
        while (l <= r)
        {
            int mid = ((r - l) >> 1) + l;
            ll co_mid = 0, co_mid_high = 0;
            for (int i = 0; i < n; i++)
            {
                co_mid += (ll)abs(nums[i] - mid) * cost[i];
                co_mid_high += (ll)abs(nums[i] - (mid + 1)) * cost[i];
            }

            if (co_mid < co_mid_high) // 寻找更小开销
                r = mid - 1;
            else
                l = mid + 1;
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
            ans += (ll)abs(nums[i] - l) * cost[i];
        return ans;
    }
};