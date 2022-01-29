// 884. 两句话中的不常见单词
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        set<string> st1;
        stringstream ss1(s1);
        string intermidiate;
        while (ss1 >> intermidiate)
        {
            if (st1.count(intermidiate))
                st1.erase(intermidiate);
            else
                st1.insert(intermidiate);
        }

        set<string> st2;
        stringstream ss2(s2);
        while (ss2 >> intermidiate)
        {
            if (st2.count(intermidiate))
                st2.erase(intermidiate);
            else
                st2.insert(intermidiate);
        }
        set<string> ans;

        vector<string> res;
        set_symmetric_difference(st1.begin(), st1.end(), st2.begin(), st2.end(), inserter(ans, ans.begin()));
        for (set<string>::const_iterator i = ans.begin(); i != ans.end(); ++i)
        {
            cout << *i << endl;
            res.push_back(*i);
        }
        return res;
    }
};

// hash table
class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        vector<string> res;
        stringstream ss1(s1);
        stringstream ss2(s2);
        string word1, word2;
        unordered_map<string, int> dict;
        while (ss1 >> word1)
        {
            dict[word1]++;
        }
        while (ss2 >> word2)
        {
            dict[word2]++;
        }
        for (auto &p : dict)
        {
            if (p.second == 1)
                res.push_back(p.first);
        }
        return res;
    }
};