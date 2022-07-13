// 122. 买卖股票的最佳时机 II
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ret = 0;
        // 因为交易次数不受限，如果可以把所有的上坡全部收集到，一定是利益最大化的
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
                ret += prices[i] - prices[i - 1];
        }
        return ret;
    }
};