#include <vector>
#include <stack>
using namespace std;
class Node
{
public:
    int val;
    std::vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, std::vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
// Definition for a Node.
/*
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    std::vector<int> postorder(Node *root)
    {
        if (!root)
            return {};
        std::stack<std::pair<Node *, int>> stack;
        std::vector<int> ans;
        stack.emplace(root, 0);
        while (!stack.empty())
        {
            auto &[node, index] = stack.top();
            if (index == node->children.size())
            {
                ans.push_back(node->val);
                stack.pop();
            }
            else
            {
                stack.emplace(node->children[index++], 0);
            }
        }
        return ans;
    }
};