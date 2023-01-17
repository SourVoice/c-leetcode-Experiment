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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int target)
    {
        vector<int> path;
        helper(root, path, target, 0);
        return ret;
    }
    void helper(TreeNode *root, vector<int> &path, int target, int sum)
    {
        if (!root)
            return;
        path.push_back(root->val);
        if (!root->left && !root->right && (sum + root->val) == target)
            ret.push_back(path);
        sum += root->val;
        helper(root->left, path, target, sum);
        helper(root->right, path, target, sum);
        path.pop_back();
    }

private:
    vector<vector<int>> ret;
};