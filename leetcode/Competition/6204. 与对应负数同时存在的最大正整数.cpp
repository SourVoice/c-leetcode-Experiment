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
// Ë«Ö¸Õë
class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] < 0)
                i++;
            else if (nums[i] + nums[j] > 0)
                j--;
            else
                return nums[j];
        }
        return -1;
    }
};
