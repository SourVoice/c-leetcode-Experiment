// 1760. 袋子里最少数目的球
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
using namespace std;
class Solution
{
public:
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        sort(begin(nums), end(nums));
        int max_ = nums[nums.size() - 1];
        int l = 1, r = max_;
        int operation = 0;
        int mid = 0;
        //找到最大的拆分值
        while (l < r)
        {
            mid = (l + r) / 2;
            operation = 0;
            for (auto &num : nums)
            {
                operation += num / mid;
                if ((num % mid) == 0)
                    operation -= 1; // 举例: 8按2拆分会冗余 8->6/2->2/4/2->2/2/2/2(共4次)
            }
            if (operation <= maxOperations)
                r = mid; //相等时左测可能有更小的开销, 我们需要找到最小开销
            else if (operation > maxOperations)
                l = mid + 1;
        }
        return l;
    }
};