// 784. 字母大小写全排列
#include <string>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
using namespace std;
// 递归;回溯
class Solution
{
public:
    vector<string> letterCasePermutation(string s)
    {
        vector<string> ret;
        dfs(ret, s, 0);
        return ret;
    }
    void dfs(vector<string> &ret, string &s, int index)
    {
        if (s.size() == index)
        {
            ret.push_back(s);
            return;
        }
        dfs(ret, s, index + 1);
        if (islower(s[index]))
        {
            s[index] = toupper(s[index]);
            dfs(ret, s, index + 1);
            s[index] = tolower(s[index]);
        }
        else if (isupper(s[index]))
        {
            s[index] = tolower(s[index]);
            dfs(ret, s, index + 1);
            s[index] = toupper(s[index]);
        }
    }
};
// 位运算
class Solution
{
public:
    vector<string> letterCasePermutation(string s)
    {
        vector<string> ret;
        dfs(ret, s, 0);
        return ret;
    }
    void dfs(vector<string> &ret, string &s, int index)
    {
        if (s.size() == index)
        {
            ret.push_back(s);
            return;
        }
        dfs(ret, s, index + 1);
        if (isalpha(s[index]))
        {
            s[index] ^= (1 << 5);
            dfs(ret, s, index + 1);
        }
    }
};