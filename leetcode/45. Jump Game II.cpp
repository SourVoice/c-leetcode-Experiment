// 45. ��Ծ��Ϸ II
#include <vector>
using namespace std;

//̰���㷨
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (maxPos >= i)
            {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end)
                {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};

//��̬�滮
class Solution2
{
public:
    int jump(vector<int> &nums)
    {
        int cur = 0, n = nums.size(), end = 0;
        int step = 0;
        for (int i = 0; i < n;i++){
            if(cur>=i){
                cur = max(cur, i + nums[i]);
                if(i == end){
                    end = cur;
                    step++;
                }
            }
        }
        return step;
    }
};