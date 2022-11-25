// 673. ����������еĸ���
#include <string>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
using namespace std;
// ��̬�滮
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);  // ��ϳ���
        vector<int> cnt(n, 1); // ������, ��nums[i]��β��
        int maxLen = 0;        // ��¼��������г���
        if (n == 1)
            return 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (dp[j] + 1 > dp[i]) // ������г��ȸ���
                    {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if (dp[j] + 1 == dp[i]) // ��ͬ����������
                    {
                        cnt[i] += cnt[j];
                    }
                }
                maxLen = max(maxLen, dp[i]);
            }
        }
        int ans = 0;
        // �ۼƸ���
        for (int i = 0; i < n; i++)
        {
            if (maxLen == dp[i])
                ans += cnt[i];
        }
        return ans;
    }
};
// TODO: ̰�� + ǰ׺�� + ���ֲ���