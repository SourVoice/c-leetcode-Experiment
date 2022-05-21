// 961. �ڳ��� 2N ���������ҳ��ظ� N �ε�Ԫ��
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto &num : nums)
        {
            if (mp.count(num))
                return num;
            mp[num]++;
        }
        return 0;
    }
};