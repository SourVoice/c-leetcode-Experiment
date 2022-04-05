// 45. 跳跃游戏
#include <vector>
using namespace std;

//贪心
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
            { //判断能够到达的最远距离j
                max_reach = max(max_reach, nums[i] + i);
            }
            else // max_reach不能到达i,直接退出
            {
                return false;
            }
        }
        return max_reach >= n - 1;
    }
};

//动态规划,dp,逆向思维
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

//逆向思维:
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
            else //从i可以到达max_reach处
            {
                max_reach = i;
            }
        }
        return max_reach == 0;
    }
};
