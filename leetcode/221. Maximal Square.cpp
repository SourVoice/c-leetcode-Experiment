// 221. ���������
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//����, ��ʱ
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int maxSide = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1') //���������Ͻ�
                {
                    maxSide = max(maxSide, 1);
                    int currentSide = min(m - i, n - j);
                    for (int k = 1; k < currentSide; k++)
                    {
                        bool find = true;
                        if (matrix[i + k][j + k] == '0')
                            break;
                        for (int t = 0; t <= k; t++) //�����������Ǻ�������
                        {
                            if (matrix[i + k][j + t] == '0' || matrix[i + t][j + k] == '0')
                            {
                                find = false;
                                break;
                            }
                        }
                        if (find)
                            maxSide = max(maxSide, k + 1);
                        else
                            break;
                        if (maxSide == min(m, n))
                            return maxSide * maxSide;
                    }
                }
            }
        }
        return maxSide * maxSide;
    }
};

//��̬�滮
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0)); // dp[i][j]��ʾi,jΪ���½�

        int ret = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    if (i == 0 || j == 0) //�ڱ߽�ʱ���Ϊ1
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j - 1]), dp[i - 1][j]) + 1;
                }
                ret = max(ret, dp[i][j]);
            }
        }
        return ret * ret;
    }
};