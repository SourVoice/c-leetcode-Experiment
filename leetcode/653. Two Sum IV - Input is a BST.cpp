// 653. 两数之和 IV - 输入 BST
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
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
// store into hashmap
class Solution
{
public:
    void preOrder(TreeNode *root, unordered_map<int, int> &m)
    {
        if (!root)
        {
            return;
        }
        m[root->val]++;
        preOrder(root->left, m);
        preOrder(root->right, m);
    }
    bool findTarget(TreeNode *root, int k)
    {
        unordered_map<int, int> mp;
        preOrder(root, mp);
        for (auto &p : mp)
        {
            cout << p.first << " ";
        }
        cout << endl;
        for (auto &elem : mp)
        {
            if (mp.find(k - elem.first) != mp.end() && (k - elem.first) != elem.first)
            {
                return true;
            }
        }
        return false;
    }
};
// 二分查找
class Solution
{
public:
    vector<int> vec;

    //中序遍历搜索是递增
    void inorderTraversal(TreeNode *node)
    {
        if (node == nullptr)
            return;
        inorderTraversal(node->left);
        vec.push_back(node->val);
        inorderTraversal(node->right);
    }

    bool findTarget(TreeNode *root, int k)
    {

        inorderTraversal(root);
        int left = 0, right = vec.size() - 1;
        while (left < right)
        {
            if (vec[left] + vec[right] == k)
                return true;
            if (vec[left] + vec[right] < k)
                left++;
            else
                right--;
        }
        return false;
    }
};
// 哈希表, 简洁
class Solution
{
public:
    set<int> st;
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;
        if (st.count(k - root->val))
            return true;
        st.emplace(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
