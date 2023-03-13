// 1202. 交换字符串中的元素
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
// 优先队列
class Unionfind
{
public:
    Unionfind(int capacity) : n(capacity)
    {
        fathers.resize(n, 0);
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

private:
    vector<int> fathers;
    int n;
};
class Solution
{
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int n = s.size();
        Unionfind uf(n);
        for (auto &pair : pairs)
            uf.join(pair[0], pair[1]);
        auto cmp = [](const char &a, const char &b) -> bool
        {
            return a < b;
        };
        unordered_map<int, priority_queue<char, vector<char>, decltype(greater<int>())>> mp;
        for (int i = 0; i < n; i++)
        {
            int parent = uf.find(i);
            if (!mp.count(parent))
                mp.insert({parent, priority_queue<char, vector<char>, decltype(greater<int>())>{}});
            mp[parent].push(s[i]);
        }
        string ret;
        for (int i = 0; i < n; i++)
        {
            priority_queue<char, vector<char>, decltype(greater<int>())> &pq = mp[uf.find(i)];
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
    }
};
// 按秩合并 并查集
class Unionfind
{
public:
    Unionfind(int capacity) : n(capacity)
    {
        // do not use initialize list to initizli vector (like this: class () : n(), vec(n, 0), is wrong)
        fathers.resize(n, 0);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            fathers[i] = i;
            rank[i] = i;
        }
    }
    int find(int u)
    {
        return u == fathers[u] ? u : fathers[u] = find(fathers[u]);
    }
    void join(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV)
            return;

        if (rank[rootU] == rank[rootV])
        {
            fathers[rootU] = rootV;
            // 此时以 rootV 为根结点的树的高度仅加了 1
            rank[rootV]++;
        }
        else if (rank[rootU] < rank[rootV])
        {
            fathers[rootU] = rootV;
            // 此时以 rootV 为根结点的树的高度不变
        }
        else
        {
            // 同理，此时以 rootU 为根结点的树的高度不变
            fathers[rootV] = rootU;
        }
    }

private:
    vector<int> fathers;
    // 以 i 为根结点的子树的高度（引入了路径压缩以后该定义并不准确）
    vector<int> rank;
    int n;
};