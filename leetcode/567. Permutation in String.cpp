// 567. 字符串的排列
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
// 滑动窗口
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int len1 = s1.size(), len2 = s2.size();
        if (len1 > len2)
            return false;
        int win = len1;
        vector<int> alpha1(26, 0);
        vector<int> alpha2(26, 0);
        for (int i = 0; i < s1.size(); i++)
        {
            alpha1[s1[i] - 'a']++;
            alpha2[s2[i] - 'a']++;
        }
        for (int i = win; i < s2.size(); i++)
        {
            if (alpha1 == alpha2)
                return true;
            alpha2[s2[i - win] - 'a']--;
            alpha2[s2[i] - 'a']++;
        }
        return alpha1 == alpha2;
    }
};