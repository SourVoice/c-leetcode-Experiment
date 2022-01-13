// 334. ��������Ԫ������
//̰��
#include <limits>
#include <vector>

class Solution
{
public:
    bool increasingTriplet(std::vector<int> &nums)
    {
        int a = INT_MAX;
        int b = INT_MAX;

        for (auto elem : nums)
        {
            if (elem <= a)
                a = elem;
            else if (elem <= b)
                b = elem;
            else
                return true;
        }
        return false;
    }
};