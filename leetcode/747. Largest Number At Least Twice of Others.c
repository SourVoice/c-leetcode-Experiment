// 747. 至少是其他数字两倍的最大数

int cmpFunc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int dominantIndex(int *nums, int numsSize)
{
    if (numsSize == 1)
        return 0;
    int *copy = (int *)calloc(numsSize, sizeof(nums[0]));
    for (int i = 0; i < numsSize; i++)
        copy[i] = nums[i];
    qsort(nums, numsSize, sizeof(nums[0]), cmpFunc);
    if (nums[numsSize - 1] >= nums[numsSize - 2] * 2)
    {
        for (int i = 0; i < numsSize; i++)
        {
            if (copy[i] == nums[numsSize - 1])
                return i;
        }
    }
    return -1;
}