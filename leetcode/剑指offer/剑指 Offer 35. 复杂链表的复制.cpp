#include <string>
#include <stack>
#include <functional>
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
#include <limits.h>
#include <stdbool.h>
#include <math.h>
using namespace std;
/*
// Definition for a Node.
*/
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// 哈希
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> mp;
        Node *headNode = head;
        while (headNode)
        {
            Node *node = new Node(headNode->val);
            mp[headNode] = node;
            headNode = headNode->next;
        }
        for (Node *node = head; node != nullptr; node = node->next)
        {
            mp[node]->next = mp[node->next];
            mp[node]->random = mp[node->random];
        }
        return mp[head];
    }
};
// 分离链表
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // 将拷贝节点放到原节点后面，例如1->2->3这样的链表就变成了这样1->1'->2->2'->3->3'
        for (Node *node = head; node != nullptr; node = node->next->next)
        {
            Node *copy = new Node(node->val);
            copy->next = node->next;
            node->next = copy;
        }
        // 把拷贝节点的random指针安排上
        for (Node *node = head; node != nullptr; node = node->next->next)
        {
            if (node->random)
            {
                node->next->random = node->random->next;
            }
        }
        // 分离拷贝节点和原节点，变成1->2->3和1'->2'->3'两个链表，后者就是答案
        if (!head)
            return head;
        Node *newHead = head->next;
        Node *temp = nullptr;
        for (Node *node = head; node != nullptr && node->next != nullptr;)
        {
            temp = node->next;
            node->next = temp->next;
            node = temp;
        }

        return newHead;
    }
};