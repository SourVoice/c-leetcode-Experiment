// 1790. 仅执行一次字符串交换能否使两个字符串相等
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
// 模拟
class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        int len1 = s1.length(), len2 = s2.length();
        int i = 0, j = 0;
        int times = 0;
        char rec1_1, rec1_2, rec2_1, rec2_2;
        while (i < len1 && j < len2)
        {
            if (s1[i] != s2[j])
            {
                if (times == 0)
                    rec1_1 = s1[i], rec2_1 = s2[j];
                if (times == 1)
                    rec1_2 = s1[i], rec2_2 = s2[j];
                if (times >= 2)
                    return false;
                times++;
            }
            i++, j++;
        }
        return (rec1_1 == rec2_2 && rec1_2 == rec2_1) || (times == 0);
    }
};