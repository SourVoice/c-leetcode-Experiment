// 116. 填充每个节点的下一个右侧节点指针
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
            {
                root->left->next = root->right;
                if (root->next)
                    root->right->next = root->next->left;
            }
            connect(root->left);
            connect(root->right);
        }
        return root;
    }
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
                Node *cur = dq.front();
                dq.pop_front();
                if (i < n - 1)
                    cur->next = dq.front();
                if (cur->left)
                    dq.push_back(cur->left);
                if (cur->right)
                    dq.push_back(cur->right);
            }
        }
        return root;
    }
};
