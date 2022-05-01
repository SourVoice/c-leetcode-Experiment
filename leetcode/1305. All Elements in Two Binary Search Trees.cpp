// 1305. 两棵二叉搜索树中的所有元素
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
/*
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
    void helper(TreeNode *root, vector<int> &store)
    {
        if (!root)
            return;
        helper(root->left, store);
        store.push_back(root->val);
        helper(root->right, store);
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        helper(root1, BST1);
        helper(root2, BST2);
        // MERGE
        std::vector<int> dst;
        std::merge(BST1.begin(), BST1.end(), BST2.begin(), BST2.end(), std::back_inserter(dst));
        return dst;
    }

private:
    vector<int> BST1;
    vector<int> BST2;
};

// merger by hand
class Solution2
{
public:
    void helper(TreeNode *root, vector<int> &store)
    {
        if (!root)
            return;
        helper(root->left, store);
        store.push_back(root->val);
        helper(root->right, store);
    }

    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        helper(root1, BST1);
        helper(root2, BST2);
        return Merge(BST1, BST2);
    }
    vector<int> Merge(vector<int> &v1, vector<int> &v2)
    {
        int len1 = v1.size(), len2 = v2.size(), i = 0, j = 0;
        vector<int> res;
        while (i < len1 && j < len2)
        {
            if (v1[i] <= v2[j])
                res.push_back(v1[i++]);
            else
                res.push_back(v2[j++]);
        }
        while (i < len1)
        {
            res.push_back(v1[i++]);
        }
        while (j < len2)
        {
            res.push_back(v2[j++]);
        }
        return res;
    }

private:
    vector<int> BST1;
    vector<int> BST2;
};