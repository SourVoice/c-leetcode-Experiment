// 633. ƽ����֮��
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;
// ����
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        if (c == 3)
            return false;
        if (c <= 4)
            return true;
        for (long i = 0; static_cast<long>(i * i) < c; i++)
        {
            int left = 0, right = sqrt(c + 1);
            while (left <= right)
            {
                {
                    int mid = (left + right) / 2;
                    long long res = mid * mid;
                    if (res == c - i * i)
                    {
                        return true;
                    }
                    else if (res < c - i * i)
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
            }
        }
        return false;
    }
};
// ˫ָ��
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        int left = 0, right = sqrt(c);
        while (left <= right)
        {
            long long x = static_cast<long>(left * left) + static_cast<long>(right * right);
            if (x < c)
                left++;
            else if (x > c)
                right--;
            else
                return true;
        }
        return false;
    }
};