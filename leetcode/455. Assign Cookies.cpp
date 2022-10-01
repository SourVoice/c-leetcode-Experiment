// 455. 分发饼干
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
// 贪心
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int i = 0, j = 0;
        sort(begin(g), end(g));
        sort(begin(s), end(s));
        while (j < s.size() && i < g.size())
        {
            if (s[j] >= g[i])
                j++, i++;
            else
                j++;
        }
        return i;
    }
};