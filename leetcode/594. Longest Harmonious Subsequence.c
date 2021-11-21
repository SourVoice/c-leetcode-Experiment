/*594. ���г������*/
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
//����������Ҫ�����������ҳ�������Сֵ�Ĳ�Ϊ1,Ҳ����������ֻ������������ͬԪ�����,�������򲢲�Ӱ����.