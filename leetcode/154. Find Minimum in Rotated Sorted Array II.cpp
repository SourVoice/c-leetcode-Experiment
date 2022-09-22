// 154. Ѱ����ת���������е���Сֵ II
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
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            // ÿ��ѡ������һ��
            if (nums[mid] < nums[r])
                r = mid;
            else if (nums[mid] > nums[r])
                l = mid + 1;
            else // ��֤��nums[mid]==nums[r]��ͬʱ�ܹ�ȡ������һ��, ����֤��ֹ�ظ�Ԫ��Ϊ��СԪ��
                r--;
        }
        return nums[l];
    }
};