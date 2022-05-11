// 449. 序列化和反序列化二叉搜索树
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <limits>
#include <stack>
#include <queue>
#include <string>
#include <vector>
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

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        stack<TreeNode *> sk;
        string ans;
        while (root || !sk.empty())
        {
            while (root)
            {
                ans += to_string(root->val);
                ans += ',';
                sk.push(root);
                root = root->left;
            }
            root = sk.top();
            sk.pop();
            root = root->right;
        }
        return ans.substr(0, ans.size() - 1);
    }
    void prefixOrder(TreeNode *root, vector<int> &arr)
    {
        if (!root)
            return;
        arr.push_back(root->val);
        prefixOrder(root->left, arr);
        prefixOrder(root->right, arr);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data == "")
            return nullptr;
        string delimiter = ",";
        vector<int> preOrder;
        size_t pos = 0;
        string s = data;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos)
        {
            token = s.substr(0, pos);
            preOrder.push_back(stoi(token));
            s.erase(0, pos + delimiter.length());
        }
        preOrder.push_back(stoi(s));
        vector<int> inOrder = preOrder;
        sort(inOrder.begin(), inOrder.end());
        int n = inOrder.size();
        for (int i = 0; i < n; i++)
        {
            index[inOrder[i]] = i;
        }
        return buildFromPre_In(preOrder, inOrder, 0, n - 1, 0, n - 1);
    }
    TreeNode *buildFromPre_In(const vector<int> &preorder, vector<int> &inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right)
    {
        if (preorder_left > preorder_right)
        {
            return nullptr;
        }

        // 前序遍历中的第一个节点就是根节点
        int preorder_root = preorder_left;
        // 在中序遍历中定位根节点
        int inorder_root = index[preorder[preorder_root]];

        // 先把根节点建立出来
        TreeNode *root = new TreeNode(preorder[preorder_root]);
        // 得到左子树中的节点数目
        int size_left_subtree = inorder_root - inorder_left;
        // 递归地构造左子树，并连接到根节点
        // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        root->left = buildFromPre_In(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
        // 递归地构造右子树，并连接到根节点
        // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
        root->right = buildFromPre_In(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
        return root;
    }

private:
    unordered_map<int, int> index;
};