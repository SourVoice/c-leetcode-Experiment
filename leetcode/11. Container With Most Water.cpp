// 11. 盛最多水的容器
#include <vector>
using namespace std;

//双指针
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int i = 0, j = n - 1;
        int area = INT_MIN;
        while (i < j)
        {
            int hmin = fmin(height[i], height[j]);
            area = fmax(area, (j - i) * hmin);
            while (height[i] <= hmin && i < j)
            {
                i++;
            }
            while (height[j] <= hmin && i < j)
            {
                j--;
            }
        }
        return area;
    }
};