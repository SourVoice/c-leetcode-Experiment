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

// 极坐标
class Solution
{
public:
    Solution(double radius, double x_center, double y_center) : _radius(radius), _x_c(x_center), _y_c(y_center) {}

    double randf(double min = 0, double max = 1)
    {
        double g = (double)rand() / RAND_MAX;
        return min + g * (max - min);
    }
    vector<double> randPoint()
    {
        double theta = randf() * 2 * PI;
        double r = sqrt(randf()) * _radius; //该处涉及到概率论的推到,见:https://leetcode.cn/problems/generate-random-point-in-a-circle/solution/lian-ye-fan-chu-gai-lu-lun-ppt-by-liuyvj-ec7s/
        return {_x_c + r * cos(theta), _y_c + r * sin(theta)};
    }

private:
    double _radius, _x_c, _y_c;
    const double PI = 3.14159265358979323846;
};

//梅森旋转算法+拒绝采样
class Solution
{
public:
    Solution(double radius, double x_center, double y_center) : _radius(radius), _x_c(x_center), _y_c(y_center) {}

    vector<double> randPoint()
    {
        while (true)
        {
            double x = distrib(gen), y = distrib(gen);
            if (x * x + y * y <= _radius * _radius)
                return {_x_c + x, _y_c + y};
        }
    }

private:
    double _radius, _x_c, _y_c;
    const double PI = 3.14159265358979323846;

    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen{rd()}; // Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<double> distrib{0, 1};
};

//梅森旋转算法+极坐标
class Solution
{
public:
    Solution(double radius, double x_center, double y_center) : _radius(radius), _x_c(x_center), _y_c(y_center) {}

    vector<double> randPoint()
    {
        double theta = distrib(gen) * 2 * PI, r = sqrt(distrib(gen)) * _radius;
        return {_x_c + r * cos(theta), _y_c + r * sin(theta)};
    }

private:
    double _radius, _x_c, _y_c;
    const double PI = 3.14159265358979323846;

    std::mt19937 gen{std::random_device{}()};
    std::uniform_real_distribution<double> distrib{0, 1};
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */