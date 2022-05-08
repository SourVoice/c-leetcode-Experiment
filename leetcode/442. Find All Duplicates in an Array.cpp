// 442. �������ظ�������
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// ��ϣ��;����
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto &num : nums)
        {
            mp[num]++;
        }
        vector<int> ret;
        for (auto &[_, __] : mp)
        {
            if (__ == 2)
                ret.push_back(_);
        }
        return ret;
    }
};

// ����
class Solution2
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [](const int a, const int b)
             { return a < b; });
        vector<int> ret;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
                ret.push_back(nums[i]);
        }
        return ret;
    }
};

//��������
class Solution3
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ret;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int sign = (nums[i] - 1) % n;
            nums[sign] += n;
            if (nums[sign] > 2 * n)
                ret.push_back(sign + 1);
        }
        return ret;
    }
};