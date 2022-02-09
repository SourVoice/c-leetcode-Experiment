// 2006. ��ľ���ֵΪ K ��������Ŀ

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

//˫��ѭ��
class Solution
{
public:
    int countKDifference(vector<int> &nums, int k)
    {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (abs(nums[i] - nums[j]) == k)
                    ans++;
            }
        }
        return ans;
    }
};

//һ�α���
class Solution2
{
public:
    int countKDifference(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int ans = 0, n = nums.size();
        for (auto &num : nums)
        {
            ans += (mp.count(num - k) ? mp[num - k] : 0); // j֮ǰi������
            ans += (mp.count(num + k) ? mp[num + k] : 0);
            mp[num]++;
        }
        return ans;
    }
};
