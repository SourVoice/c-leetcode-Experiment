// 1539. 第 k 个缺失的正整数
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] - (i + 1) >= k) // x - (i + 1) 为arr[i]之前缺失了几个数
                return k + i;
        }
        return k + n;
    }
};