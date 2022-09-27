// 1498. ������������������Ŀ
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
// ��ʱ
class Solution
{
public:
    typedef long long ll;
    int numSubseq(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int l = nums[0], r = nums[n - 1];
        ll cnt = 0;
        vector<int> pow(n + 1, 1);
        for (int i = 1; i < n; i++)
            pow[i] = (pow[i - 1] << 1) % mod;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (j < n && nums[i] + nums[j] <= target)
                j++;
            j--;
            if (j >= i)
                cnt += pow[j - i];
        }
        return cnt % mod;
    }

private:
    int mod = 1e9 + 7;
};
// ���ֲ�����СĿ��ֵ
class Solution
{
public:
    typedef long long ll;
    int numSubseq(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(begin(nums), end(nums));
        ll cnt = 0;
        vector<int> pow(n + 1, 1); // ʹ�������¼ÿ��2^i % mod.
        for (int i = 1; i < n; i++)
            pow[i] = (pow[i - 1] << 1) % mod;
        for (int i = 0; i < n && nums[i] <= target - nums[i]; i++)
        {
            auto it = upper_bound(begin(nums) + i, end(nums), target - nums[i]); // �����ҵ���һ������target-nums[i]
            int j = it - begin(nums) - 1;
            if (j >= i)
                cnt += pow[j - i];
        }
        return cnt % mod;
    }

private:
    int mod = 1e9 + 7;
};