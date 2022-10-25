// 199. 二叉树的右视图
#include <string>
#include <stack>
#include <bitset>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
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
// 层序遍历仅保留右侧结点值
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return {};
        deque<TreeNode *> dq;
        vector<int> ans;
        dq.push_back(root);
        while (!dq.empty())
        {
            int n = dq.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = dq.front();
                if (i == n - 1)
                    ans.push_back(node->val);
                dq.pop_front();
                if (node->left)
                    dq.push_back(node->left);
                if (node->right)
                    dq.push_back(node->right);
            }
        }
        return ans;
    }
};