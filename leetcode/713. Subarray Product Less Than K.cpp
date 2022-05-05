// 713. 乘积小于 K 的子数组
#include <vector>
using namespace std;

// 双指针
class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt = 0;
        int multi = 1;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            multi *= nums[i];
            while (j < i && multi >= k)
            {
                multi /= nums[j];
                j++;
            }
            if (multi < k)
                cnt += i - j + 1;
        }
        return cnt;
    }
};
