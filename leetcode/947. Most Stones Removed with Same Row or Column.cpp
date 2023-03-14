// 947. 移除最多的同行或同列石头
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
// brute-force
class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (stones[i][0] == stones[j][0])
                {
                    uf.join(i, j);
                }
                else if (stones[i][1] == stones[j][1])
                    uf.join(i, j);
            }
        }
        return uf.getcount();
    }
};
// 优化
// 二维降一维
class Solution2
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        size_t kmax = 100000;
        UnionFind uf(kmax * 2);
        for (const auto &stone : stones)
            uf.join(stone[0], stone[1] + kmax + 1);
        unordered_set<int> st;
        for (const auto &stone : stones)
            st.insert(uf.find(stone[0]));
        return n - st.size();
    }
};
class UnionFind
{
public:
    UnionFind(int capacity) : n(capacity)
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
        if (u == v)
            return;
        fathers[u] = v;
    }
    bool is_same(int u, int v)
    {
        return find(u) == find(v);
    }
    int getcount()
    {
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(find(fathers[i]));
        }
        return st.size();
    }

private:
    vector<int> fathers;
    int n;
};
