// 26. ɾ�����������е��ظ���

//˫ָ��
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
//         if (nums[left] != nums[right]) //���Ҳ�Ϊ����ͬ
//         {
//             left++;
//             nums[left] = nums[right];
//         }
//     }
//     return left + 1;
// }