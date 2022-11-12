// 986. 区间列表的交集
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
// 双指针
class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        int m = firstList.size(), n = secondList.size();
        int i = 0, j = 0;
        vector<vector<int>> ans;
        int rightLimit = 0;
        for (; i < m && j < n;)
        {
            int leftBorder = max(firstList[i][0], secondList[j][0]);
            int rightBorder = min(firstList[i][1], secondList[j][1]);
            if (leftBorder <= rightBorder)
                ans.push_back({leftBorder, rightBorder});
            if (firstList[i][1] < secondList[j][1])
                i++;
            else
                j++;
        }
        return ans;
    }
};