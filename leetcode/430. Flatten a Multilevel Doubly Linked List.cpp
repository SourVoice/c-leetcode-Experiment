// 430. 扁平化多级双向链表
#include <bits/stdc++.h>
using namespace std;
/*
// Definition for a Node.
*/
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};
// 递归; 链表
class Solution
{
public:
    Node *flatten(Node *head)
    {
        helper(head);
        return head;
    }
    Node *helper(Node *head)
    {
        Node *last = head;
        while (head != nullptr)
        {
            Node *nxt = head->next;
            if (head->child != nullptr)
            {
                Node *lastChild = helper(head->child);
                head->next = head->child;
                head->child->prev = head;
                head->child = nullptr;
                if (nxt != nullptr)
                {
                    lastChild->next = nxt;
                    nxt->prev = lastChild;
                }
                last = lastChild;
            }
            else
            {
                last = head;
            }
            head = nxt;
        }
        return last;
    }
};