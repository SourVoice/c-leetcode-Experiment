// 309. ���������Ʊʱ�����䶳��
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(4, 0));
        /*
        i��ʾ�����Ѿ�����
        dp[i][0] ��ʾ�������,���й�Ʊ
        dp[i][1] ��ʾ�����й�Ʊ,�����䶳��,����Ϊdp[i][1]
        dp[i][2] ��ʾ�����й�Ʊ,�������䶳��, ����Ϊdp[i][2],����
        */
        dp[0][0] = -prices[0]; //����
        dp[0][1] = 0;
        dp[0][2] = 0;
        int profit = 0;
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]); // i-1���Ѿ����л��߷��䶳������
            dp[i][1] = dp[i - 1][0] + prices[i];                    //����
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);             // �����ڵ� ii �����֮�󲻳����κι�Ʊ���Ҳ������䶳�ڣ�˵������û�н����κβ���
            profit = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
        }
        return max(dp[n - 1][0], max(dp[n - 1][2], dp[n - 1][1]));
    }
};