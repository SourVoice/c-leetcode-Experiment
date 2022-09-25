//
// ������, �Խת��,
// ��������𽥼�С����ֵ, һ���������������Ϊ����ȫ��Ԫ��
// ����ֻ��Ҫ�ҵ��������Ԫ�صĸ�������
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int max_ = *max_element(begin(nums), end(nums));
        int cnt = 0, ret = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == max_)
                cnt++;
            else
                ret = max(cnt, ret), cnt = 0;
        }
        return max(cnt, ret);
    }
};