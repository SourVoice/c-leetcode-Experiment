// 97. 交错字符串
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// dp;动态规划
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n_1 = s1.size(), n_2 = s2.size(), n_3 = s3.size();
        if (n_1 + n_2 != n_3)
            return false;
        vector<vector<int>> dp(n_1 + 10, vector<int>(n_2 + 10, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n_1; i++)
        {
            if (s1.at(i - 1) == s3.at(i - 1))
                dp[i][0] = 1;
            else
                break;
        }
        for (int i = 1; i <= n_2; i++)
        {
            if (s2.at(i - 1) == s3.at(i - 1))
                dp[0][i] = 1;
            else
                break;
        }

        for (int i = 1; i <= n_1; i++)
        {
            for (int j = 1; j <= n_2; j++)
            {
                bool contidion1 = false, contidion2 = false;
                if (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1])
                    contidion1 = true;
                if (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])
                    contidion2 = true;
                cout << i << " " << j << endl;
                dp[i][j] = contidion1 || contidion2;
            }
        }
        return dp[n_1][n_2];
    }
};