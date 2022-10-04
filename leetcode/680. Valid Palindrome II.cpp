// 680. ��֤���Ĵ� II
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <list>
using namespace std;
// ���Ե�һ��������ж�
class Solution
{
public:
    bool validPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        auto helper = [&](int i, int j) -> bool
        {
            while (i <= j)
                if (s[i++] != s[j--])
                    return false;
            return true;
        };
        while (i < j)
        {
            if (s[i] != s[j])
                if (helper(i, j - 1) || helper(i + 1, j))
                    return true;
                else
                    return false;
            else
                i++, j--;
        }
        return true;
    }
};