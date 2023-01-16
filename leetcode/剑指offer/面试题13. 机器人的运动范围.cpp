#include <string>
#include <stack>
#include <functional>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <sstream>
using namespace std;
class Solution
{
public:
    int movingCount(int m, int n, int k)
    {
        this->m = m;
        this->n = n;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        dfs(visited, 0, 0, k);

        return ans;
    }
    void dfs(vector<vector<int>> &visited, int x, int y, int k)
    {
        if (x >= m || x < 0 || y >= n || y < 0 || visited[x][y] || help(x) + help(y) > k)
        {
            return;
        }
        visited[x][y] = 1;
        ans++;
        for (auto &dir : dirs)
        {
            int n_x = x + dir[0], n_y = y + dir[1];
            dfs(visited, n_x, n_y, k);
        }
    }
    int help(int n)
    {
        int t = 0;
        while (n)
        {
            t += n % 10;
            n /= 10;
        }
        return t;
    }

private:
    int m, n;
    int ans = 0;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};