// 283. �ƶ���
#include <string>
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
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        nums.erase(remove(begin(nums), end(nums), 0), end(nums));
        for (int i = nums.size(); i < n; i++)
            nums.push_back(0);
    }
};
// ˫ָ��
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int j = 0, n = nums.size();
        // j��¼��0����
        for (int i = 0; i < n; i++)
        {
            if (nums[i])
                nums[j++] = nums[i];
        }
        for (int i = j; i < n; i++)
            nums[i] = 0;
    }
};
// һ�α���
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int j = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            // ������0���������
            if (nums[i])
            {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j++] = tmp;
            }
        }
    }
};