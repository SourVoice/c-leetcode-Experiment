// 1414. 和为 K 的最少斐波那契数字数目

#include <vector>
#include <queue>
#include <stack>
using namespace std;
//贪心算法
class Solution
{
public:
    int findMinFibonacciNumbers(int k)
    {
        vector<int> fibonacci;
        fibonacci.push_back(1);
        fibonacci.push_back(1);
        while (fibonacci.back() <= k)
        {
            fibonacci.push_back(fibonacci[fibonacci.size() - 1] + fibonacci[fibonacci.size() - 2]);
        }
        fibonacci.pop_back();
        int ans = 0;
        int sum = 0;
        stack<int> q;
        for (auto it = fibonacci.rbegin(); it != fibonacci.rend() && sum != k; it++)
        {
            while (sum < k)
            {
                sum += *it;
                q.push(*it);
                ans++;
            }
            if (sum == k)
                break;
            sum -= q.top();
            q.pop();
            ans--;
        }
        return q.size();
    }
};