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
/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return getDepth(root) != -1;
    }
    int getDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        if (leftDepth >= 0 && rightDepth >= 0 && abs(rightDepth - leftDepth) <= 1)
            return max(leftDepth, rightDepth) + 1;
        else
            return -1;
    }
};