// 3. 无重复字符的最长子串
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
// 二刷
// 滑动窗口;双指针
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<char> pool(256, 0);
        int i = 0, j = 0;
        int win = 0;
        for (; j < s.size();)
        {
            while (pool[s[j]])
            {
                pool[s[i]] = 0;
                i++;
            }
            pool[s[j]] = 1;
            j++;
            win = max(win, j - i);
        }
        return win;
    }
};
// C题解
int lengthOfLongestSubstring(char *s)
{
    char *p1 = s;
    char *p2 = s;
    char ch_ASSIC[256] = {0}; //用于记录每个重复字符，出现重复则将其重置为全零
    int counter = 0;          //字符长度
    do
    {
        counter = p2 - p1 >= counter ? (p2 - p1) : counter;
        if (ch_ASSIC[*p2] == 1) // p1++
        {
            while (p2 != p1)
                ch_ASSIC[*--p2] = '\0'; //重置字符池
            p1++;
            p2 = p1;
        }
        if (*p2 == '\0') //外循环结束条件
            break;
        ch_ASSIC[*p2] = 1;
        p2++;

    } while (1);
    return counter;
}