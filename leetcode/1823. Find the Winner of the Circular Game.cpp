// 1823. �ҳ���Ϸ�Ļ�ʤ��
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// simulate
class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        vector<int> died(n, 0);
        int i = 0;
        int all = n;
        int cnt = 0;
        while (n > 1)
        {
            if (!died[i % all])
            {
                cnt++;
            }
            if (cnt == k)
            {
                died[i % all] = 1;
                cnt = 0;
                n--;
            }
            i++;
            i = i % all;
        }
        int ans;
        for (int i = 0; i < all; i++)
        {
            if (died[i] == 0)
            {
                ans = i + 1;
                break;
            }
        }
        return ans;
    }
};

// ����ģ��
class Solution2
{
public:
    int findTheWinner(int n, int k)
    {
        deque<int> dq;
        for (int i = 1; i <= n; i++)
            dq.push_back(i);
        for (int i = 1; i < n; i++) // ÿ�λ�ȥ��һ����, ����ѭ������һ����n-1
        {
            for (int j = 1; j < k; j++)
            {
                int tmp = dq.front();
                dq.push_back(tmp);
                dq.pop_front();
            }
            dq.pop_front();
        }
        return dq.back();
    }
};

// ��ѧ
class Solution3
{
public:
    int findTheWinner(int n, int k)
    {
        int p = 0;
        for (int i = 2; i <= n; i++) // need do n- 1 times
            p = (p + k) % i;
        return p + 1;
    }
};