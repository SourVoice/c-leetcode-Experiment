// 66. º”“ª
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
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i)
        {
            int carry = 0;
            if (digits[i] + 1 == 10)
            {
                digits[i] = 0;
                if (i == 0)
                    digits.insert(digits.begin(), 1);
            }
            else
            {
                digits[i]++;
                break;
            }
        }
        return digits;
    }
};