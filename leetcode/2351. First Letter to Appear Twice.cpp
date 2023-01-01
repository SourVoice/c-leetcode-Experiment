// 2351. 第一个出现两次的字母
#include <string>
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
    char repeatedCharacter(string s)
    {
        vector<char> alpha(26, 0);
        for (auto ch : s)
        {
            int i = ch - 'a';
            alpha[i]++;
            if (alpha[i] == 2)
                return ch;
        }
        return 'a';
    }
};
// 状态压缩
class Solution
{
public:
    char repeatedCharacter(string s)
    {
        int ans = 0;
        for (auto ch : s)
        {
            if (ans >> ch - 'a' & 1)
                return ch;
            ans |= 1 << ch - 'a';
        }
        return 'a';
    }
};