/*400. 第 N 位数字*/
#include <math.h>
//超时
int findNthDigit(int n)
{
    long sum = 0; //rec the pos of all the nums
    long numth = 0;
    for (long i = 1; i <= n; i++)
    {
        while (numth + 1 < pow(10, i))
        {
            sum += i;
            numth++;
            if (n <= sum)
            {
                // printf("numth = %d, sum = %d\n",numth, sum);
                return numth % (int)pow(10, sum - n + 1) / pow(10, sum - n);
            }
        }
    }
    return 0;
}
//1,3,4,5,6,7,8,9,10,11,12