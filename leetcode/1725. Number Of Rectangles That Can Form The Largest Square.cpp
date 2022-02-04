// 1725. 可以形成最大正方形的矩形数目

#include <vector>
#include <algorithm>
using namespace std;

//常规法
class Solution
{
public:
    int countGoodRectangles(vector<vector<int>> &rectangles)
    {
        int maxLen = 0;
        vector<int> minSide(rectangles.size(), 0);
        for (auto &rect : rectangles)
        {
            minSide.push_back(min(rect[0], rect[1]));
        }
        sort(minSide.begin(), minSide.end(), [&](int a, int b)
             { return a < b; });
        int maxLength = *minSide.rbegin();
        int ans = 0;
        for (auto i = minSide.rbegin();; i++)
        {
            ans++;
            if (*i != maxLength)
            {
                return ans;
            }
        }
        return 0;
    }
};

class Solution2
{
public:
    int countGoodRectangles(vector<vector<int>> &rectangles)
    {
        int ans = 0;
        int maxlength = 0;
        for (auto &rect : rectangles)
        {
            int len = min(rect[0], rect[1]);
            if (len == maxlength)
            {
                ans++;
            }
            else if (len > maxlength)
            {
                maxlength = len;
                ans = 1;
            }
        }
        return ans;
    }
};
