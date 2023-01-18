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
    int maxDepth(TreeNode *root)
    {
        helper(root, 0);
        return ret;
    }
    void helper(TreeNode *root, int depth)
    {
        if (!root)
        {
            ret = max(depth, ret);
            return;
        }
        helper(root->left, depth + 1);
        helper(root->right, depth + 1);
    }

private:
    int ret = 0;
};