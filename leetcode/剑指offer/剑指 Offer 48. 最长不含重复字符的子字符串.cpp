#include <string>
#include <stack>
#include <functional>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        set<char> st;
        int maxL = 0;
        for (int i = 0, j = 0; i < s.size(); i++)
        {
            while (st.count(s[i]))
                st.erase(s[j++]);
            st.emplace(s[i]);
            maxL = max(maxL, i - j + 1);
        }
        return maxL;
    }
};