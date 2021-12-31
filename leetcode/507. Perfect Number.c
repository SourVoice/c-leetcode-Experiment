// 507. ÍêÃÀÊı
#include <stdbool.h>

bool checkPerfectNumber(int num)
{
    if (num <= 1)
        return false;
    int sum = 1;
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            sum += i;
            if (sum > num)
                return false;
        }
        // int low = i;
        // int high = num;
        // int mid = high + (low - high) / 2;
        // while (low < high)
        // {
        //     if (i * mid > num)
        //         high = mid - 1;
        //     else if (i * high < num)
        //         low = mid + 1;
        //     if (i * mid == num)
        //         sum += i;
        // }
    }
    return sum == num;
}
/*
#include <iso646.h>

bool checkPerfectNumber(int num)
{
    return num == 6 or num == 28  or num == 496 or num == 8128 or num == 33550336;
}
*/