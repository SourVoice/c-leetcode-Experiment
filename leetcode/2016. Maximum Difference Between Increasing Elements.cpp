// 2016. 增量元素之间的最大差值

#include <vector>
using namespace std;

// violence
class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int max = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                max = max > nums[j] - nums[i] ? max : nums[j] - nums[i];
            }
        }
        return max > 0 ? max : -1;
    }
};

// set cache for min before i

class Solution2
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int minBeforI = nums[0]; // cache
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > minBeforI)
            {
                ans = max(ans, nums[i] - minBeforI);
            }
            minBeforI = min(minBeforI, nums[i]);
        }
        return ans;
    }
};