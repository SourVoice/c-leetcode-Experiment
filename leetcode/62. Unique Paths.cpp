// 62. ��ͬ·��

#include <vector>
using namespace std;

//�����ѧ
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        long ans = 1;

        for (int x = n, y = 1; y < m; y++, x++)
        { //�ܹ�m+n-2��,������ѡm-1
            ans = ans * x / y;
        }
        return ans;
    }
};

//��̬�滮
class Soluiton2
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 1)); //����ӵ�һ�е���m��,��һ�е���n�е�·����
        for (int i = 2; i <= m; i++)
        {
            for (int j = 2; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];//״̬ת��:����i,j��·���������������,�������;��ǵ�i,j��·����
            }
        }
        long ans;
        ans = dp[m][n];
        return ans;
    }
};