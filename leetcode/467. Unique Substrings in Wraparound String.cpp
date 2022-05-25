// 467. 环绕字符串中唯一的子字符串
#include <string>
#include <vector>
using namespace std;

//动态规划
class Solution
{
public:
    int findSubstringInWraproundString(string p)
    {
        int n = p.size();
        vector<int> cnt(26, 0);
        vector<int> dp(n, 0);
        dp[0] = 1;
        int i = 0;
        while (i < n)
        {
            if (i > 0 && i < n)
            {
                if (p[i - 1] == 'z' && p[i] == 'a' || p[i] == p[i - 1] + 1)
                {
                    dp[i] = dp[i - 1] + 1;
                }
                else
                    dp[i] = 1;
            }
            cnt[p[i] - 'a'] = max(dp[i], cnt[p[i] - 'a']); //当前结尾的字符可以覆盖之前的字串
            i++;
        }
        int sum = 0;
        for (auto &elem : cnt)
        {
            sum += elem;
        }
        return sum;
    }
};