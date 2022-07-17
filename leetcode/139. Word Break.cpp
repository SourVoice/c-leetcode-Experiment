// 139. ���ʲ��
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
        vector<int> dp(s.size() + 1, 0); // dp[i]��ʾs[0, i- 1]���ַ����Ƿ�Ϸ�
        dp[0] = 1;
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                string word = s.substr(j, i - j);
                if (st.count(word) && dp[j]) // dp[j]�Ϸ�ʱ����s[j, i - j]�Ƿ�Ϸ�
                {
                    dp[i] = 1;
                }
            }
        }
        return dp[s.size()];
    }
};