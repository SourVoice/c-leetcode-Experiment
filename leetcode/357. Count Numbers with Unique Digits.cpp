// 357. 统计各位数字都不同的数字个数
#include <vector>
#include <functional>
#include <cmath>
using namespace std;

class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        function<int(int)> dfs = [&](int n)
        {
            int res = 9;
            if (n == 0)
                return res + 1;
            for (int i = 0; i < n; i++)
            {
                res *= 10 - i;
            }
            return res + dfs(n - 1);
        };
        return dfs(n) / 10;
    }
};