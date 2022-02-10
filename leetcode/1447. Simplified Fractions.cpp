// 1447. ������
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <numeric> //c++17 gcd()��׼��
using namespace std;
class Solution
{
public:
    vector<string> simplifiedFractions(int n)
    {
        vector<string> ans;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (gcd(i, j) == 1)
                {
                    ans.push_back(to_string(j) + "/" + to_string(i));
                }
            }
        }
        return ans;
    }
    int gcd(int a, int b) //�����Լ��
    {
        if (a < b)
            return gcd(b, a);
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    int gcd2(int m, int n) //ѭ��д��
    {
        int t = 1;
        while (t != 0)
        {
            t = m % n;
            m = n;
            n = t;
        }
        return m;
    }
};

// gnu�ڲ�����ʹ��
class Solution2
{
public:
    vector<string> simplifiedFractions(int n)
    {
        vector<string> ans;
        for (int denominator = 2; denominator <= n; ++denominator)
        {
            for (int numerator = 1; numerator < denominator; ++numerator)
            {
                if (__gcd(numerator, denominator) == 1)
                {
                    ans.emplace_back(to_string(numerator) + "/" + to_string(denominator));
                }
            }
        }
        return ans;
    }
};
