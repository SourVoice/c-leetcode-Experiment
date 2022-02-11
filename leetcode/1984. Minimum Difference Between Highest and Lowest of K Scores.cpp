// 1984. ѧ����������С��ֵ

#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), [](const int &a, const int &b)
             { return a < b; });
        int ans = INT_MAX;
        for (int i = 0; i < nums.size() - k + 1; i++)
        {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
};