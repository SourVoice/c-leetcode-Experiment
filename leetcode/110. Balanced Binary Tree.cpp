// 110. Æ½ºâ¶þ²æÊ÷
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
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// µÝ¹é
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
        int leftD = getDepth(root->left);
        int rightD = getDepth(root->right);
        if (leftD >= 0 && rightD >= 0 && abs(leftD - rightD) <= 1)
            return max(leftD, rightD) + 1;
        else
            return -1;
    }
};