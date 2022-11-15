// 117. ���ÿ���ڵ����һ���Ҳ�ڵ�ָ�� II
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
// �������
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
// �ݹ�
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
        connect(root->right); // Ҫ�ȵݹ��Ҳ�, ��ֹ���ڵ��޷����ӵ��Ҳ�
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
