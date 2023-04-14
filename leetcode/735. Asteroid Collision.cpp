// 735. ������ײ
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
             * ��ǰֵ�ľ���ֵ����ջ��Ԫ�أ���ʱջ��Ԫ�ر����� ��ջ��Ԫ�س�ջ��Ȼ��ѭ�������жϡ�
             * ��ǰֵ�ľ���ֵС��ջ��Ԫ�أ���ʱ��ǰֵ������ֱ��������ǰԪ�أ�������һ������Ԫ�ء�
             * ��ǰֵ�ľ���ֵ����ջ��Ԫ�أ���ʱ ջ��Ԫ�غ͵�ǰֵ�������𣬼�ջ��Ԫ����ջ����������ǰԪ�أ�������һ������Ԫ�ء�
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