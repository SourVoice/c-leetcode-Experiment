// 2028. 找出缺失的观测数据

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int rollsSum = 0;
        for (int i = 0; i < rolls.size(); i++)
        {
            rollsSum += rolls[i];
        }
        int missingNum = (n + rolls.size()) * mean - rollsSum;
        if (missingNum < n || missingNum > 6 * n)
            return {};

        // missing num均分给n个数
        int devided = missingNum / n;
        int mod = missingNum % n;
        vector<int> ans;
        for (int i = 0; i < mod; i++)
        {
            ans.push_back(devided + 1);
        }
        for (int i = 0; i < n - mod; i++)
        {
            ans.push_back(devided);
        }
        return ans;
    }
};
