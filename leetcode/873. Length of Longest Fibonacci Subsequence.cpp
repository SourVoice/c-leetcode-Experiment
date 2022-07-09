// 873. 最长的斐波那契子序列的长度
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;

//动态规划
class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        unordered_map<int, int> mp; // map for index
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]] = i;
        }
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0)); //以下标i, j为结尾的两个数的数列长度
        int ret = 0;
        for (int i = 0; i < n; i++)
        {

            for (int j = i - 1; j >= 0 && arr[j] * 2 > arr[i]; j--)
            {
                int k = -1;
                if (mp.count(arr[i] - arr[j]))
                {
                    k = mp[arr[i] - arr[j]];
                }
                if (k >= 0 && k < j)
                    dp[j][i] = max(dp[k][j] + 1, 3);
                else
                    dp[j][i] = 0;
                ret = max(ret, dp[j][i]);
            }
        }
        return ret;
    }
};