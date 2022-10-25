// 113. Â·¾¶×ÜºÍ II
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
// Ê÷, µÝ¹é
class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;
        helper(root, path, targetSum, 0);
        return ans;
    }
    void helper(TreeNode *root, vector<int> &path, int targetSum, int pathsum)
    {
        if (!root)
            return;
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && pathsum + root->val == targetSum)
            ans.push_back(path);
        pathsum += root->val;
        helper(root->left, path, targetSum, pathsum);
        helper(root->right, path, targetSum, pathsum);
        path.pop_back();
    }

private:
    vector<vector<int>> ans;
};