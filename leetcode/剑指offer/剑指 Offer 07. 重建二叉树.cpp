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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode *helper(vector<int> &preorder, int prel, int prer, vector<int> &inorder, int inl, int inr)
    {
        if (inl > inr)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[prel]);
        int mid = inl;
        while (inorder[mid] != preorder[prel]) // 在inorder中查找root位置
            mid++;
        root->left = helper(preorder, prel + 1, prer - inr + mid, inorder, inl, mid - 1);  // 前序的右端点=前序右端点减去 右子树的节点数(inr - mid) = prer - ( inr - mid)
        root->right = helper(preorder, prel + mid - inl + 1, prer, inorder, mid + 1, inr); // 同上
        return root;
    }
};