// 1706. 球会落何处
#include <vector>
using namespace std;
//模拟
class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int balls = n;
        vector<int> ans(n, -1);
        for (int ball = 0; ball < balls; ball++)
        {
            int j = ball;
            int i = 0;
            while (1)
            {
                if (i == m) // touch the bottom
                {
                    ans.push_back(j);
                    break;
                }

                if (grid[i][j] == 1) // switch to right
                {
                    if (j + 1 >= n || grid[i][j + 1] == -1) // here's a  V
                    {
                        ans.push_back(-1);
                        break;
                    }
                    else // else switch to right
                    {
                        j++;
                        i++;
                    }
                }
                else if (grid[i][j] == -1) // switch to left
                {
                    if (j - 1 < 0 || grid[i][j - 1] == 1)
                    {
                        ans.push_back(-1);
                        break;
                    }
                    else // switch to left
                    {
                        j--;
                        i++;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution2
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int balls = n;
        vector<int> ans;
        for (int ball = 0; ball < balls; ball++)
        {
            int j = ball;
            int i = 0;
            while (1)
            {
                if (i == m) // touch the bottom
                {
                    ans.push_back(j);
                    break;
                }

                if (grid[i][j] == 1) // switch to right
                {
                    if (j + 1 < n && grid[i][j + 1] == 1)
                    {
                        j++;
                        i++;
                    }
                    else
                    {
                        ans.push_back(-1);
                        break;
                    }
                }
                else if (grid[i][j] == -1)
                {
                    if (j - 1 > -1 && grid[i][j - 1] == -1)
                    {
                        j--;
                        i++;
                    }
                    else
                    {
                        ans.push_back(-1);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};