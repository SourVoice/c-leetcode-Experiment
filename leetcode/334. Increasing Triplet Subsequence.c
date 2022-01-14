// 334. ��������Ԫ������
//̰��
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
        else if (num > first) //������������С��,��С��second
            second = num;
        else //������С����С��
            first = num;
    }
    return false;
}
