// 367. 有效的完全平方数
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int left = 0, right = sqrt(num);
        while (left <= right)
        {
            int mid = ((left - right) >> 1) + right, ret = mid * mid;
            if (ret > num)
                right = mid - 1;
            else if (ret < num)
                left = mid + 1;
            else
                return true;
        }
        return false;
    }
};