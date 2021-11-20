/*594. 最长和谐子序列*/
#include <stdlib.h>
int cmpfunc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int findLHS(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmpfunc);
}
