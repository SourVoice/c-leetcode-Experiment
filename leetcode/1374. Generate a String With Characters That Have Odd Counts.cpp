// 1374. 生成每种字符都是奇数个的字符串
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    string generateTheString(int n)
    {
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        string ret;
        if (n & 1)
        {
            ret.append(n, 'a');
        }
        else
        {
            ret.append(n - 1, 'a');
            ret.append("b");
        }
        return ret;
    }
};