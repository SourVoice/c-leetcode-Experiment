// 236. �������������������
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
#define N 1000
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
// �ݹ�
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        if (root == nullptr || root == p || root == q) // ���������еĲ��ҽ��
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);   // ���������в���p, q
        TreeNode *right = lowestCommonAncestor(root->right, p, q); // ���������в���p, q
        if (left && right)                                         // p, qλ�ڲ�ͬ����
            return root;
        else if (!right)
            return left;
        else if (!left)
            return right;
        return nullptr;
    }
};