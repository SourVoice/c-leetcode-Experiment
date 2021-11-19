/*397. ÕûÊıÌæ»»*/

#define min(x, y) (x < y ? x : y)

long calculate(long n, long step)
{
    if (n == 1)
    {
        return 0;
    }
    if (n % 2 == 0)
    {
        return 1 + calculate(n / 2, step + 1);
    }
    else
    {
        return 1 + min(calculate(n - 1, step + 1), calculate(n + 1, step + 1));
    }
}

int integerReplacement(int n)
{
    long step = 0;
    return calculate(n, step);
}