// 105. ��ǰ��������������й��������
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
// ���εݹ�;������
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
        while (inorder[mid] != preorder[prel]) //��inorder�в���rootλ��
            mid++;
        root->left = helper(preorder, prel + 1, prer - inr + mid, inorder, inl, mid - 1);  // ǰ����Ҷ˵�=ǰ���Ҷ˵��ȥ �������Ľڵ���(inr - mid) = prer - ( inr - mid)
        root->right = helper(preorder, prel + mid - inl + 1, prer, inorder, mid + 1, inr); // ͬ��
        return root;
    }
};