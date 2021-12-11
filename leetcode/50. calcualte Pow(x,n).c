#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/*
 * @lc app=leetcode.cn id=50 lang=c
 *
 * [50] Pow(x, n)
 */

// @lc code=start
//位运算法:
double myPow(double x, int n)
{
    double res = 1;
    while (n)
    {
        if (n & 1)
            res = n > 0 ? res * x : res / x;
        x = x * x;
        n = n / 2;
    }
    return res;
}
// 迭代法iterative way
double myPow(double x, int n)
{
    double res = 1;
    while (n)
    {
        if (n % 2) // depose n as binary number and
                   // then keep multiplying for x to raise to some power of 2 value
                   // as we go along.
            res = n > 0 ? res * x : res / x;
        x = x * x;
        n /= 2;
    }
    return res;
}
// 递归法
// double powFunc(double x, uint32_t n)
// {
//     if (n == 1)
//         return x;
//     if (n % 2 != 0)
//     {
//         double intermediate = powFunc(x, n / 2);
//         return intermediate * intermediate * x;
//     }
//     else
//     {
//         double intermediate = powFunc(x, n / 2);
//         return intermediate * intermediate;
//     }
// }

// double myPow(double x, int n)
// {
//     if (n == 0 || x == 1)
//         return 1;
//     if (n < 0)
//         return 1 / powFunc(x, abs(n));
//     return powFunc(x, n);
// }
//暴力法
// double myPow(double x, int n)
// {
//     if (x == 1.0000)
//         return 1.00000;
//     long long N = n;
//     if (n < 0) // n为负
//     {
//         x = 1 / x;
//         N = -N;
//     }
//     double ans = 1.0;
//     for (long long i = 0; i < N; i++)
//     {
//         ans *= x;
//     }
//     return ans;
// }
//递归法
// double quickMul(double x, long long N)
// {
//     if (N == 0)
//     {
//         return 1.0;
//     }
//     double y = quickMul(x, N / 2);
//     return N % 2 == 0 ? y * y : y * y * x;
// }

// double myPow(double x, int n)
// {
//     long long N = n;
//     return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
// }