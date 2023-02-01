#include <string>
#include <stack>
#include <functional>
#include <deque>
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
#include <queue>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <sstream>
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
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "#_";
        string s = to_string(root->val) + "_";
        s += serialize(root->left);
        s += serialize(root->right);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        queue<string> q;
        stringstream ss(data);
        char delim = '_';
        string str;
        while (getline(ss, str, delim))
            q.push(str);
        return helper(q);
    }
    TreeNode *helper(queue<string> &q)
    {
        auto s = q.front();
        q.pop();
        if (s == "#")
            return nullptr;
        TreeNode *node = new TreeNode(atoi(s.c_str()));
        node->left = helper(q);
        node->right = helper(q);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));