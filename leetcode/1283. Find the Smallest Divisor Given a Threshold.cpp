// 1283. 使结果不超过阈值的最小除数
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int l = 1, r = nums[n - 1];
        auto countDivideSum = [&](const vector<int> &nums, int div)
        {
            int sum = 0;
            for (auto &num : nums)
            {
                sum += num / div;
                if (num % div != 0 || num < div)
                    sum++;
            }
            return sum;
        };
        int ret = INT_MAX;
        while (l <= r)
        {
            int mid = ((r - l) >> 1) + l;
            int sumOfDiv = countDivideSum(nums, mid);
            if (sumOfDiv <= threshold)
            {
                r = mid - 1;
                ret = min(ret, mid);
            }
            else
                l = mid + 1;
        }
        return ret;
    }
};
// 返回左侧
class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int length = nums.size();
        int l = 1;
        int r = *max_element(nums.begin(), nums.end()) + 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            int total = 0;
            for (int num : nums)
            {
                total += (num - 1) / mid + 1; // 向上取整
            }
            if (total <= threshold)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};