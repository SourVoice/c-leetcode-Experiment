// 1247. �����ַ�ʹ���ַ�����ͬ
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
// ̰��, ��ѧ
class Solution
{
public:
    int minimumSwap(string s1, string s2)
    {
        int len = s1.size();
        int cntx = 0, cnty = 0;
        for (int i = 0; i < len; i++)
        {
            if (s1[i] == 'x' && s2[i] == 'y')
                cntx++;
            if (s1[i] == 'y' && s2[i] == 'x')
                cnty++;
        }
        if ((cntx + cnty) & 1) // ����ʱ���ܹ�ƥ��
            return -1;
        // x, y��Ϊ����ʱ, ���Լ�һ��ż��ƥ��(x - 1)/2 + (y - 1) / 2, ����Ĳ���Ϊxy, yx, �������ν���(+2����)
        return (cntx + 1) / 2 + (cnty + 1) / 2;
    }
};