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
    int kthLargest(TreeNode *root, int k)
    {
        helper(root, k);
        return ret;
    }
    void helper(TreeNode *root, int k)
    {
        if (!root)
            return;
        helper(root->right, k);
        maxnumpos++;
        if (maxnumpos == k)
        {
            ret = root->val;
            return;
        }
        helper(root->left, k);
    }

private:
    int ret = 0;
    int maxnumpos = 0;
};