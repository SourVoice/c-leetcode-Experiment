// 547. 省份数量
#include <string>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
using namespace std;
// 并查集
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j])
                    uf.join(i, j);
            }
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[uf.find(i)]++;
        }
        return mp.size();
    }
};
// 并查集模板:
class UnionFind
{
public:
    UnionFind(int n)
    {
        this->n = n;
        this->father.resize(n, 0);
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
    void join(int u, int v)
    {
        u = find(u);
        v = find(v);
        father[v] = u;
    }
    bool same(int u, int v)
    {
        u = find(u);
        v = find(v);
        return u == v;
    }

private:
    int n;
    vector<int> father;
};