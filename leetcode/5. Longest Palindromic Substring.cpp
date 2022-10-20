// 5. 最长回文子串
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//中心拓展法
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int len = INT_MIN;
        int n = s.size();
        int substr_start = 0, substr_end = 0;
        for (int i = 1; i < 2 * n - 1; i++)
        {
            int left = i / 2;
            int right = i / 2 + i % 2;
            while (left >= 0 && right < n)
            {
                if (s[left] == s[right])
                {
                    left--;
                    right++;
                }
                else
                    break;
            }
            if (right - left + 1 > len)
            {
                len = right - left + 1;
                substr_start = left + 1;
                substr_end = right - 1;
            }
        }
        return s.substr(substr_start, substr_end - substr_start + 1);
    }
};
//动态规划
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int len = INT_MIN;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0)); // dp[i][j]表示s[i..j]是否为回文
        int substr_start = 0, substr_end = 0;
        for (int right = 0; right < n; right++)
        {
            for (int left = 0; left < right; left++)
            {
                if (s[left] == s[right] && (dp[left + 1][right - 1] || right - left <= 2))
                {
                    if (right - left + 1 > len)
                    {
                        len = right - left + 1;
                        substr_start = left;
                        substr_end = right;
                    }
                    dp[left][right] = 1;
                }
            }
        }
        return s.substr(substr_start, substr_end - substr_start + 1);
    }
};
// 三刷, 动态规划
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0)); // [i][j] form i to j is true
        dp[0][0] = 1;
        int substr_start = 0, substr_end = 0;
        int substr_len = 0;
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < j; i++)
            {
                if (s[i] == s[j] && (dp[i + 1][j - 1] == 1 || j - i < 2))
                {
                    if (j - i + 1 > substr_len)
                    {
                        substr_start = i, substr_end = j;
                        substr_len = j - i + 1;
                    }
                    dp[i][j] = 1;
                }
            }
        }
        return s.substr(substr_start, substr_len);
    }
};