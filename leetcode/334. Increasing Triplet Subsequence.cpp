// 334. 递增的三元子序列
#include <limits>
#include <vector>
using namespace std;
// 贪心
/*
        |               |
---------------------------------------->
       small           mid

    num只用三种可能的位置
*/
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int small = INT_MAX;
        int mid = INT_MAX;
        for (auto &num : nums)
        {
            if (num <= small)
                small = num;
            else if (num <= mid)
                mid = num;
            else
                return true;
        }
        return false;
    }
};