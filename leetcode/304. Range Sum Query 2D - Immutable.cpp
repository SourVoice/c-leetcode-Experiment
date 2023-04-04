// 304. 二维区域和检索 - 矩阵不可变
#include <bits/stdc++.h>
using namespace std;
class NumMatrix
{
public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        presum.resize(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                presum[i][j] = presum[i][j - 1] + presum[i - 1][j] - presum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        // for(auto &row : presum){
        // 	for(auto &col : row){
        // 		cout << col << " ";
        // 	}
        // 	cout << endl;
        // }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        row1 += 1, col1 += 1, row2 += 1, col2 += 1; // 因为使用了padding技术, 所以行列都变多一行
        return presum[row2][col2] - presum[row2][col1 - 1] - presum[row1 - 1][col2] + presum[row1 - 1][col1 - 1];
    }

private:
    vector<vector<int>> presum;
};
