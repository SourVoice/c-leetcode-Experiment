// 334. ��������Ԫ������
#include <limits>
#include <vector>
using namespace std;
// ̰��
/*
        |               |
---------------------------------------->
       small           mid

    numֻ�����ֿ��ܵ�λ��
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