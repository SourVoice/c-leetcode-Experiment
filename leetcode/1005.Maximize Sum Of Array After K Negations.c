// 1005. K 次取反后最大化的数组和
//首次用到贪心算法
#include <stdlib.h>
#include <stdio.h>
int comFunc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int largestSumAfterKNegations(int *nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), comFunc);
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < 0 && k > 0)
        {

            nums[i] = -nums[i];
            k--;
        }
        sum += nums[i];
    }
    qsort(nums, numsSize, sizeof(int), comFunc); //再进行一次排序,以确保被反转的负数也参与return操作
    return sum - (k % 2 == 0 ? 0 : nums[0] * 2);
}