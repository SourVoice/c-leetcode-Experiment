// 287. Ѱ���ظ���
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
// ����ָ��
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;
        for (; slow != fast || fast == 0;)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        // nums���������, ���Բ�һ������ڴ�����
        for (int i = 0; i != slow; i = nums[i])
        {
            slow = nums[slow];
        }
        return slow;
    }
};
// ����, ����ԭ��
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int left = 1, right = nums.size() - 1;
        auto count = [&](const vector<int> &nums, int mid) -> int
        {
            int cnt = 0;
            for (auto &num : nums)
            {
                if (num <= mid)
                    cnt++;
            }
            return cnt;
        };
        while (left < right)
        {
            int mid = ((right - left) >> 1) + left;
            if (count(nums, mid) <= mid)
                left = mid + 1;
            else // ����mid�����ϸ����mid, ��ʾ�ظ�����һ����������
                right = mid;
        }
        return left;
    }
};
