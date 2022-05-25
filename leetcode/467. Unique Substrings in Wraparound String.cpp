// 467. �����ַ�����Ψһ�����ַ���
#include <string>
#include <vector>
using namespace std;

//��̬�滮
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
            cnt[p[i] - 'a'] = max(dp[i], cnt[p[i] - 'a']); //��ǰ��β���ַ����Ը���֮ǰ���ִ�
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