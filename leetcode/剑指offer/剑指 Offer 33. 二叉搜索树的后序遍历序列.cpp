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
        int pos = left;                           // ����Ѱ�ҵ�һ�����ڸ��ڵ��λ��
        while (postorder[pos] < postorder[right]) // ����������
            pos++;
        int mid = pos;
        while (postorder[pos] > postorder[right]) // ����������
            pos++;
        return pos == right && helper(postorder, left, mid - 1) && helper(postorder, mid, right - 1);
    }
};
// TODO: ����ջ