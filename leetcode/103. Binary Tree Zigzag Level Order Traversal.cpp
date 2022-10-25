// 103. ¶þ²æÊ÷µÄ¾â³ÝÐÎ²ãÐò±éÀú
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
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        deque<TreeNode *> dq;
        vector<vector<int>> ans;
        dq.push_back(root);
        int level = 1;
        while (!dq.empty())
        {
            int n = dq.size();
            vector<int> levelarr;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = dq.front();
                levelarr.push_back(node->val);
                dq.pop_front();
                if (node->left)
                    dq.push_back(node->left);
                if (node->right)
                    dq.push_back(node->right);
            }
            if (!(level & 1))
                reverse(levelarr.begin(), levelarr.end());
            ans.push_back(levelarr);
            level++;
        }
        return ans;
    }
};