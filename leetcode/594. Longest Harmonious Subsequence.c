/*594. 最长和谐子序列*/
#include <stdlib.h>
int cmpfunc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int max(int x, int y)
{
    return x - y < 0 ? x : y;
}
int findLHS(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int ans = 0;
    int str = 0;
    for (int end = 1; end < numsSize; end++)
    {
        if (nums[end] - nums[str] > 1)
        {
            str++;
        }
        if (nums[end] - nums[str] == 1)
        {
            ans = max(ans, end - str + 1);
        }
    }
    return ans;
}
//本题巧在需要在子序列中找出最大和最小值的差为1,也就是子序列只可能由两个相同元素组成,所以排序并不影响结果.