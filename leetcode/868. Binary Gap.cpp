// 868. 二进制间距
#include <limits>
#include <vector>
using namespace std;

class Solution
{
public:
    int binaryGap(int n)
    {
        int cnt = 0;
        vector<int> all_1_pos;
        while (n)
        {
            if (n & 1)
            {
                all_1_pos.push_back(cnt);
            }
            n >>= 1;
            cnt++;
        }
        if (all_1_pos.size() < 2)
        {
            return 0;
        }
        int max_gap = 0;
        for (int i = 1; i < all_1_pos.size(); i++)
        {
            max_gap = max(max_gap, all_1_pos[i] - all_1_pos[i - 1]);
        }
        return max_gap;
    }
};