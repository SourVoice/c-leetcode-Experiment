// 26. 删除有序数组中的重复项

//双指针
int removeDuplicates(int *nums, int numsSize)
{
    if (!numsSize)
        return 0;
    int count = 0;
    int *leftp = nums;
    for (int *rightp = leftp + 1; rightp < nums + numsSize; rightp++)
    {
        if (*leftp != *rightp)
        {
            count++;
            leftp++;
            *leftp = *rightp;
        }
    }
    return count + 1;
}

// int removeDuplicates(int *nums, int numsSize)
// {
//     if (numsSize == 0)
//         return nums;

//     int left = 0;
//     for (int right = 1; right < numsSize; right++)
//     {
//         if (nums[left] != nums[right]) //当右不为左相同
//         {
//             left++;
//             nums[left] = nums[right];
//         }
//     }
//     return left + 1;
// }