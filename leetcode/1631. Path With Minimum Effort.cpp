// 1631. 最小体力消耗路径
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
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size(), n = heights[0].size();
        vector<tuple<int, int, int>> vec;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int id = n * i + j;
                if (i > 0)
                    vec.emplace_back(id - n, id, abs(heights[i][j] - heights[i - 1][j]));
                if (j > 0)
                    vec.emplace_back(id - 1, id, abs(heights[i][j - 1] - heights[i][j]));
            }
        }
        sort(begin(vec), end(vec), [&](const auto &a, const auto &b)
             { return get<2>(a) < get<2>(b); });
        UnionFind uf(m * n);
        int ans = 0;
        for (auto &[_1, _2, _3] : vec)
        {
            uf.join(_1, _2);
            if (uf.is_same(0, m * n - 1))
            {
                ans = _3;
                break;
            }
        }
        return ans;
    }
};
class UnionFind
{
public:
    UnionFind(int capacity) : n(capacity), fathers(capacity, 0), sizes(capacity, 1)
    {
        iota(begin(fathers), end(fathers), 0);
    }
    int find(int u)
    {
        return u == fathers[u] ? u : fathers[u] = find(fathers[u]);
    }
    void join(int u, int v)
    {
        u = find(u);
        v = find(v);
        // if (sizes[u] > sizes[v])
        //     swap(u, v);
        // sizes[u] += sizes[v];
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
    vector<long long> sizes;
    int n;
};