// 91. 解码方法
#include <string>
#include <iostream>
#include <vector>
using namespace std;

//动态规划,条件
class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.length();
        vector<int> dp(n + 1, 0); // dp is one index more farther than s
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] != '0')
            {
                dp[i] += dp[i - 1];
            }
            if (i > 1 && s[i - 2] != '0' && stoi(s.substr(i - 2, 2)) <= 26) // the i > 1 can prevent the out of bound of substr
            {

                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};