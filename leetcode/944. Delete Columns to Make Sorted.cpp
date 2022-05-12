// 944. …æ¡–‘Ï–Ú
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int ans = 0;
        int m = strs.size(), n = strs[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m - 1; j++)
            {
                if (strs[j + 1][i] < strs[j][i])
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};