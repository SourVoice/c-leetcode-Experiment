// 120. ��������С·����
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//��̬�滮,��
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX)); // ����ӵ�һ�е���i�е���С��
        dp[0] = triangle[0];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                }
                else if (j == i)
                {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
                }
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
//��// 120. ��������С·����
class Solution2
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX)); // ����ӵ�һ�е���i�е���С��
        dp[0] = triangle[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = dp[i - 1][0] + triangle[i][0]; //������ֻ���������
            for (int j = 1; j < i; j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
            }
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i]; //���Ҳ�ֻ�����Ҳ���
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};