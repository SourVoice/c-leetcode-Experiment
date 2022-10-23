// 1768. ½»ÌæºÏ²¢×Ö·û´®
#include <string>
#include <stack>
#include <bitset>
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
// ×Ö·û´®
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int i = 0, j = 0;
        string ans;
        while (i < word1.size() && j < word2.size())
        {
            if (i == j)
                ans += word1[i++];
            else
                ans += word2[j++];
        }
        return word1[i] ? ans.append(word1, i) : ans.append(word2, j);
    }
};
