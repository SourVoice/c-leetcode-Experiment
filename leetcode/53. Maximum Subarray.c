// 53. 最大子数组和
int maxSubArray(int *nums, int numsSize)
{
    int res = INT_MIN;
    int count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        count = 0;
        for (int j = i; j < numsSize; j++)
        {
            count += nums[j];
            res = count > res ? count : res;
        }
    }
    return res;
}