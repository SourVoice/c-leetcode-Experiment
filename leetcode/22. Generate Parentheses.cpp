// 22. ��������
#include <vector>
#include <string>
#include <functional>
using namespace std;

// dp��̬�滮
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};
        dp[1] = {"()"};
        vector<string> ans;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                for (auto p : dp[j])
                {
                    for (auto q : dp[i - 1 - j]) //�µ����������j���i-1-j��+1���
                    {
                        dp[i].push_back("(" + p + ")" + q);
                    }
                }
            }
        }
        return dp[n];
    }
};

// dfs+����
class Solution2
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        function<void(int, int, int, string)> dfs = [&](int left, int right, int n, string str)
        {
            if (right < 0 || left < 0 || right< left)//��֦
                return;
            if (right == 0 && left == 0)
            {
                ans.push_back(str);
                return;
            }

            if (left > 0)
                dfs(left - 1, right, n, str + '(');
            if (right > 0)
                dfs(left, right - 1, n, str + ')');
        };
        dfs(n, n, n, "");
        return ans;
    }
};