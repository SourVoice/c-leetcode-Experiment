// 1567. �˻�Ϊ������������鳤��
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//��̬�滮
class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> postive(n + 1, 0), negative(n + 1, 0); // �������±�i��β�ĳ˻�Ϊ��������Ϊ������,�������
        if (nums[0] > 0)
            postive[0] = 1;
        else if (nums[0] < 0)
            negative[0] = 1;
        int ret = postive[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > 0)
            {
                postive[i] = postive[i - 1] + 1;
                negative[i] = negative[i - 1] ? negative[i - 1] + 1 : 0;
            }
            if (nums[i] < 0)
            {
                postive[i] = negative[i - 1] ? negative[i - 1] + 1 : 0;
                negative[i] = postive[i - 1] + 1;
            }
            if (nums[i] == 0)
            {
                postive[i] = 0;
                negative[i] = 0;
            }
            ret = max(ret, postive[i]);
        }
        return ret;
    }
};