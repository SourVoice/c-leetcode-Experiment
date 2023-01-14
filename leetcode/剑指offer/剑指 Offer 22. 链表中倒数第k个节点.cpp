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
/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        ListNode *fast = head;
        int i = 0;
        while (i < k)
        {
            i++;
            fast = fast->next;
        }
        ListNode *slow = head;
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};