// 977. ���������ƽ��
#include <string>
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
// ˫ָ��
class Solution
{
public:
    typedef long long ll;
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ret(n, 0);
        int i = 0, j = n - 1, k = n - 1;
        while (k != -1)
        {
            ll pow_l = powl(nums[i], 2), pow_r = powl(nums[j], 2);
            if (pow_l > pow_r)
                ret[k--] = pow_l, i++;
            else
                ret[k--] = pow_r, j--;
        }
        return ret;
    }
};