// 1995. 统计特殊四元组

// int cmpFun(const void *a, const void *b)
// {
//     return (*(int *)a - *(int *)b);
// }

// int countQuadruplets(int *nums, int numsSize)
// {

//     qsort(nums, numsSize, sizeof(nums[0]), cmpFun);
//     int *numpos = nums;
//     int *numend = nums + 3;

//     int ans = 0;
//     for (int *numspos = nums; numspos < numsSize + nums - 3; numspos++)
//     {
//         for (int *numsplus3; numspos < numsSize + ; numsplus3++)
//         {
//         }
//     }
//     return ans;
// }

int countQuadruplets(int *nums, int numsSize)
{

    qsort(nums, numsSize, sizeof(nums[0]), cmpFun);
    int *numpos = nums;
    int *numend = nums + 3;

    int ans = 0;
    for (int i = 0; i < numsSize - 3; i++)
    {
        for (int j = i + 1; j < numsSize - 2; j++)
        {
            for (int m = j + 1; m < numsSize - 1; m++)
            {
                for (int n = m + 1; n < numsSize; n++)
                {
                    if (nums[i] + nums[j] + nums[m] == nums[n])
                        ans++;
                }
            }
        }
    }
    return ans;
}