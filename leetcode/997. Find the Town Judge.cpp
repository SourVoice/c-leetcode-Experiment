// 997. 找到小镇的法官
#include <string>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
// 图论建模
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<vector<int>> rec(n, vector(2, 0)); // 0, for 入度
        for (auto &person : trust)
        {
            rec[person[0] - 1][1]--;
            rec[person[1] - 1][0]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (rec[i][0] == n - 1 && rec[i][1] == 0)
                return i + 1;
        }
        return -1;
    }
};