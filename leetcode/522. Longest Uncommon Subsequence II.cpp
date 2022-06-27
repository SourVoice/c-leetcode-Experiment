// 522. 最长特殊序列 II
#include <cmath>
#include <vector>
#include <string>
#include <functional>
using namespace std;

class Solution
{
public:
    int findLUSlength(vector<string> &strs)
    {

        function<bool(string &, string &)> check = [](string &str1, string &str2) -> bool // check if the str1 is the substr of the str2
        {
            int i = 0, j = 0;
            while (i < str1.size() && j < str2.size())
            {
                if (str1[i] == str2[j])
                    i++, j++;
                else
                    j++;
            }
            return i == str1.size();
        };
        int ret = -1, n = strs.size();
        for (int i = 0; i < n; i++)
        {
            int rec = 0; // if the strs[i] is the only one substr of a strs, we update ret.
            for (int j = 0; j < n; j++)
            {
                if (!check(strs[i], strs[j]))//当前字符串不是字符串数组中其他字符串的子序列
                    rec++;
            }
            if (rec == n - 1)
                ret = fmax(ret, strs[i].size());
        }
        return ret;
    }
};