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
    string replaceSpace(string s)
    {
        int i = 0;
        string add = "20";
        while (s[i])
        {
            if (s[i] == ' ')
            {
                s[i] = '%';
                s.insert(i + 1, add);
                i += 2;
            }
            i++;
        }
        return s;
    }
};
// 非stl做法
class Solution
{
public:
    string replaceSpace(string s)
    {
        int cnt = 0;
        // 统计空格个数
        for (auto ch : s)
        {
            if (ch == ' ')
                cnt++;
        }
        int sizeold = s.size();
        s.resize(s.size() + cnt * 2);
        int sizenew = s.size();
        for (int i = sizenew, j = sizeold; j < i; i--, j--)
        {
            if (s[j] != ' ')
                s[i] = s[j];
            else
            {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};