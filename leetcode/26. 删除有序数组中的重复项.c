int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize == 0)
        return nums;

    int left = 0;
    for (int right = 1; right < numsSize; right++)
    {
        if (nums[left] != nums[right]) //当右不为左相同
        {
            left++;
            nums[left] = nums[right];
        }
    }
    return left + 1;
}