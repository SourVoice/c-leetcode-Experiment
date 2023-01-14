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
#include <sstream>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());
        stringstream ss(s);
        string word;
        string ret;
        while (ss >> word)
        {
            reverse(word.begin(), word.end());
            ret.append(word);
            ret.push_back(' ');
        }
        ret.pop_back();
        return ret;
    }
};