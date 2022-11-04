// 344. 反转字符串
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
// 双指针
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int n = s.size();
        for (int i = 0, j = n - 1; i < j;)
            swap(s[i++], s[j--]);
    }
};
// stl解决
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        reverse(s.begin(), s.end());
    }
};