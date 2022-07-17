// 139. 单词拆分
#include <unordered_set>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> dp(s.size() + 1, 0); // dp[i]表示s[0, i- 1]的字符串是否合法
        dp[0] = 1;
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                string word = s.substr(j, i - j);
                if (st.count(word) && dp[j]) // dp[j]合法时看是s[j, i - j]是否合法
                {
                    dp[i] = 1;
                }
            }
        }
        return dp[s.size()];
    }
};