#include <stdio.h>
#include <limits.h>
int reverse(int x)
{
    int ret = 0;
    printf("%d", _I32_MAX);
    while (x)
    {
        if (ret > 0 && ret * 10 < ret)
            return 0;
        if (ret < 0 && ret * 10 > ret)
            return 0;
        ret = ret * 10 + x % 10;
        printf("%d\n", ret);

        x = x / 10;
    }
    return ret;
}
int main(void)
{
    printf("%d", reverse(1534236469));
    return 0;
}