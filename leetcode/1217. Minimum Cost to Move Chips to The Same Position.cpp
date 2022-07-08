// 1217. Íæ³ïÂë
#include <vector>
using namespace std;
class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {
        int n = position.size();
        int even = 0, odd = 0;
        for (auto e : position)
        {
            (e & 1) ? odd++ : even++;
        }
        return fmin(even, odd);
    }
};