// 75. 颜色分类
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
// 朴素法
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = n - 1;
        int tmp = 0;
        int tmp_j = 0;
        while (i < j)
        {
            if (nums[i] == 2)
            {
                while (j > i && nums[j] == 2)
                    j--;
                swap(nums[i], nums[j]);
                j--;
            }
            else if (nums[i] == 1)
            {
                tmp_j = j;
                while (j > i && nums[j] >= 1)
                    j--;
                swap(nums[i], nums[j]);
                i++;
                j = tmp_j;
            }
            else if (nums[i] == 0)
            {
                if (nums[j] == 0)
                {
                    while (j > i && nums[i] == 0)
                        i++;
                    swap(nums[i], nums[j]);
                }
                i++;
            }
        }
    }
};
// 三指针
// 只处理0和1
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = 0, k = n - 1;
        while (i < j)
        {
            if (nums[j] == 0) // 此时交换的一定是1
                swap(nums[i++], nums[j++]);
            else if (nums[j] == 2) // 防止交换过来的数较小, j不做操作
                swap(nums[k--], nums[j]);
            else
                j++;
        }
    }
};
