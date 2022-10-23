#include <string>
#include <stack>
#include <bitset>
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
// ±©Á¦
class Solution
{
public:
    int subarrayGCD(vector<int> &nums, int k)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int minfatcor = nums[i];
            int j = i;
            for (; j < nums.size() && gcd(minfatcor, nums[j]) % k == 0; j++)
            {
                minfatcor = gcd(minfatcor, nums[j]);
                if (minfatcor == k)
                    ans++;
            }
        }
        return ans;
    }
};
// ÓÅ»¯
