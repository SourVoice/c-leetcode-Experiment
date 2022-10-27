// 173. ����������������
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
// ʹ�����������
class BSTIterator
{
public:
    BSTIterator(TreeNode *root)
    {
        stack<TreeNode *> sk;
        while (!sk.empty() || root)
        {
            while (root)
            {
                sk.push(root);
                root = root->left;
            }
            root = sk.top();
            arr.push_back(root->val);
            sk.pop();
            root = root->right;
        }
        it = arr.begin();
    }

    int next()
    {
        return *(it++);
    }

    bool hasNext()
    {
        return it != arr.end();
    }

private:
    vector<int>::iterator it;
    vector<int> arr;
};
// ʵ��O(h)�ռ� hΪ���߶�
// ����������Ľ�
// ÿ�ε�������������
class BSTIterator
{
public:
    BSTIterator(TreeNode *root)
    {
        while (root)
        {
            leftChain.push_back(root);
            root = root->left;
        }
    }

    int next()
    {
        TreeNode *root = leftChain.back();
        leftChain.pop_back();
        int ret = root->val;
        root = root->right;
        while (root)
        {
            leftChain.push_back(root);
            root = root->left;
        }
        return ret;
    }

    bool hasNext()
    {
        return !leftChain.empty();
    }

private:
    vector<TreeNode *> leftChain;
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */