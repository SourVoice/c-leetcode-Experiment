// 1319. 连通网络的操作次数
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
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int cnt = connections.size();
        if (cnt < n - 1)
            return -1;
        UnionFind uf(n);
        sort(connections.begin(), connections.end());
        for (auto &&vec : connections)
        {
            uf.join(vec[0], vec[1]);
        }
        for (auto &&vec : connections)
        {
            uf.join(vec[0], vec[1]);
        }
        return uf.getcnt() - 1;
    }
};
class UnionFind
{
public:
    UnionFind(int capacity) : n(capacity)
    {
        father.resize(n);
        this->init();
    }
    void init()
    {
        for (int i = 0; i < n; i++)
            father[i] = i;
    }
    int find(int u)
    {
        return u == father[u] ? u : father[u] = find(father[u]);
    }
    int getcnt()
    {
        unordered_set<int> parent;
        for (int i = 0; i < n; i++)
            parent.insert(father[i]);
        return parent.size();
    }
    void join(int u, int v)
    {
        u = find(u);
        v = find(v);
        father[v] = u;
    }
    bool is_same(int u, int v)
    {
        u = find(u);
        v = find(v);
        return v == u;
    }

private:
    vector<int> father;
    int n;
};