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
    bool isSymmetric(TreeNode *root)
    {
        return helper(root, root);
    }
    bool helper(TreeNode *p, TreeNode *q)
    {
        if (!p && q)
            return false;
        if (p && !q)
            return false;
        if (!p && !q)
            return true;
        return p->val == q->val && helper(p->left, q->right) && helper(p->right, q->left);
    }
};