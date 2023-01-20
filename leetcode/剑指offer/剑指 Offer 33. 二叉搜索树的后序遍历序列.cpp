#include <string>
#include <stack>
#include <functional>
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
#include <sstream>
using namespace std;
class Solution
{
public:
    bool verifyPostorder(vector<int> &postorder)
    {
        return helper(postorder, 0, postorder.size() - 1);
    }
    bool helper(vector<int> &postorder, int left, int right)
    {
        if (left >= right)
            return true;
        int pos = left;                           // 用于寻找第一个大于根节点的位置
        while (postorder[pos] < postorder[right]) // 左子树区间
            pos++;
        int mid = pos;
        while (postorder[pos] > postorder[right]) // 右子树区间
            pos++;
        return pos == right && helper(postorder, left, mid - 1) && helper(postorder, mid, right - 1);
    }
};
// TODO: 单调栈