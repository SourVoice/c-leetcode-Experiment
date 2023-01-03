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
// ��ϣ
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
// ��������
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // �������ڵ�ŵ�ԭ�ڵ���棬����1->2->3����������ͱ��������1->1'->2->2'->3->3'
        for (Node *node = head; node != nullptr; node = node->next->next)
        {
            Node *copy = new Node(node->val);
            copy->next = node->next;
            node->next = copy;
        }
        // �ѿ����ڵ��randomָ�밲����
        for (Node *node = head; node != nullptr; node = node->next->next)
        {
            if (node->random)
            {
                node->next->random = node->random->next;
            }
        }
        // ���뿽���ڵ��ԭ�ڵ㣬���1->2->3��1'->2'->3'�����������߾��Ǵ�
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