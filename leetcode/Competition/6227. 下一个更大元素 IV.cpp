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
#include <stack>
using namespace std;
// 单调栈
class Solution
{
public:
    vector<int> secondGreaterElement(vector<int> &nums)
    {
        vector<int> ans(nums.size(), -1);
        stack<int> s, t; // t 存储已经有一个大于元素的元素的位置, s 存储右侧没有更大值的位置(递减栈)
        for (int i = 0; i < nums.size(); i++)
        {
            stack<int> tmp;
            while (!t.empty() && nums[i] > nums[t.top()])
            {
                ans[t.top()] = nums[i];
                t.pop();
            }
            while (!s.empty() && nums[s.top()] < nums[i])
            {
                tmp.push(s.top());
                s.pop();
            }
            while (!tmp.empty())
            {
                t.push(tmp.top());
                tmp.pop();
            }
            s.push(i);
        }
        return ans;
    }
};