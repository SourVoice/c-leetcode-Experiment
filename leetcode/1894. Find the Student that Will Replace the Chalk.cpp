// 1894. 找到需要补充粉笔的学生编号
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
using namespace std;
class Solution
{
public:
    typedef long long ll;
    int chalkReplacer(vector<int> &chalk, int k)
    {
        int n = chalk.size();
        if (n == 1)
            return 0;
        ll sum = accumulate(begin(chalk), end(chalk), static_cast<ll>(0));
        ll cnt = 0;
        while (k - sum * cnt >= 0)
        {
            cnt++;
        }
        k = k - sum * (cnt - 1);
        for (auto i = 0; i < n; i++)
        {
            if (k < chalk[i])
                return i;
            k -= chalk[i];
        }
        return 0;
    }
};
// 简化
class Solution
{
public:
    typedef long long ll;
    int chalkReplacer(vector<int> &chalk, int k)
    {
        int n = chalk.size();
        if (n == 1)
            return 0;
        ll sum = accumulate(begin(chalk), end(chalk), static_cast<ll>(0));
        k = k % sum;
        for (int i = 0; i < n; i++)
        {
            if (k < chalk[i])
                return i;
            k -= chalk[i];
        }
        return 0;
    }
};
// 前缀和
class Solution
{
public:
    typedef long long ll;
    int chalkReplacer(vector<int> &chalk, int k)
    {
        int n = chalk.size();
        for (int i = 1; i < n; i++)
        {
            chalk[i] += chalk[i - 1];
            if (chalk[i] > k)
                return i;
        }
        k = k % chalk.back();
        return upper_bound(begin(chalk), end(chalk), static_cast<ll>(k)) - begin(chalk);
    }
};