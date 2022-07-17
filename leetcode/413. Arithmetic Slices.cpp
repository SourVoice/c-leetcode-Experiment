// 413. �Ȳ����л���
#include <unordered_set>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        vector<int> dp(n + 1, 0); //���±�i��β�������Ȳ�����ĸ���
        dp[0] = 0;
        int ret = 0;
        int d = nums[1] - nums[0];
        for (int i = 2; i < n; i++)
        {
            int diff = nums[i] - nums[i - 1];
            if (diff == d)
            {
                dp[i] = dp[i - 1] + 1;
                ret += dp[i];
            }
            d = diff;
        }
        return ret;
    }
};