// 374. 猜数字大小
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);
//二分查找
class Solution
{
public:
    int guessNumber(int n)
    {
        int l = 1, r = n;
        while (l <= r)
        {
            int mid = (l - r) / 2 + r, ret = guess(mid);
            if (ret < 0)
                r = mid - 1;
            else if (ret > 0)
                l = mid + 1;
            else
                return mid;
        }
        return 0;
    }
};