// 36. 有效的数独
//数组哈希
#include <vector>
#include <string>
#include <string.h>

using namespace std;
class Solution
{
public:
    bool isValidSudoku(std::vector<std::vector<char>> &board)
    {
        int rows[9][9];
        int cols[9][9];
        int subboxes[3][3][9];

        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(subboxes, 0, sizeof(subboxes));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char c = board[i][j];
                if (c != '.')
                {
                    int index = c - '0' - 1;
                    rows[i][index]++;
                    cols[j][index]++;
                    subboxes[i / 3][j / 3][index]++;
                    if (rows[i][index] > 1 || cols[j][index] > 1 || subboxes[i / 3][j / 3][index] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};
// 我的做法
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<vector<int>> rows(9, vector<int>(9, 0));                                   // 统计row[i]行数字出现频率
        vector<vector<int>> cols(9, vector<int>(9, 0));                                   // 统计col[i]列数字出现频率
        vector<vector<vector<int>>> subMat(3, vector<vector<int>>(3, vector<int>(9, 0))); // submat[i][j]用于标注大方格的坐标
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char cell = board[i][j];
                int index = cell - '1';
                if (cell != '.')
                {
                    rows[i][index]++;
                    cols[j][index]++;
                    subMat[i / 3][j / 3][index]++; // 大方格每三个出现一次
                    if (rows[i][index] > 1 || cols[j][index] > 1 || subMat[i / 3][j / 3][index] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};