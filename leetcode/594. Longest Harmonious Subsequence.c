/*594. ���г������*/
#include <stdlib.h>
int cmpfunc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int findLHS(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmpfunc);
}
