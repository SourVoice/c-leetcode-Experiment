// 376. °Ú¶¯ÐòÁÐ
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//Ì°ÐÄ
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return n;
        int diff = nums[1] - nums[0];
        int ans = 2;
        if (diff == 0)
            ans = 1;
        for (int i = 2; i < n; i++)
        {
            int diff_cur = nums[i] - nums[i - 1];
            if ((diff >= 0 && diff_cur < 0) || (diff <= 0 && diff_cur > 0))
            {
                ans++;
                diff = diff_cur;
            }
        }
        return ans;
    }
};