/*
// Definition for a Node.
*/
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};
class Solution
{
public:
    Node *treeToDoublyList(Node *root)
    {
        if (!root)
            return nullptr;
        helper(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
    void helper(Node *root)
    {
        if (!root)
            return;
        helper(root->left);
        if (!pre) //// pre为空，就说明是第一个节点，头结点，然后用head保存头结点，用于之后的返回
            head = root;
        if (pre)
            pre->right = root;
        root->left = pre;
        pre = root;
        helper(root->right);
    }

private:
    Node *pre, *head; // pre保存左中右中 的 "左"
};