// 2029. й╞вссно╥ IX
#include <vector>

class Solution
{
public:
    bool stoneGameIX(std::vector<int> &stones)
    {
        int len = stones.size();
        std::vector<int> nums(3);
        for (auto val : stones)
        {
            nums[val % 3]++;
        }

        if ((nums[0] & 1) == 0)
        {
            if (nums[1] > 0 && nums[2] > 0)
                return true;
            else
                return false;
        }
        else
        {
            return abs(nums[1] - nums[2]) > 2;
        }
    }
};