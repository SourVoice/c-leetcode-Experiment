// 556. ��һ������Ԫ�� III
// https://leetcode.cn/problems/next-permutation/solution/xia-yi-ge-pai-lie-by-leetcode-solution/
// �ο�<��һ������>
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
        while (i >= 0 && num[i] >= num[i + 1]) // ��һ������˳����С��
            i--;
        if (i < 0)
            return -1;
        int j = n - 1;
        while (j >= 0 && num[i] >= num[j]) //��һ����num[i]���
            j--;
        if (j < 0)
            return -1;
        swap(num[i], num[j]);
        reverse(num.begin() + i + 1, num.end()); // i����İ�����С����
        long ret = stol(num);
        return ret > (INT_MAX) ? -1 : ret;
    }
};