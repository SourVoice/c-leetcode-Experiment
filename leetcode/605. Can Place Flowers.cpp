// 605. 种花问题
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <list>
using namespace std;
// 面向测试用例
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int len = flowerbed.size();
        if (len == 1)
            if (flowerbed[0] == 1 && n == 1)
                return false;
            else
                return true;
        if (flowerbed[0] == 0 && flowerbed[1] == 0)
            n--, flowerbed[0] = 1;
        for (int i = 1; i < len - 1; i++)
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0)
                n--, flowerbed[i] = 1;
        if (flowerbed[len - 1] == 0 && flowerbed[len - 2] == 0)
            n--, flowerbed[len - 1] = 1;
        return n <= 0;
    }
};
// 防御性编程:
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.insert(flowerbed.end(), 0);
        int len = flowerbed.size();
        for (int i = 1; i < len - 1; i++)
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0)
                n--, flowerbed[i] = 1;
        return n <= 0;
    }
};
