// 556. 下一个更大元素 III
// https://leetcode.cn/problems/next-permutation/solution/xia-yi-ge-pai-lie-by-leetcode-solution/
// 参考<下一个排列>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int nextGreaterElement(int x)
    {
        long tmp = 0;
        string num = to_string(x);
        int n = num.size();
        int i = n - 2;
        while (i >= 0 && num[i] >= num[i + 1]) // 第一个不按顺序最小的
            i--;
        if (i < 0)
            return -1;
        int j = n - 1;
        while (j >= 0 && num[i] >= num[j]) //第一个比num[i]大的
            j--;
        if (j < 0)
            return -1;
        swap(num[i], num[j]);
        reverse(num.begin() + i + 1, num.end()); // i后面的按照最小排序
        long ret = stol(num);
        return ret > (INT_MAX) ? -1 : ret;
    }
};