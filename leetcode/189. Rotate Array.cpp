// 189. ��ת����
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
// ʹ�ø�������
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        vector<int> tmp = nums;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int tar = (i + k) % n;
            nums[tar] = tmp[i];
        }
    }
};
// TODO: O(n)�ռ�, ԭ���㷨
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
    }
};
// ��ת����(trick)
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + (k % n));
        reverse(nums.begin() + (k % n), nums.end());
    }
};