// 88³¡
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <list>
using namespace std;
class Solution
{
public:
    bool equalFrequency(string word)
    {
        set<char> st;
        for (int i = 0; i < word.size(); i++)
        {
            if (st.count(word[i]))
                continue;
            else
                st.emplace(word[i]);
            string s = word;
            vector<int> pool(26, 0);
            s.erase(find(begin(s), end(s), word[i]));
            for (auto &e : s)
                pool[e - 'a']++;
            pool.erase(remove(begin(pool), end(pool), 0), end(pool));
            int x = *max_element(begin(pool), end(pool));
            int y = *min_element(begin(pool), end(pool));
            if (x == y)
                return true;
        }
        return false;
    }
};