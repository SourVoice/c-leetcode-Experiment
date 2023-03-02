// 959. ��б�ܻ�������
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
    int regionsBySlashes(vector<string> &grid)
    {
        int N = grid.size();
        UnionFind uf(N * N * 4);
        auto get_pos = [&N](const int &row, const int &col)
        { return row * N + col; };
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int idx = get_pos(i, j);
                // ��ͨ��ͬ��������������
                if (i < N - 1)
                {
                    int bottom = idx + N;
                    uf.join(idx * 4 + 2, bottom * 4);
                }
                if (j < N - 1)
                {
                    int right = idx + 1;
                    uf.join(idx * 4 + 1, right * 4 + 3);
                }
                // ��ͨ������
                if (grid[i][j] == '/')
                {
                    uf.join(idx * 4, idx * 4 + 3);
                    uf.join(idx * 4 + 1, idx * 4 + 2);
                }
                else if (grid[i][j] == '\\')
                {
                    uf.join(idx * 4, idx * 4 + 1);
                    uf.join(idx * 4 + 2, idx * 4 + 3);
                }
                else if (grid[i][j] == ' ')
                {
                    uf.join(idx * 4, idx * 4 + 1);
                    uf.join(idx * 4 + 1, idx * 4 + 2);
                    uf.join(idx * 4 + 2, idx * 4 + 3);
                }
            }
        }
        return uf.getcnt();
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
    // @brief ��Ԫ��ȫ�����벢�鼯���ٽ��е���, ���ڻ�ȡ���ж��ٸ���ͨ��
    int getcnt()
    {
        unordered_set<int> parent;
        for (int i = 0; i < n; i++)
            parent.insert(find(father[i])); // find() Ϊclass UnionFind �ĺ���, �����ҵ��ڵ�������ͨ���ĸ��ڵ�
                                            // cout<<i<<": "<< father[i]<<endl;
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