#include <string>
#include <stack>
#include <functional>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
using namespace std;
class Solution
{
public:
    vector<int> exchange(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            if (!(nums[r] & 1))
            {
                r--;
                continue;
            }
            if (nums[l] & 1)
            {
                l++;
                continue;
            }
            swap(nums[l], nums[r]);
        }
        return nums;
    }
};
// �����˫ָ��

class Solution
{
public:
    vector<int> exchange(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            while (l < r && nums[l] % 2 == 1) // ����
                l++;
            while (l < r && nums[r] % 2 == 0) // ż��
                r--;
            swap(nums[l], nums[r]);
        }
    }
};