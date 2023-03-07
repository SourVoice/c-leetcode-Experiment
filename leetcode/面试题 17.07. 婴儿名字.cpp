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
    vector<string> trulyMostPopular(vector<string> &names, vector<string> &synonyms)
    {
        Unionfind uf;
        for (auto &synonym : synonyms)
        {
            int splt = synonym.find(',');
            uf.join(
                synonym.substr(1, splt - 1),
                synonym.substr(splt + 1, synonym.size() - splt - 2));
        }
        unordered_map<string, int> mp;
        for (auto &name : names)
        {
            int left_bracket_pos = name.find('(');
            int right_bracket_pos = name.find(')');
            string cur_name = name.substr(0, left_bracket_pos);
            string cur_time_str = name.substr(left_bracket_pos + 1, right_bracket_pos - left_bracket_pos);
            int cur_time = stoi(cur_time_str);
            mp[uf.find(cur_name)] += cur_time;
        }
        vector<string> ret;
        for (auto &[str, i] : mp)
            ret.push_back(str + '(' + to_string(i) + ')');
        return ret;
    }
};
class Unionfind
{
public:
    const string &find(const string &u)
    {
        if (!fathers.count(fathers[u]))
            fathers[u] = u;
        else if (fathers[u] != u)
            fathers[u] = find(fathers[u]);
        return fathers[u];
    }
    void join(const string &u, const string &v)
    {
        string rootU = find(u);
        string rootV = find(v);
        if (rootU > rootV)
            fathers[rootU] = rootV;
        else
            fathers[rootV] = rootU;
    }

private:
    unordered_map<string, string> fathers;
    int n;
};