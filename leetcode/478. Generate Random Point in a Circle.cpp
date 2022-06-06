// 478. 在圆内随机生成点
#include <random>
#include <vector>
using namespace std;

// 拒绝采样;rand for double
class Solution
{
public:
    Solution(double radius, double x_center, double y_center) : _radius(radius), _x_c(x_center), _y_c(y_center) {}

    double fRand(double fMin, double fMax)
    {
        double f = (double)rand() / RAND_MAX;
        return fMin + f * (fMax - fMin);
    }

    vector<double> randPoint()
    {
        double x = fRand(_x_c - _radius, _x_c + _radius);
        double y = fRand(_y_c - _radius, _y_c + _radius);
        if (pow(x - _x_c, 2) + pow(y - _y_c, 2) > _radius * _radius)
            return randPoint();
        return {x, y};
    }

private:
    double _radius, _x_c, _y_c;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */