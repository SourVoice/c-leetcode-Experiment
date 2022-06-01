// 473. »ð²ñÆ´Õý·½ÐÎ
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    bool makesquare(vector<int> &matchsticks)
    {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0)
            return false;
        int sid_len = sum / 4;
        this->n = matchsticks.size();
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> len(4, 0);
        vector<int> visited(n, 0);
        return dfs(sid_len, matchsticks, visited, len, 0);
    }
    bool dfs(int side_len, vector<int> &matchsticks, vector<int> &visited, vector<int> &len, int idx)
    {
        if (idx >= n)
        {
            if (len[0] == side_len && len[1] == side_len && len[2] == side_len && len[3] == side_len)
                return true;
            return false;
        }

        for (int i = 0; i < len.size(); i++)
        {
            if (matchsticks[idx] + len[i] <= side_len)
            {
                if (!visited[idx])
                {
                    visited[idx] = 1;
                    len[i] = matchsticks[idx] + len[i];
                    if (dfs(side_len, matchsticks, visited, len, idx + 1))
                        return true;
                }
                visited[idx] = 0;
                len[i] -= matchsticks[idx];
            }
        }
        return false;
    }

private:
    int n = 0;
};