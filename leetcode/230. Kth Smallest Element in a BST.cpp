// 230. �����������е�KС��Ԫ��
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
// ʹ�����������¼
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        helper(root);
        return rec[k - 1];
    }
    void helper(TreeNode *root)
    {
        if (!root)
            return;
        helper(root->left);
        rec.push_back(root->val);
        helper(root->right);
    }

private:
    vector<int> rec;
};
// ����BST����, �Ż�
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        return 0;
    }
};
// ����
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> sk;
        int cnt = 0;
        while (!sk.empty() || root)
        {
            if (root)
            {
                sk.push(root);
                root = root->left;
            }
            else
            {
                root = sk.top();
                sk.pop();
                cnt++;
                if (cnt == k)
                    return root->val;
                root = root->right;
            }
        }
        return 0;
    }
};