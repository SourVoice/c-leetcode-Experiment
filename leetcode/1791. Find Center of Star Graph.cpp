// 1791. 找出星型图的中心节点

//脑筋急转弯
class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        int a = edges[0][0], b = edges[0][1];
        if (edges[1][0] == a || edges[1][1] == a)
            return a;
        else
            return b;
    }
};