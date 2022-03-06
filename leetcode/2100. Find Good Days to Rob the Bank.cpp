// 2100. 适合打劫银行的日子
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

//单调栈,能解决大部分用例
class Solution
{
public:
    vector<int> goodDaysToRobBank(vector<int> &security, int time)
    {
        int n = security.size();

        if (time == 0)
        {
            goto read;
        }

        if (n > 1)
        {

            for (int i = 1; i < n; i++)
            {
                if (security[i] - security[i - 1] != 1)
                {
                    goto read;
                }
            }
            return {};
        }

    read:
        stack<int> not_decreasing_R;
        stack<int> not_increasing_L;

        vector<int> leftMax(n);
        vector<int> rightMin(n);

        for (int i = 0; i < n; i++)
        {
            while (!not_increasing_L.empty() && security[not_increasing_L.top()] <= security[i])
            {
                not_increasing_L.pop();
            }
            leftMax[i] = not_increasing_L.empty() ? -1 : not_increasing_L.top();
            not_increasing_L.push(i);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!not_decreasing_R.empty() && security[not_decreasing_R.top()] >= security[i])
            {
                not_decreasing_R.pop();
            }
            rightMin[i] = not_decreasing_R.empty() ? n : not_decreasing_R.top();
            not_decreasing_R.push(i);
        }
        for (int i = 0; i < n; i++)
        {
            cout << "leftMax[" << i << "]=" << leftMax[i] << "\t"
                 << "rightMin[" << i << "]=" << rightMin[i] << endl;
        }
        vector<int> ans;
        int first = 1;
        for (int i = 0; i < n; i++)
        {
            if (first)
            {

                if (i - leftMax[i] >= time && rightMin[i] - i - 1 >= time)
                {
                    cout << i << "-" << leftMax[i] << "=" << i - leftMax[i] << "\t" << rightMin[i] << "-" << i << "=" << rightMin[i] - i << endl;
                    ans.push_back(i);
                }
                first = 0;
            }
            else if (i - leftMax[i] - 1 >= time && rightMin[i] - i - 1 >= time)
            {
                cout << i << "-" << leftMax[i] << "=" << i - leftMax[i] << "\t" << rightMin[i] << "-" << i << "=" << rightMin[i] - i << endl;
                ans.push_back(i);
            }
        }
        cout << endl;
        return ans;
    }
};

//动态规划
class Solution2
{
public:
    vector<int> goodDaysToRobBank(vector<int> &security, int time)
    {
        int n = security.size();
        if (n <= 2 * time)
            return {};
        vector<int> right(n, 0), left(n, 0);

        for (int i = 1, j = n - 1; i < n && j > 0; i++, j--)
        {
            if (security[i - 1] >= security[i])
            {
                left[i] = left[i - 1] + 1;
            }

            if (security[j - 1] <= security[j])
            {
                right[j - 1] = right[j] + 1;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (left[i] >= time && right[i] >= time)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};