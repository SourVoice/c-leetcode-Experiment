#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <string>
using namespace std;
class Solution
{
public:
    int countDistinctIntegers(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            string num = to_string(nums[i]);
            reverse(num.begin(), num.end());
            nums.push_back(atoi(num.c_str()));
        }
        set<int> st;
        for (auto &num : nums)
            st.emplace(num);
        return st.size();
    }
};
// 数字反转
class Solution
{
public:
    int countDistinctIntegers(vector<int> &nums)
    {
        unordered_set<int> st;
        // 把所有数加入 set
        for (int x : nums)
            st.insert(x);

        auto reverseNum = [](const int &x) -> int
        {
            int y = 0;
            for (int t = x; t; t /= 10)
                y = y * 10 + t % 10;
            return y;
        };
        for (int x : nums)
        {
            // 把每个数的反转加入 set
            int y = 0;
            for (int t = x; t; t /= 10)
                y = y * 10 + t % 10;
            st.insert(y);
        }
        return st.size();
    }
};
