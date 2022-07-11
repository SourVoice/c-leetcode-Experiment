// 152. 乘积最大子数组
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp_max(n + 1, INT_MIN), dp_min(n + 1, INT_MAX);
        dp_max[0] = nums[0], dp_min[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            dp_max[i] = max(dp_max[i - 1] * nums[i], max(dp_min[i - 1] * nums[i], nums[i])); //按正负讨论
            dp_min[i] = min(dp_min[i - 1] * nums[i], min(dp_max[i - 1] * nums[i], nums[i]));
        }
        return *max_element(dp_max.begin(), dp_max.end());
    }
};