// 297. 二叉树的序列化与反序列化
#include <string>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
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
// 前序遍历
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
        string token;
        while (std::getline(ss, token, delim))
            q.push(token);
        return helper(q);
    }
    TreeNode *helper(queue<string> &q)
    {
        string token = q.front();
        q.pop();
        if (token == "#")
            return nullptr;
        TreeNode *node = new TreeNode(stoi(token));
        node->left = helper(q);
        node->right = helper(q);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));