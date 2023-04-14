// 735. 行星碰撞
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> sk;
        for (auto asteroid : asteroids)
        {
            if (sk.empty())
            {
                sk.emplace_back(asteroid);
                continue;
            }
            auto cur = sk.back();
            /**
             * 当前值的绝对值大于栈顶元素，此时栈顶元素被消灭， 即栈顶元素出栈，然后循环进行判断。
             * 当前值的绝对值小于栈顶元素，此时当前值被消灭，直接跳过当前元素，处理下一个数组元素。
             * 当前值的绝对值等于栈顶元素，此时 栈顶元素和当前值都被消灭，即栈顶元素跳栈，且跳过当前元素，处理下一个数组元素。
             */
            bool next = false;
            while (!sk.empty() && cur > 0 && asteroid < 0)
            {
                if (abs(cur) < abs(asteroid))
                {
                    sk.pop_back();
                }
                else if (abs(cur) > abs(asteroid))
                {
                    next = true;
                    break;
                }
                else if (abs(cur) == abs(asteroid))
                {
                    sk.pop_back();
                    next = true;
                    break;
                }
                if (!sk.empty())
                    cur = sk.back();
            }
            if (!next)
                sk.emplace_back(asteroid);
        }
        return vector<int>(begin(sk), end(sk));
    }
};