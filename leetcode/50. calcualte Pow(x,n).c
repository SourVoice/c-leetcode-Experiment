/*
 * @lc app=leetcode.cn id=50 lang=c
 *
 * [50] Pow(x, n)
 */

// @lc code=start
double powFunc(double x, uint32_t n)
{
    if (n == 1)
        return x;
    if (n % 2 != 0)
    {
        double intermediate = powFunc(x, n / 2);
        return intermediate * intermediate * x;
    }
    else
    {
        double intermediate = powFunc(x, n / 2);
        return intermediate * intermediate;
    }
}

double myPow(double x, int n)
{
    if (n == 0 || x == 1)
        return 1;
    if (n < 0)
        return 1 / powFunc(x, abs(n));
    return powFunc(x, n);
}
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