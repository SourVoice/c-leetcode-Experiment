// 415. ×Ö·û´®Ïà¼Ó
#include <string>
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
    string addStrings(string num1, string num2)
    {
        int i = num1.size() - 1, j = num2.size() - 1;
        string ans = "";
        int carry = 0;
        int tmpRet = 0;
        while (i >= 0 && j >= 0)
        {
            tmpRet = num1[i--] - '0' + num2[j--] - '0' + carry;
            ans.push_back(tmpRet % 10 + '0');
            carry = tmpRet / 10;
        }
        while (i >= 0)
        {
            tmpRet = num1[i--] - '0' + carry;
            ans.push_back(tmpRet % 10 + '0');
            carry = tmpRet / 10;
        }
        while (j >= 0)
        {
            tmpRet = num2[j--] - '0' + carry;
            ans.push_back(tmpRet % 10 + '0');
            carry = tmpRet / 10;
        }
        if (carry)
            ans.push_back(carry + '0');
        reverse(begin(ans), end(ans));
        return ans;
    }
};