// 1005. K ��ȡ������󻯵������
//�״��õ�̰���㷨
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
    qsort(nums, numsSize, sizeof(int), comFunc); //�ٽ���һ������,��ȷ������ת�ĸ���Ҳ����return����
    return sum - (k % 2 == 0 ? 0 : nums[0] * 2);
}