// 45. ��Ծ��Ϸ
#include <vector>
using namespace std;

//̰��
class Solution
{
public:
    int canJump(vector<int> &nums)
    {
        int n = nums.size();
        int max_reach = nums[0];
        int start = 0;

        for (int i = 0; i < n; i++)
        {
            if (i <= max_reach)
            { //�ж��ܹ��������Զ����j
                max_reach = max(max_reach, nums[i] + i);
            }
            else // max_reach���ܵ���i,ֱ���˳�
            {
                return false;
            }
        }
        return max_reach >= n - 1;
    }
};

//��̬�滮,dp,����˼ά
class Solution2
{
public:
    int canJump(vector<int> &nums)
    {
        int n = nums.size();
        int lastPlace = nums.size() - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] + i >= lastPlace)
            {
                lastPlace = i;
            }
            else
                continue;
        }
        return lastPlace == 0;
    }
};

//����˼ά:
class Solution3
{
public:
    int canJump(vector<int> &nums)
    {
        int n = nums.size();
        int max_reach = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] < max_reach - i)
            {
                continue;
            }
            else //��i���Ե���max_reach��
            {
                max_reach = i;
            }
        }
        return max_reach == 0;
    }
};
