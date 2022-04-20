// 821. 字符的最短距离
#include <vector>
#include <string>
#include <set>
using namespace std;

// naive哈希+遍历
class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        int n = s.length();
        vector<int> ans(n, INT_MAX);
        set<int> pos_of_c;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == c)
            {
                pos_of_c.insert(i);
                ans.at(i) = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!pos_of_c.count(i))
            {
                int distance = INT_MAX;
                for (auto pos : pos_of_c)
                {
                    distance = min(distance, abs(pos - i));
                }
                ans.at(i) = distance;
            }
        }
        return ans;
    }
};

//双向遍历
class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        int n = s.length();
        vector<int> ans(n);
        for (int i = 0, index_of_c = -n; i < n; i++)
        {
            if (s[i] == c)
            {
                index_of_c = i;
            }
            ans[i] = abs(i - index_of_c);
        }
        //反向遍历
        for (int i = n - 1, idx_of_c = 2 * n; i >= 0; i--)
        {
            if (s[i] == c)
            {
                idx_of_c = i;
            }
            ans[i] = min(ans[i], abs(i - idx_of_c));
        }
        return ans;
    }
};