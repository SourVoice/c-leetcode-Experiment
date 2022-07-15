// 714. ������Ʊ�����ʱ����������
#include <vector>
#include <cmath>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        /*
        dp[i][0]��ʾ��i�첻���й�Ʊ��������ֽ�
        dp[i][1]��ʾ��i����й�Ʊ����ֽ�,
        */
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee); //ǰһ����й�Ʊ, ������
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);       //ǰһ�첻����,����
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};