// 384. 打乱数组
#include <string>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
using namespace std;
// 洗牌算法模拟(暴力
// Fisher–Yates洗牌算法)
class Solution
{
public:
    Solution(vector<int> &nums)
    {
        this->nums = nums;
        this->orig = nums;
    }

    vector<int> reset()
    {
        return orig;
    }

    vector<int> shuffle()
    {
        list<int> ls(begin(nums), end(nums));
        vector<int> shuffled(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            int j = rand() % (ls.size());
            auto it = ls.begin();
            advance(it, j); // 移动迭代器
            shuffled[i] = *it;
            ls.erase(it);
        }
        return shuffled;
    }

private:
    vector<int> nums, orig;
};
// Knuth-Durstenfeld洗牌算法, 原地算法
class Solution
{
public:
    Solution(vector<int> &nums)
    {
        this->nums = nums;
        this->orig = nums;
    }

    vector<int> reset()
    {
        return orig;
    }

    vector<int> shuffle()
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            int j = i + rand() % (nums.size() - i); // 更新待乱序数组的长度, 即i之后的长度
            swap(nums[i], nums[j]);
        }
        return nums;
    }

private:
    vector<int> nums, orig;
};

// C语言题解:
typedef struct
{
    int *nums;
    int numsSize;
} Solution;

Solution *solutionCreate(int *nums, int numsSize)
{
    Solution *obj = (Solution *)malloc(sizeof(Solution));
    obj->numsSize = numsSize;
    obj->nums = (int *)malloc(sizeof(int) * numsSize);
    memset(obj->nums, 0, sizeof(int) * numsSize);
    memcpy(obj->nums, nums, sizeof(int) * numsSize);
    return obj;
}

int *solutionReset(Solution *obj, int *retSize)
{
    int *ans = (int *)malloc(sizeof(int) * obj->numsSize);
    memset(ans, 0, sizeof(int) * obj->numsSize);
    memcpy(ans, obj->nums, sizeof(int) * obj->numsSize);
    *retSize = obj->numsSize;
    return ans;
}

int *solutionShuffle(Solution *obj, int *retSize)
{
    *retSize = obj->numsSize;
    int *ans = (int *)malloc(sizeof(int) * obj->numsSize);
    memset(ans, 0, sizeof(int) * obj->numsSize);
    memcpy(ans, obj->nums, sizeof(int) * obj->numsSize);
    int index = 0;
    for (int i = 0; i < obj->numsSize; i++)
    {
        index = (rand()) % (obj->numsSize);
        int temp = ans[i];
        ans[i] = ans[index];
        ans[index] = temp;
    }
    return ans;
}

void solutionFree(Solution *obj)
{
    if (obj != NULL)
    {
        free(obj->nums);
        free(obj);
    }
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);

 * int* param_2 = solutionShuffle(obj, retSize);

 * solutionFree(obj);
*/