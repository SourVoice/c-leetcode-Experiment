// 399. 除法求值
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
// 有向权图
class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        int n = equations.size();
        unordered_map<string, int> mp;
        UnionFind uf(n * 2);
        int id = 0;
        int idx = 0;
        for (auto &equation : equations)
        {
            string val1 = equation[0];
            string val2 = equation[1];
            if (!mp.count(val1))
                mp.insert({val1, id++});
            if (!mp.count(val2))
                mp.insert({val2, id++});
            uf.join(mp[val1], mp[val2], values[idx++]);
        }
        int queryS = queries.size();
        vector<double> ret(queryS, -1.00000);
        for (int i = 0; i < queryS; i++)
        {
            string val1 = queries[i][0];
            string val2 = queries[i][1];
            if (mp.count(val1) && mp.count(val2))
            {
                ret[i] = uf.getret(mp[val1], mp[val2]);
            }
        }
        return ret;
    }
};
class UnionFind
{
public:
    UnionFind(int capacity) : n(capacity), fathers(n, 0), weight(n, 1.0)
    {
        for (int i = 0; i < n; i++)
        {
            fathers[i] = i;
            weight[i] = 1.0;
        }
    }
    int find(int u)
    {
        if (u != fathers[u])
        {
            int origin = fathers[u];
            fathers[u] = find(fathers[u]);
            weight[u] *= weight[origin];
        }
        return fathers[u];
    }
    void join(int u, int v, double value)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV)
            return;
        fathers[rootU] = rootV;
        weight[rootU] = weight[v] * value / weight[u];
    }
    double getret(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV)
            return weight[u] / weight[v];
        else
            return static_cast<double>(-1.0);
    }

private:
    int n;
    vector<int> fathers;
    vector<double> weight;
};