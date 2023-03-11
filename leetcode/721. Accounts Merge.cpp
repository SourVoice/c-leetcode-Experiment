// 721. ’Àªß∫œ≤¢
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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        UnionFind uf(n);
        unordered_map<string, int> email_id;
        for (int id = 0; id < accounts.size(); id++)
        {
            for (int j = 1; j < accounts[id].size(); j++)
            {
                string &email = accounts[id][j];
                if (!email_id.count(email))
                    email_id.insert({email, id});
                else
                    uf.join(email_id[email], id);
            }
        }
        unordered_map<int, vector<string>> id_email;
        for (auto &[email, id] : email_id)
        {
            int rootid = uf.find(id);
            if (!id_email.count(rootid))
            {
                id_email.insert({rootid, vector<string>{email}});
            }
            else
            {
                id_email[rootid].push_back(email);
            }
        }
        vector<vector<string>> ret;
        for (auto &[id, vec] : id_email)
        {
            string name = accounts[id][0];
            sort(vec.begin(), vec.end());
            vec.insert(vec.begin(), name);
            ret.push_back(vec);
        }
        return ret;
    }
};
class UnionFind
{
public:
    UnionFind(int capacity) : n(capacity), fathers(n, 0)
    {
        for (int i = 0; i < n; i++)
            fathers[i] = i;
    }
    int &find(int &u)
    {
        return u == fathers[u] ? u : fathers[u] = find(fathers[u]);
    }
    void join(int u, int v)
    {
        u = find(u);
        v = find(v);
        fathers[u] = v;
    }
    bool issame(int u, int v)
    {
        u = find(u);
        v = find(v);
        return u == v;
    }

private:
    int n;
    vector<int> fathers;
};