// 763. 划分字母区间
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
// 贪心;哈希表
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, int> pos;
        for (int i = 0; i < s.size(); i++)
            pos[s[i]] = i;

        vector<int> ans;
        for (int i = 0; i < s.size(); i++)
        {
            int max = pos[s[i]];
        LOOP:
            for (int j = i; j < max; j++)
            {
                if (pos[s[j]] > max)
                {
                    max = pos[s[j]];
                    goto LOOP;
                }
            }
            ans.push_back(max - i + 1);
            i += max - i;
        }
        return ans;
    }
};
// 化简代码
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, int> pos;
        for (int i = 0; i < s.size(); i++)
            pos[s[i]] = i;

        vector<int> ans;
        for (int i = 0; i < s.size(); i++)
        {
            int max = pos[s[i]];
            for (int j = i; j < max; j++)
                if (pos[s[j]] > max)
                    max = pos[s[j]];
            ans.push_back(max - i + 1);
            i += max - i;
        }
        return ans;
    }
};