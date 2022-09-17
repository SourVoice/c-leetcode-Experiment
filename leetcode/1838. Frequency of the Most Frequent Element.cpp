// 1838. ���ƵԪ�ص�Ƶ��
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
// ��������+ǰ׺��
class Solution
{
public:
    typedef long long ll;
    int maxFrequency(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end(), std::less<int>());
        int i = 0, j = 1, ret = 1;
        ll sum_prefix = nums[0];
        while (j < n)
        {
            sum_prefix += nums[j];
            // ���Ǽ���k�������ǰ׺�Ͳ��ֵ�����, ʹ��һ������ȫ����Ϊnums[j]
            while (j > i && ((static_cast<ll>(nums[j]) * static_cast<ll>(j - i + 1)) - sum_prefix) > k)
                sum_prefix -= nums[i++];
            ret = max(ret, j - i + 1);
            j++;
        }
        return ret;
    }
};