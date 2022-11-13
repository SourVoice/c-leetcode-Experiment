// 438. 找到字符串中所有字母异位词
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <stdlib.h>
#include <string.h>
using namespace std;
// 滑动窗口优化
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (p.size() > s.size())
            return vector<int>{};
        vector<int> mps(26, 0), mpp(26, 0);
        for (int i = 0; i < p.size(); i++)
            mpp[p[i] - 'a']++, mps[s[i] - 'a']++;
        int winSize = p.size();
        vector<int> ans;
        for (int i = 0; i < s.size() - p.size(); i++)
        {
            if (mps == mpp)
                ans.push_back(i);
            mps[s[i] - 'a']--;
            mps[s[i + winSize] - 'a']++;
        }
        // 最后一个在外面判断, 防止i+winSize越界
        if (mps == mpp)
            ans.push_back(s.size() - p.size());
        return ans;
    }
};
// c题解
int *findAnagrams(char *s, char *p, int *returnSize)
{

    int SMap[26] = {0}; // record alpha's count in s str
    int PMap[26] = {0}; // record alpha's count in P str
    int count = 0;
    int len1 = strlen(s);
    int len2 = strlen(p);
    int len = len1 - len2;
    //维护一个len2长的窗口

    int *res = (int *)calloc(len1 + 1, sizeof(int));
    *returnSize = 0;
    if (len1 < 0 || len2 < 0)
    {
        return res;
    }
    for (int i = 0; i < len2; i++)
    {
        PMap[p[i] - 'a']++;
    }

    char *tmp = s;
    for (int j = 0; j <= len; j++)
    {
        tmp = s + j;
        count = 0;
        for (int k = 0; k < len2; k++)
        {
            SMap[tmp[k] - 'a']++;
        }
        for (int m = 0; m < 26; m++)
        {
            if (SMap[m] == PMap[m])
            {
                count++;
            }
            SMap[m] = 0;
        }
        if (count == 26)
        {
            res[(*returnSize)++] = j;
        }
    }
    return res;
}