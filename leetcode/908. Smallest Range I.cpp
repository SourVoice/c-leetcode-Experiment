// 908. ��С��ֵ I
#include <vector>
#include <algorithm>
using namespace std;

//��ѧ
class Solution
{
public:
    int smallestRangeI(vector<int> &nums, int k)
    {
        int min_ = *min_element(nums.begin(), nums.end());
        int max_ = *max_element(nums.begin(), nums.end());
        int diff_ = max_ - min_;
        return diff_ >= 2 * k ? diff_ - 2 * k : 0;
    }
};