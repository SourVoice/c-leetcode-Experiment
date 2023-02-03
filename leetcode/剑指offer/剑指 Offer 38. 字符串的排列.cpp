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
    vector<string> permutation(string s)
    {
        vector<string> ret;
        dfs(s, ret, 0);
        return ret;
    }
    void dfs(string &s, vector<string> &ret, int pos)
    {
        if (pos == s.size())
        {
            ret.push_back(s);
            return;
        }
        set<int> st;
        for (int i = pos; i < s.size(); i++)
        {
            if (st.find(s[i]) != st.end())
            {
                continue;
            }
            st.insert(s[i]);
            swap(s[i], s[pos]);
            dfs(s, ret, pos + 1);
            swap(s[pos], s[i]);
        }
    }
};