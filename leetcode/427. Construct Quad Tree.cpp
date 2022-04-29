// 427. 建立四叉树
#include <vector>
using namespace std;

// Definition for a QuadTree node.
class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

// dfs
class Solution
{
public:
    Node *helper(vector<vector<int>> &part, int x, int y, int borderL)
    {
        bool findNotSame = false;
        int partNum = part[x][y];
        for (int i = x; i < x + borderL; i++)
        {
            for (int j = y; j < y + borderL; j++)
            {
                if (part[i][j] != part[x][y])
                {
                    findNotSame = true;
                    break;
                }
            }
        }
        if (findNotSame)
        {
            // 区域内值不同,使用二分进行分割
            Node *node = new Node(1, false);
            int newBorder = borderL / 2;
            node->topLeft = helper(part, x, y, newBorder);
            node->topRight = helper(part, x, y + newBorder, newBorder);
            node->bottomLeft = helper(part, x + newBorder, y, newBorder);
            node->bottomRight = helper(part, x + newBorder, y + newBorder, newBorder);
            return node;
        }
        else
        {
            Node *node = new Node(partNum, true);
            return node;
        }
        return NULL;
    }
    Node *construct(vector<vector<int>> &grid)
    {
        int x = 0, y = 0, borderL = grid.size();
        return helper(grid, x, y, borderL);
    }
};