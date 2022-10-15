// 1441. 用栈操作构建数组
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
// 模拟
class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        int index = 0;
        vector<string> ans;
        for (int i = 0; i < n; i++)
        {
            if (target[index] == i + 1)
            {
                ans.push_back("Push");
                index++;
            }
            else
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            if (index >= target.size())
                break;
        }
        return ans;
    }
};