int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize == 0)
        return nums;

    int left = 0;
    for (int right = 1; right < numsSize; right++)
    {
        if (nums[left] != nums[right]) //���Ҳ�Ϊ����ͬ
        {
            left++;
            nums[left] = nums[right];
        }
    }
    return left + 1;
}