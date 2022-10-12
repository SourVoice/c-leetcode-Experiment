// 817. Á´±í×é¼þ
#include <vector>
#include <map>
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
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    int numComponents(ListNode *head, vector<int> &nums)
    {
        map<int, int> mp;
        for (auto &num : nums)
            mp[num]++;
        bool isContinuous = false;
        int cnt = 0;
        while (head)
        {
            if (mp.count(head->val))
                mp[head->val]--, isContinuous = true;
            else
                isContinuous ? isContinuous = 0, cnt++ : isContinuous = 0;
            head = head->next;
        }
        if (isContinuous)
            cnt++;
        return cnt;
    }
};