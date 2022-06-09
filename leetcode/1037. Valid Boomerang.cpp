// 1037. 有效的回旋镖
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isBoomerang(vector<vector<int>> &points)
    {

        double len1 = sqrt(pow(points[0][0] - points[1][0], 2) + pow(points[0][1] - points[1][1], 2));
        double len2 = sqrt(pow(points[0][0] - points[2][0], 2) + pow(points[0][1] - points[2][1], 2));
        double len3 = sqrt(pow(points[1][0] - points[2][0], 2) + pow(points[1][1] - points[2][1], 2));
        if (len1 + len2 > len3 && len1 + len3 > len2 && len2 + len3 > len1)
            if (points[0][0] / points[0][1] != points[1][0] / points[1][1] && points[2][0] / points[2][1] != points[1][0] / points[1][1])
                return true;
        return false;
    }
};

//叉乘
class Solution
{
public:
    bool isBoomerang(vector<vector<int>> &points)
    {
        vector<int> v1 = {points[1][0] - points[0][0], points[1][1] - points[0][1]};
        vector<int> v2 = {points[2][0] - points[0][0], points[2][1] - points[0][1]};
        return v1[0] * v2[1] - v1[1] * v2[0] != 0;
    }
};
