// 324. °Ú¶¯ÅÅÐò II
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        vector<int> clone = nums;
        sort(clone.begin(), clone.end());
        int n = nums.size();
        int l = (n - 1) / 2, r = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (i & 1) // even
                nums[i] = clone[r--];
            else
                nums[i] = clone[l--];
        }
    }
};