// 2596. �����ʿѲ�ӷ���
#include <string>
#include <stack>
#include <functional>
#include <deque>
#include <vector>
#include <map>
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
#include <sstream>
using namespace std;
// ģ��
class Solution
{
public:
    bool checkValidGrid(vector<vector<int>> &grid)
    {
        if (grid[0][0] != 0)
            return false;

        typedef tuple<int, int, int> tiii;
        int len = grid.size();
        int n = len;
        vector<tiii> vec;
        // ��¼�����������߹���˳��, ��ÿ����Ӧ��i, jλ��
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                vec.push_back(make_tuple(grid[i][j], i, j));

        sort(begin(vec), end(vec));
        for (int idx = 1; idx < n * n; idx++)
        {
            auto &prev_e = vec[idx - 1];
            auto &cur_e = vec[idx];
            int di = get<1>(prev_e) - get<1>(cur_e);
            int dj = get<2>(prev_e) - get<2>(cur_e);
            if ((abs(di) == 2 && abs(dj) == 1) || // idx ���ܴ�idx - 1���ƶ�����
                (abs(di) == 1 && abs(dj) == 2))
                continue;
            return false;
        }
        return true;
    }
};