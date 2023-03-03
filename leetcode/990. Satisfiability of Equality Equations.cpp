// 990. 等式方程的可满足性
#include <string>
#include <stack>
#include <functional>
#include <deque>
#include <vector>
#include <map>
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
    bool equationsPossible(vector<string> &equations)
    {
        UnionFind uf(26);
        for (auto &equation : equations)
        {
            if (equation[1] == '=')
                uf.join(equation[0] - 'a', equation[3] - 'a');
        }
        for (auto &equation : equations)
        {
            if (equation[1] == '!')
            {
                if (uf.is_same(equation[0] - 'a', equation[3] - 'a'))
                    return false;
            }
        }
        return true;
    }
};
class UnionFind
{
public:
    UnionFind(int capacity) : n(capacity), fathers(n, 0)
    {
        this->init();
    }
    void init()
    {
        for (int i = 0; i < n; i++)
            fathers[i] = i;
    }
    int find(int u)
    {
        return u == fathers[u] ? u : fathers[u] = find(fathers[u]);
    }
    void join(int u, int v)
    {
        u = find(u);
        v = find(v);
        fathers[v] = u;
    }
    bool is_same(int u, int v)
    {
        u = find(u);
        v = find(v);
        return u == v;
    }

private:
    vector<int> fathers;
    int n;
};