// 1202. �����ַ����е�Ԫ��
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
// ���ȶ���
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
// ���Ⱥϲ� ���鼯
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
            // ��ʱ�� rootV Ϊ���������ĸ߶Ƚ����� 1
            rank[rootV]++;
        }
        else if (rank[rootU] < rank[rootV])
        {
            fathers[rootU] = rootV;
            // ��ʱ�� rootV Ϊ���������ĸ߶Ȳ���
        }
        else
        {
            // ͬ����ʱ�� rootU Ϊ���������ĸ߶Ȳ���
            fathers[rootV] = rootU;
        }
    }

private:
    vector<int> fathers;
    // �� i Ϊ�����������ĸ߶ȣ�������·��ѹ���Ժ�ö��岢��׼ȷ��
    vector<int> rank;
    int n;
};