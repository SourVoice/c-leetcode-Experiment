
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ret;
        while (!q.empty())
        {
            int levelnum = q.size();
            vector<int> level;
            for (int i = 0; i < levelnum; i++)
            {
                TreeNode *node = q.front();
                level.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);

                q.pop();
            }
            ret.push_back(level);
        }
        return ret;
    }
};