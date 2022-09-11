#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;
//Ì°ÐÄ
class Solution
{
public:
    int partitionString(string s)
    {
        int n = s.size();
        set<char> st;
        int cnt = 1;
        for (auto &a : s)
        {
            if (st.count(a))
                st.clear(), cnt++;
            st.emplace(a);
        }
        return cnt;
    }
};