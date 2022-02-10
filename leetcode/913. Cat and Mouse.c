// 913. 猫鼠游戏
//博弈论和动态规划

#include <limits.h>
#include <stdbool.h>
//数据范围
static int MAXSIZE = 55;

//使用f[k][i][j]表示
//当前进行了 k 次
//老鼠所在位置为i,猫所在为j,
//时的获胜情况
static int f[2 * MAXSIZE * MAXSIZE][MAXSIZE][MAXSIZE];
int dfs(int k, int a, int b)
{
    int ans = f[k][a][b];
    if (a == 0)
        ans = 1;
    else if (a == b)
        ans = 2;
    else if (k >= 2 * MAXSIZE * MAXSIZE) //最多n个位置,所以组合数最多2*n^2种
        ans = 0;
    else if (ans == -1)
    {
        if (k % 2 == 0) // mouse's turn
        {
            bool win = false;
            bool draw = false;
            for (int ne = 0; ne < a; ne++)
            {
                int t = dfs(k + 1, ne, b);
                if (t == 1)
                    win = true;
                else if (t == 0)
                    draw = true;
                if (win)
                    break;
            }
            if (win)
                ans = 1;
            else if (draw)
                ans = 0;
            else
                ans = 2;
        }
        else // cat's turn
        {
            bool win = false;
            bool draw = false;
            for (int ne = 0; ne < b; ne++)
            {
                if (ne == 0)
                    continue;
                int t = dfs(k + 1, a, ne);
                if (t == 2)
                    win = true;
                else if (t == 0)
                    draw = true;
                if (win)
                    ans = 2;
                else if (draw)
                    ans = 0;
                else
                    ans = 1;
            }
        }
        f[k][a][b] = ans;
        return ans;
    }
}

int catMouseGame(int **graph, int graphSize, int *graphColSize)
{
    int **g;
    int n = 0;
    //初始化所有的f[k][i][j]为-1 (无效值)
    for (int k = 0; k < 2 * n * n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                f[k][i][j] = -1;
            }
        }
    }
    return dfs(0, 1, 2);
}