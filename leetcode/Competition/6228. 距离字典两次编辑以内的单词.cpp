// 60场双周赛
#include <vector>
#include <map>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
// 6228. 距离字典两次编辑以内的单词
class Solution
{
public:
    vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary)
    {
        set<string> dic;
        for (auto &word : dictionary)
            dic.insert(word);
        auto countTimes = [](const string &s1, const string &s2) -> int
        {
            int i = 0, j = 0;
            int cnt = 0;
            while (i < s1.size() && j < s2.size())
            {
                if (s1[i++] != s2[j++])
                {
                    cnt++;
                    if (cnt > 2)
                        return cnt;
                }
            }
            return cnt;
        };
        vector<string> ans;
        set<string> st;
        for (auto &query : queries)
        {
            for (auto &word : dictionary)
            {
                if (query.size() == word.size())
                {
                    if (countTimes(query, word) <= 2)
                    {
                        ans.push_back(query);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};