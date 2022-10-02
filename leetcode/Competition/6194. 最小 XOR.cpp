
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
// 超时
class Solution
{
public:
    // 返回二进制第一个有效位位置
    int msb(int x)
    {
        return 31 - __builtin_clz(x);
    }
    int minimizeXor(int num1, int num2)
    {
        // 返回所有有效位的个数
        auto count1 = [&](const int &num) -> int
        {
            int n = num;
            n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
            n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
            n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
            n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
            n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
            return n;
        };
        int n = msb(max(num1, num2));
        int number2 = count1(num2); // 置位数
        int xorRet = INT_MAX;
        int ret = 0;
        int begin = (0xffffffff >> (31 - number2 + 1));
        int end = (0xffffffff >> (31 - n));
        // cout << (0xffffffff >> (31 - min(number1, number2)) + 1) << " " << (0xffffffff >> (31 - n)) << endl;
        for (int i = begin; i <= end; i++)
        {
            if (count1(i) == number2)
            {
                if ((num1 ^ i) < xorRet)
                {
                    xorRet = num1 ^ i;
                    ret = i;
                    if (xorRet == 0)
                        return ret;
                }
            }
        }
        return ret;
    }
};
// 贪心, 将num1中k个1反转, 能得到的最小值
class Solution
{
public:
    int minimizeXor(int num1, int num2)
    {
        // 返回二进制所有有效位的个数
        auto count1 = [&](const int &num) -> int
        {
            int n = num;
            n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
            n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
            n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
            n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
            n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
            return n;
        };
        int k = count1(num2); // 置位数
        int bitsNum1[32];
        for (int i = 0; i <= 31; i++)
            bitsNum1[i] = num1 >> (31 - i) & 1;

        bool visited[32] = {0};
        for (int i = 0; i <= 31; i++)
            if (bitsNum1[i] && k) // 高位的1置0
                bitsNum1[i] = 0, k--, visited[i] = 1;

        for (int i = 31; i >= 0; i--)
            if ((!bitsNum1[i]) && k && (!visited[i])) // 有剩余k, 且位置没有被置过(有剩余k表示一定1已经被置完了), 低位0置1
                bitsNum1[i] = 1, k--, visited[i] = 1;
        int ret = 0;
        for (int i = 0; i <= 31; i++)
            ret += visited[i] << (31 - i);
        return ret;
    }
};