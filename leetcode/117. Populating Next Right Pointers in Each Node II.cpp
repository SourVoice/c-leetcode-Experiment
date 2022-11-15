// 117. 填充每个节点的下一个右侧节点指针 II
#include <string>
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
using namespace std;
/*
// Definition for a Node.
*/
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
// 层序遍历
class Solution
{
public:
    Node *connect(Node *root)
    {
        deque<Node *> dq;
        dq.push_back(root);
        while (!dq.empty() && root)
        {
            int n = dq.size();
            for (int i = 0; i < n; i++)
            {
                Node *node = dq.front();
                dq.pop_front();
                if (i < n - 1)
                    node->next = dq.front();
                if (node->left)
                    dq.push_back(node->left);
                if (node->right)
                    dq.push_back(node->right);
            }
        }
        return root;
    }
};
// 递归
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return nullptr;
        if (root->left)
        {
            if (root->right)
                root->left->next = root->right;
            else
                root->left->next = nextNode(root->next);
        }
        if (root->right)
            root->right->next = nextNode(root->next);
        connect(root->right); // 要先递归右侧, 防止左侧节点无法连接到右侧
        connect(root->left);
        return root;
    }

private:
    Node *nextNode(Node *cur)
    {
        while (!cur)
        {
            if (cur->left)
                return cur->left;
            else if (cur->right)
                return cur->right;
            cur = cur->next;
        }
        return nullptr;
    }
};
