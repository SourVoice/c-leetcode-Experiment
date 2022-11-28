// 149. 直线上最多的点数
#include <string>
#include <functional>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
using namespace std;
class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        unordered_map<int, int> mp;
        function<int(int, int)> gcd = [&](int a, int b) -> int
        {
            return b ? gcd(b, a % b) : a;
        };
        for (int i = 0; i < points.size() - 1; i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                for (int k = j; k < points.size(); k++)
                {
                }
                int dxy = gcd(abs(dx), abs(dy));
            }
        }
        int ans = INT_MIN;
        for (auto &[_, val] : mp)
        {
            cout << _ << endl;
            ans = max(ans, val + 1);
        }
        return ans;
    }
};
// 需要排处平行和重叠
class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int ans = INT_MIN;
        if (points.size() < 2)
            return 1;
        function<int(int, int)> gcd = [&](int a, int b) -> int
        {
            return b ? gcd(b, a % b) : a;
        };
        for (int i = 0; i < points.size() - 1; i++)
        {
            unordered_map<string, int> mp; // 统计穿过i的直线
            int maxCnt = 0;
            for (int j = i + 1; j < points.size(); j++)
            {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int dxy = gcd(dx, dy);
                string slope = to_string(dy / dxy) + "_" + to_string(dx / dxy);
                mp[slope]++;
                maxCnt = max(maxCnt, mp[slope]);
            }
            ans = max(ans, maxCnt + 1);
        }
        return ans;
    }
};