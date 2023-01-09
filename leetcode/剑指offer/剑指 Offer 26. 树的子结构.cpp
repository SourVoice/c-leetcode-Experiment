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
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if (!A || !B)
            return false;
        return helper(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    bool helper(TreeNode *A, TreeNode *B) // 判断两个树是否相等
    {
        if (B && !A)
            return false;
        if (!B && !A)
            return true;
        if (!B && A)
            return true;
        return A->val == B->val && helper(A->left, B->left) && helper(A->right, B->right);
    }
};