// 1014. 最佳观光组合
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int n = values.size();
        int ret = 0;
        int max_val = values[0] + 0; // 看哪一个可以和最大的j组成的
        for (int i = 1; i < n; i++)
        {
            ret = max(ret, max_val + values[i] - i);
            max_val = max(max_val, values[i] + i);
        }
        return ret;
    }
};