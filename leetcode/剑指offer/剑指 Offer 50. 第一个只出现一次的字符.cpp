#include <string>
#include <stack>
#include <functional>
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
#include <limits.h>
#include <stdbool.h>
#include <math.h>
using namespace std;
class Solution
{
public:
    char firstUniqChar(string s)
    {
        unordered_map<char, int> mp;
        string stmp = s;
        for (auto &ch : s)
        {
            mp[ch]++;
            if (mp[ch] > 1)
            {
                stmp.erase(remove(begin(stmp), end(stmp), ch), end(stmp));
                mp.erase(ch);
            }
        }
        return stmp.size() ? stmp[0] : ' ';
    }
};
// ½â·¨¶þ:
class Solution
{
public:
    char firstUniqChar(string s)
    {
        if (s.length() == 0)
            return ' ';
        int alpha[26] = {0};
        for (auto ch : s)
        {
            alpha[ch - 'a']++;
        }
        for (auto ch : s)
        {
            if (alpha[ch - 'a'] == 1)
                return ch;
        }
        return ' ';
    }
};