// 67. 二进制求和
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
// 模拟
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.size() - 1, j = b.size() - 1;
        string s;
        char carry = '0';
        while (i >= 0 && j >= 0)
        {
            if (a[i] == '1' && b[j] == '1')
            {
                if (carry == '1')
                {
                    carry = '1';
                    s.push_back('1');
                }
                else
                {
                    carry = '1';
                    s.push_back('0');
                }
            }
            else
            {
                if (carry == '1' && max(a[i], b[j]) == '0')
                {
                    s.push_back('1');
                    carry = '0';
                }
                else if (carry == '1' && max(a[i], b[j]) == '1')
                {
                    s.push_back('0');
                    carry = '1';
                }
                else
                {
                    s.push_back(max(a[i], b[j]));
                    carry = '0';
                }
            }
            i--, j--;
        }
        while (i >= 0)
        {
            if (carry == '1' && a[i] == '1')
            {
                s.push_back('0');
                carry == '1';
            }
            else
            {
                s.push_back(max(a[i], carry));
                carry = '0';
            }
            i--;
        }
        while (j >= 0)
        {
            if (carry == '1' && b[j] == '1')
            {
                s.push_back('0');
                carry == '1';
            }
            else
            {
                s.push_back(max(b[j], carry));
                carry = '0';
            }
            j--;
        }
        if (carry == '1')
            s.push_back(carry);
        reverse(begin(s), end(s));
        return s;
    }
};
