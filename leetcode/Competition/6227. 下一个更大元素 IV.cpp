// 60��˫����
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
// ����ջ
class Solution
{
public:
    vector<int> secondGreaterElement(vector<int> &nums)
    {
        vector<int> ans(nums.size(), -1);
        stack<int> s, t; // t �洢�Ѿ���һ������Ԫ�ص�Ԫ�ص�λ��, s �洢�Ҳ�û�и���ֵ��λ��(�ݼ�ջ)
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