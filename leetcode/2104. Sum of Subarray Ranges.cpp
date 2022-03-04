// 2104. 子数组范围和

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

// timeout
class Solution
{
public:
    long long subArrayRanges(std::vector<int> &nums)
    {
        long long sum = 0;
        long long ans = 0;
        int n = nums.size();
        std::vector<int>::iterator it = nums.begin();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                auto small = min_element(it + i, it + j + 1); // C++11
                auto big = max_element(it + i, it + j + 1);
                ans += *big - *small;
            }
        }
        return ans;
    }
};

//优化
class Solution
{
public:
    long long subArrayRanges(std::vector<int> &nums)
    {
        long long sum = 0;
        long long ans = 0;
        int n = nums.size();
        std::vector<int>::iterator it = nums.begin();
        for (int i = 0; i < n; i++)
        {
            int min_cache = nums[i];
            int max_cache = nums[i];
            for (int j = i + 1; j < n; j++)
            {
                min_cache = min(min_cache, nums[j]);
                max_cache = max(max_cache, nums[j]);
                ans += max_cache - min_cache;
            }
        }
        return ans;
    }
};

//单调栈
class Solution
{
public:
    long long subArrayRanges(std::vector<int> &nums)
    {
        int n = nums.size();
        vector<int> minRight(n), maxRight(n), minLeft(n), maxLeft(n);
        stack<int> minIndex, maxIndex;
        for (int i = 0; i < n; i++)
        {

            // i左侧比nums[i]小的值
            while (!minIndex.empty() && nums[minIndex.top()] > nums[i])
            {
                minIndex.pop();
            }
            minLeft[i] = minIndex.empty() ? -1 : minIndex.top();
            minIndex.push(i);

            // i左侧比nums[i]大的值
            while (!maxIndex.empty() && nums[maxIndex.top()] <= nums[i])
            {
                maxIndex.pop();
            }
            maxLeft[i] = maxIndex.empty() ? -1 : maxIndex.top();
            maxIndex.push(i);
        }
        minIndex = stack<int>();
        maxIndex = stack<int>();
        for (int i = n - 1; i >= 0; i--)
        {
            // i右侧比nums[i]小的值
            while (!minIndex.empty() && nums[minIndex.top()] >= nums[i])
            {
                minIndex.pop();
            }
            minRight[i] = minIndex.empty() ? n : minIndex.top();
            minIndex.push(i);

            // i右侧比nums[i]大的值
            while (!maxIndex.empty() && nums[maxIndex.top()] < nums[i])
            {
                maxIndex.pop();
            }
            maxRight[i] = maxIndex.empty() ? n : maxIndex.top();
            maxIndex.push(i);
        }
        long long minSubarrSum = 0;
        long long maxSubarrSum = 0;
        for (int i = 0; i < n; i++)
        {
            minSubarrSum += static_cast<long long>(i - minLeft[i]) * (minRight[i] - i) * nums[i];
            maxSubarrSum += static_cast<long long>(i - maxLeft[i]) * (maxRight[i] - i) * nums[i];
        }
        return maxSubarrSum - minSubarrSum;
    }
};