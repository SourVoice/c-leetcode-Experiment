// 953. —È÷§Õ‚–«”Ô¥ µ‰
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        unordered_map<char, int> mp;
        vector<string> copy = words;
        int number = 0;
        for (auto &c : order)
            mp[c] = number++;
        sort(words.begin(), words.end(), [&](const string &a, const string &b)
             {
                int i = 0, j = 0;
                while (i < a.size() && j < b.size())
                {
                    if (mp[a[i]] == mp[b[j]])
                    {
                        if (a[i] == b[j])
                            i++,
                        j++;
                    }
                    else
                    {
                        return mp[a[i]] < mp[b[j]];
                    }
                }
                return a.size() < b.size(); });
        return words == copy;
    }
};