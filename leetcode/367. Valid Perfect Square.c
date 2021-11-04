#include <stdio.h>
#include <math.h>
#define bool int

bool isPerfectSquare(int num)
{
    return (int)sqrt(num) * (int)sqrt(num) == num ? 1 : 0;
}
bool isPerfectSquare_Binary(int num) //Binary,���ַ�
{
    int bottom = 1, top = num;
    while (bottom <= top)
    {
        int mid = (top - bottom) / 2 + bottom;
        int tmp = num / mid;

        if (tmp > mid)
            bottom = mid + 1;
        else if (tmp < mid)
            top = mid - 1;
        else
        {
            if (num % mid == 0)
                return 1;
            bottom = mid + 1;
        }
    }
    return 0;
}
bool isPerfectSquare_EnumerateFactor(int num) //�ҳ�һ��num������,����i*i=num
{
    for (int i = 1; i <= num / i; i++)
    {
        if (num == i * i)
            return 1;
    }
    return 0;
}
bool isPerfectSquare_NewtonIteration(int num) //newton iteration method,ţ�ٵ���
{
    double x = num;
    double tmp = 1 + x;
    while (tmp - x > 1e-6)
    {
        tmp = x;
        double res = (x + num / x) / 2;
        x = res;
    }
    return (int)x * (int)x == num;
}
int main()
{
    printf("%d", isPerfectSquare_NewtonIteration(16));
    return 0;
}