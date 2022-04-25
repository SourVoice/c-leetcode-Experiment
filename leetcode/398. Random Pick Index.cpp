// 398. ���������
#include <map>
#include <vector>
using namespace std;

//��ˮ��
class Solution
{
public:
    Solution(vector<int> &nums)
    {
        this->nums = nums;
        n = nums.size();
    }

    int pick(int target)
    {
        int idx = 0, d = 0; // denominator
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                d++;
                if (rand() % d == 0)
                    idx = i;
            }
        }
        return idx;
    }

private:
    vector<int> nums;
    int n;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

// ��ϣ��, ����������

class Solution
{
public:
    Solution(vector<int> &nums)
    {
        this->nums = nums;
        n = nums.size();
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }
    }
    int pick(int target)
    {
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                return mp[target][rand() % mp[target].size()];
            }
        }
    }

private:
    vector<int> nums;
    int n;
    map<int, vector<int>> mp;
};