// * [35] 搜索插入位置

//蓝方法
// int searchInsert(int *nums, int numsSize, int target)
// {

//     int low = 0;
//     int high = numsSize - 1;
//     int mid = (low - high) / 2 + high;
//     while (low != high && low < high)
//     {
//         if (nums[mid] == target)
//             break;
//         if (nums[mid] < target)
//             low = mid + 1;
//         else if (nums[mid] > target)
//             high = mid - 1;
//         mid = (low - high) / 2 + high;
//         if (nums[mid] != target && low == high)
//             break;
//         if (low == high)
//         {
//             if (nums[low] > target)
//                 return mid - 1;
//             if (nums[high] < target)
//                 return mid + 1;
//         }
//     }
//     return nums[mid] != target ? (nums[mid] < target ? mid + 1 : mid) : mid;
// }
int searchInsert(int *nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1, ans = numsSize;
    while (left <= right)
    {
        int mid = ((right - left) >> 1) + left;
        if (target <= nums[mid])
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}
