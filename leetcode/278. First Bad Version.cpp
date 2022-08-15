// 278. 第一个错误的版本
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int version);
class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 1, right = n;
        int lastBad = n;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid))
                lastBad = mid, right = mid;
            else
                left = mid + 1;
        }
        return lastBad;
    }
};