// 553. ×îÓÅ³ý·¨

#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Solution
{
public:
    string optimalDivision(vector<int> &nums)
    {
        if (nums.size() < 2)
        {
            return to_string(nums[0]);
        }
        if (nums.size() == 2)
        {
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        }
        stringstream ss;
        ss << nums[0];
        ss << "/(";
        ss << nums[1];
        for (int i = 2; i < nums.size(); i++)
        {
            ss << "/" << nums[i];
        }
        ss << ")";
        return ss.str();
    }
};