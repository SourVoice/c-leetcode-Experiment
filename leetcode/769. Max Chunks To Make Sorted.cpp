// 769. 最多能完成排序的块
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
// 贪心
class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int n = arr.size();
        int m = 0, res = 0;
        for (int i = 0; i < n; i++)
        {
            m = max(m, arr[i]); // 在前i中找到最大的
            if (m == i)
                res++;
        }
        return res;
    }
};
