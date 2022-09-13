// 1760. ������������Ŀ����
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
using namespace std;
class Solution
{
public:
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        sort(begin(nums), end(nums));
        int max_ = nums[nums.size() - 1];
        int l = 1, r = max_;
        int operation = 0;
        int mid = 0;
        //�ҵ����Ĳ��ֵ
        while (l < r)
        {
            mid = (l + r) / 2;
            operation = 0;
            for (auto &num : nums)
            {
                operation += num / mid;
                if ((num % mid) == 0)
                    operation -= 1; // ����: 8��2��ֻ����� 8->6/2->2/4/2->2/2/2/2(��4��)
            }
            if (operation <= maxOperations)
                r = mid; //���ʱ�������и�С�Ŀ���, ������Ҫ�ҵ���С����
            else if (operation > maxOperations)
                l = mid + 1;
        }
        return l;
    }
};