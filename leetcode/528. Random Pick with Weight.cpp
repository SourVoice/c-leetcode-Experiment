// 528. 按权重随机选择
#include <vector>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
// 普通随机 + 二分 + 前缀和
class Solution
{
public:
    Solution(vector<int> &w)
    {
        sum = accumulate(begin(w), end(w), 0);
        int n = w.size();
        prefix.resize(n, 0);
        prefix[0] = w[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + w[i];
    }

    int pickIndex()
    {
        int r = 1 + rand() % sum;
        return lower_bound(begin(prefix), end(prefix), r) - begin(prefix);
    }

private:
    int sum;
    vector<int> prefix;
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// 梅森随机
class Solution
{
public:
    Solution(vector<int> &w) : distrib(1, accumulate(begin(w), end(w), 0)) // distrib的初始化必须在这里做, 否则不能通过(指在private中直接定义distrib(1, sum))
    {
        sum = accumulate(begin(w), end(w), 0);
        int n = w.size();
        prefix.push_back(w[0]);
        for (int i = 1; i < n; i++)
            prefix.push_back(prefix[i - 1] + w[i]);
    }

    int pickIndex()
    {
        int x = distrib(gen);
        return lower_bound(begin(prefix), end(prefix), x) - begin(prefix);
    }

private:
    int sum;
    vector<int> prefix;
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen{rd()}; // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib;
};