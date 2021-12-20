/*二分插入排序*/
/*
1-每次取下一个元素,接着二分查找比它大的位置
2-其他元素错位
*/
#include <stdio.h>
void BinaryInsertSort(int array[], int len)
{
    int target; //要排的元素
    int low, high, middle;
    for (int i = 1; i < len; i++)
    {
        target = array[i];
        high = i - 1;
        while (low <= high)
        {
            middle = (low + high) / 2;
            if (array[middle] > target)

                high = middle - 1;
            else
                low = middle + 1;
        }
        for (int j = i - 1; j >= low; j--)
        {
            array[j + 1] = array[j];
        }
        array[low] = target;
    }
}