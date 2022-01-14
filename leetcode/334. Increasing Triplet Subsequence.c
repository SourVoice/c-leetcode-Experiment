// 334. 递增的三元子序列
//贪心
#include <limits.h>
#include <stdbool.h>
bool increasingTriplet(int *nums, int numsSize)
{
    int first = INT_MAX;
    int second = INT_MAX;
    for (int i = 0; i < numsSize; i++)
    {
        int num = nums[i];
        if (num > second)
            return true;
        else if (num > first) //第三个大于最小的,但小于second
            second = num;
        else //第三个小于最小的
            first = num;
    }
    return false;
}
