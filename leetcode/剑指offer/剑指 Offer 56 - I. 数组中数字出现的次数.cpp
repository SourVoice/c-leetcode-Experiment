#include <string>
#include <stack>
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
#include <sstream>
using namespace std;
class Solution
{
public:
    vector<int> singleNumbers(vector<int> &nums)
    {
        int xorsum = 0;
        for (auto &&num : nums)
            xorsum ^= num;
        int index = 0;
        while ((xorsum & 1) == 0) // Ѱ�ҵ�һ���������е�1, == ���ȼ����� &
        {
            index++;
            xorsum >>= 1;
        }
        int res = res & (-res); // �õ����λ��1��Ӧ���� lowbit
        int ret1 = 0, ret2 = 0;
        for (auto &&num : nums)
        {
            if ((num >> index) & 1)
                ret1 ^= num;
            else
                ret2 ^= num;
        }
        return vector<int>{ret1, ret2};
    }
};