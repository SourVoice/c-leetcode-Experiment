// 69. x ��ƽ����
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//���ֲ���
class Solution
{
public:
    int mySqrt(int x)
    {
        int left = 0, right = x;
        while (left < right)
        {
            int mid = (left - right) / 2 + right;
            // ��� mid * mid С�ڻ���� x��˵��mid���������һ��ƽ��С��x����, ����ǡ����x
            if (x / mid >= mid)
                left = mid;
            else if (x / mid < mid)
                right = mid - 1;
        }
        return left;
    }
};