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
// ��ѧ, ѭ������
// �����Ӿ����ֳܷ�����
class Solution
{
public:
    int cuttingRope(int n)
    {
        if (n <= 3)
            return n - 1;
        long ret = 1;
        long mod = 1e9 + 7;
        while (n > 4)
        {
            ret *= 3;
            ret %= mod;
            n -= 3;
        }
        // ʣ���Ϊ��Ϊ1 , 2, 3, 4
        return (ret * n) % mod;
    }
};