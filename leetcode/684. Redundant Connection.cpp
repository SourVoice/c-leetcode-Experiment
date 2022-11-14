// 684. ��������
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
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        UnionFind uf(n + 10);
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (!uf.same(edges[i][0], edges[i][1]))
                uf.join(edges[i][0], edges[i][1]);
            else                // �����ڵ������ͬһ������
                ans = edges[i]; // ���˳�, ѡ�����һ��
        }
        return ans;
    }
};
// ���鼯
class UnionFind
{
public:
    UnionFind(int n)
    {
        this->n = n;
        father.resize(n, 0);
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