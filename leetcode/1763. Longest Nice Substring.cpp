// 1763. 最长的美好子字符串
#include <cctype>
#include <iostream>
#include <string>

//枚举
class Solution
{
public:
    string longestNiceSubstring(string s)
    {
        int n = s.size();
        int maxLen = 0;
        int start = 0;
        for (int i = 0; i < n; i++)
        {

            int lower = 0;
            int upper = 0;
            int j = 0;
            for (j = i; j < n; j++)
            {
                if (islower(s[j]))
                {
                    lower |= 1 << (s[j] - 'a');
                }
                else
                {
                    upper |= 1 << (s[j] - 'A');
                }
                if (lower == upper && j - i + 1 > maxLen) //这里要严格大于
                {
                    maxLen = max(maxLen, j - i + 1);
                    start = i;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};