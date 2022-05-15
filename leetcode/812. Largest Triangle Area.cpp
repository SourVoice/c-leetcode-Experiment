// 812. 最大三角形面积
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//模拟
class Solution
{
public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        vector<double> length;
        int n = points.size();
        double area = 0;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    double l1 = sqrt(pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2)); // (x1-x2)^2+(y1-y2)^2
                    double l2 = sqrt(pow(points[i][0] - points[k][0], 2) + pow(points[i][1] - points[k][1], 2)); // (x1-x3)^2+(y1-y3)^2
                    double l3 = sqrt(pow(points[j][0] - points[k][0], 2) + pow(points[j][1] - points[k][1], 2)); // (x2-x3)^2+(y2-y3)^2
                    area = max(area, heronFormula(l1, l2, l3));
                }
            }
        }
        return area;
    }
    double heronFormula(double a, double b, double c)
    {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

//向量
class Solution
{
public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        int n = points.size();
        double area = 0;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    area = max(area, determinant(points[i], points[j], points[k]));
                }
            }
        }
        return area;
    }
    double determinant(vector<int> p1, vector<int> p2, vector<int> p3)
    {
        return 0.5 * abs(p1[0] * p2[1] + p2[0] * p3[1] + p3[0] * p1[1] - p1[0] * p3[1] - p2[0] * p1[1] - p3[0] * p2[1]); // 1/2 * abs( x1*y2 + x2*y3 + x3*y1 - x1*y3 - x2*y1 - x3*y2 )
    }
};