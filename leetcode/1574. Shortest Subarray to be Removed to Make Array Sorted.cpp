// 1574. 删除最短的子数组使剩余数组有序
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
class Solution
{
public:
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int n = arr.size();
        int prefix_l = 0, suffix_l = n - 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                prefix_l = i;
                break;
            }
            prefix_l = i + 1;
        }
        for (int i = n - 1; i > 0; i--)
        {
            if (arr[i - 1] > arr[i])
            {
                suffix_l = i;
                break;
            }
            suffix_l = i - 1;
        }
        // 只留下左侧或者右侧
        int removeLen = min(n - prefix_l - 1, suffix_l);
        for (int i = 0; i <= prefix_l; i++)
        {
            if (arr[i] <= arr[suffix_l])
                removeLen = min(removeLen, suffix_l - i - 1);
            else if (suffix_l < n - 1)
                suffix_l += 1;
            else
                break;
        }
        return removeLen < 0 ? 0 : removeLen;
    }
};