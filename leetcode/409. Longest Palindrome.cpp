// 409. 最长回文串
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
// hash表
class Solution
{
public:
    int longestPalindrome(string s)
    {
        int res = 0;
        unordered_map<char, int> m;
        for (auto c : s)
            m[c]++;
        for (auto it : m)
        {
            if (it.second % 2 == 0)
                res += it.second;
            else
                res += it.second - 1;
        }
        return res >= s.size() ? res : res + 1;
    }
};
// 哈希表
class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> mp;
        for (auto &ch : s)
            mp[ch]++;
        int ans = 0;
        bool Odd = false;
        for (auto &[ch, t] : mp)
        {
            if (t & 1)
                ans += t - 1, Odd = true;
            else
                ans += t;
        }
        return ans + Odd;
    }
};
