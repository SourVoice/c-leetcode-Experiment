// 6181. 最长的字母序连续子字符串的长度
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
// brute force
class Solution
{
public:
    int longestContinuousSubstring(string s)
    {
        int n = s.size();
        int len = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            for (; j + 1 < n;)
            {
                if (s[j + 1] == s[j] + 1)
                {
                    j++;
                }
                else
                {
                    break;
                }
            }
            len = max(len, j - i + 1);
            i = j;
        }
        return len;
    }
};
// 动态规划
class Solution
{
public:
    int longestContinuousSubstring(string s)
    {
        int n = s.size();
        int len = 0;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1] + 1)
                dp[i] = dp[i - 1] + 1;
            len = max(len, dp[i]);
        }
        return len;
    }
};
