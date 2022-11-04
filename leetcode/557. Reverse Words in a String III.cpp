// 557. 反转字符串中的单词 III
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        string word;
        string ans;
        while (ss >> word)
        {
            reverse(word.begin(), word.end());
            ans += word + ' ';
        }
        ans.erase(ans.end() - 1);
        return ans;
    }
};
// 原地算法
class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.size();
        int i = 0;
        while (i < n)
        {
            int start = i;
            // 找到单词
            while (i < n && s[i] != ' ')
                i++;
            int l = start, r = i - 1;
            while (l < r)
                swap(s[l++], s[r--]);
            // 下一个单词起点
            while (i < n && s[i] == ' ')
                i++;
        }
        return s;
    }
};