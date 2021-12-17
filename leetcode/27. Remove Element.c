
/*
 *  app=leetcode.cn id=27 lang=c
 *
 * [27] ÒÆ³ýÔªËØ
 */

int cmpFunc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int removeElement(int *nums, int numsSize, int val)
{
    if (!numsSize)
        return 0;
    if (numsSize == 1)
        return nums[0] == val ? 0 : numsSize;

    int left = 0;
    qsort(nums, numsSize, sizeof(int), cmpFunc);
    while (nums[left] != val)
    {
        left++;
        if (left == numsSize)
        {
            return numsSize;
        }
    }
    for (int right = left + 1; right < numsSize; right++)
    {
        if (nums[right] != nums[left])
        {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
        }
    }
    return left;
}