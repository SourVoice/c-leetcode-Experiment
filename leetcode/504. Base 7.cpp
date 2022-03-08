// 504. Æß½øÖÆÊı
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string helper(int num, int base)
    {
        string ans;
        bool neg_flag = false;
        if (num < 0)
            neg_flag = true;
        while (num / base != 0)
        {
            ans.push_back(abs(num % base) + '0');
            num = num / base;
        }
        ans.push_back(abs(num % base) + '0');
        if (neg_flag)
            ans.push_back('-');
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string convertToBase7(int num)
    {
        int base = 7;
        return helper(num, base);
    }
};