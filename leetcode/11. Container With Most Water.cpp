// 11. ʢ���ˮ������
#include <vector>
using namespace std;

//˫ָ��
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