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
    vector<int> printNumbers(int n)
    {
        s.resize(n, '0');
        dfs(n, 0);
        return ret;
    }
    void dfs(int &n, int pos)
    {
        if (pos == n)
        {
            int idx = 0;
            while (idx < n && s[idx] == '0') // È¥³ýÇ°µ¼0
                idx++;
            if (idx < n)
                ret.push_back(stoi(s.substr(idx)));
            return;
        }
        for (int i = 0; i < 10; i++)
        {
            s[pos] = '0' + i;
            dfs(n, pos + 1);
        }
    }

private:
    string s;
    vector<int> ret;
};
