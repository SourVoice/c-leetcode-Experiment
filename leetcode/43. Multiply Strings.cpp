// 43. ×Ö·û´®Ïà³Ë
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
    string multiply(string num1, string num2)
    {
        vector<int> a(1000, 0);
        vector<int> b(1000, 0);
        vector<int> c(1000, 0);
        int len1 = num1.length();
        int len2 = num2.length();
        for (int i = len1 - 1; i >= 0; i--)
            a[i] = num1[len1 - i - 1] - '0';

        for (int i = len2 - 1; i >= 0; i--)
            b[i] = num2[len2 - i - 1] - '0';

        for (int i = 0; i < len1; i++)
        {
            int carry = 0;
            for (int j = 0; j < len2; j++)
            {
                c[i + j] = a[i] * b[j] + carry + c[i + j];
                carry = c[i + j] / 10;
                c[i + j] = c[i + j] % 10;
            }
            c[i + len2] += carry;
        }
        int lenc = 0;
        for (int i = 1000 - 1; i >= 0; i--)
        {
            if (c[i] != 0)
            {
                lenc = i;
                break;
            }
        }
        string ret(lenc + 1, 0);
        for (int i = 0; i <= lenc; i++)
            ret[i] = c[lenc - i] + '0';
        return ret;
    }
};
