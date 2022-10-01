// 1694. 重新格式化电话号码
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
// 字符串模拟
class Solution
{
public:
    string reformatNumber(string number)
    {
        number.erase(remove(number.begin(), number.end(), ' '), number.end());
        number.erase(remove(number.begin(), number.end(), '-'), number.end());
        string res;
        int i = 0, len = number.length();
        for (int j = 3; len > 4 && j <= len; j += 3)
        {
            res += number.substr(j - 3, 3), res += '-';
            if (abs(j + 3 - len) <= 1)
                i = j, j = len + 1;
        }
        if (i + 2 == len)
            res += number.substr(i, 2);
        else if (i + 3 == len)
            res += number.substr(i, 3);
        else if (i + 4 == len)
            res += number.substr(i, 2), res += '-', res += number.substr(i + 2, 2);
        return res;
    }
};