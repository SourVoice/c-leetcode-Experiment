// 1722. 执行交换操作后的最小汉明距离
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
    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps)
    {
        int n = source.size();
        UnionFind uf(n);
        for (auto &e : allowedSwaps)
            uf.join(e[0], e[1]);
        unordered_map<int, multiset<int>> s, t; // 为每个连通分量k维护source以及target中对应位置元素的集合
        for (int i = 0; i < n; i++)
        {
            int fa = uf.find(i);
            s[fa].insert(source[i]);
            t[fa].insert(target[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!s.count(i))
                continue; // 跳过非父节点, 非父节点没有在s集合中作为键出现
            for (auto &s_elem : s[i])
            {
                if (t[i].find(s_elem) != t[i].end())
                    t[i].erase(t[i].find(s_elem)); // 防止删掉所有相同元素
                else
                    ans++; // s集合中出现但t集合中没有出现, 所以汉明距离++
            }
        }
        return ans;
    }
};
class UnionFind
{
public:
    UnionFind(int capacity) : n(capacity), fathers(capacity, 0)
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
        if (u == v)
            return;
        fathers[u] = v;
    }
    bool is_same(int u, int v)
    {
        return find(u) == find(v);
    }

private:
    vector<int> fathers;
    int n;
};