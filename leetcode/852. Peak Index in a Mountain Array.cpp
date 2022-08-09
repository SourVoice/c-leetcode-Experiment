// 852. 山脉数组的峰顶索引
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int left = 0, right = arr.size() - 1;
        while (left < right)
        {
            int mid = (left - right) / 2 + right, ret = arr[mid];
            if (arr[mid - 1] < ret && ret > arr[mid + 1])
                return mid;
            else if (arr[mid - 1] > ret)
                right = mid;
            else if (arr[mid + 1] > ret)
                left = mid;
        }
        return -1;
    }
};