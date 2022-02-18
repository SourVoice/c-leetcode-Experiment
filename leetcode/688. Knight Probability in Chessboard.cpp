// 688. ��ʿ�������ϵĸ���
#include <vector>
using namespace std;
//��̬�滮
class Solution
{
public:
    vector<vector<int>> dirs = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    double knightProbability(int n, int k, int row, int column)
    {
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, 0))); // dp[i][j][k]��ʾ��(i,j)��ʼ��k���ڵĸ���
        for (int i = 0; i <= k; i++)
        {
            for (int x = 0; x < n; x++)
            {
                for (int y = 0; y < n; y++)
                {
                    if (i == 0)
                    {
                        dp[x][y][i] = 1;
                    }
                    else
                    {
                        for (auto dir : dirs)
                        {
                            int newX = x + dir[0];
                            int newY = y + dir[1];
                            if (newX >= 0 && newX < n && newY >= 0 && newY < n)
                            {
                                dp[x][y][i] += dp[newX][newY][i - 1] / 8.0;
                            }
                        }
                    }
                }
            }
        }
        return dp[row][column][k];
    }
};

//����������� ��ʱ
class Solution2
{
public:
    vector<vector<int>> dirs = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    double knightProbability(int n, int k, int row, int column)
    {
        return dfs(n, k, row, column);
    }
    double dfs(int n, int k, int row, int col)
    {
        if (row < 0 || row >= n || col < 0 || col >= n)
            return 0;
        if (k == 0)
            return 1;

        double ans = 0;
        for (auto dir : dirs)
        {
            ans += dfs(n, k - 1, row + dir[0], col + dir[1]) / 8.0;
        }
        return ans;
    }
};

//���仯����
class Solution3
{
public:
    vector<vector<int>> dirs = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    double knightProbability(int n, int k, int row, int column)
    {
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, 0)));
        return dfs(n, k, row, column, dp);
    }

    //�۲�ݹ鷽����ǩ����public double dfs(int n, int k, int i, int j)�������������ɱ�����أ�i��j��k��
    double dfs(int n, int k, int row, int col, vector<vector<vector<double>>> &dp)
    {
        if (row < 0 || row >= n || col < 0 || col >= n)
            return 0;
        if (k == 0)
            return 1;

        // �����д��ڣ�ֱ�ӷ���
        if (dp[row][col][k] != 0)
        {
            return dp[row][col][k];
        }

        double ans = 0;
        for (auto dir : dirs)
        {
            ans += dfs(n, k - 1, row + dir[0], col + dir[1], dp) / 8.0;
        }

        dp[row][col][k] = ans;
        return ans;
    }
};