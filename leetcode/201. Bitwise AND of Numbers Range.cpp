// 201. ���ַ�Χ��λ��
#include <string>
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
// λ����
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int offset = 0;
        while (left != right) // �ҵ������乲ͬǰ׺, ��������ȫ����0����
        {
            left >>= 1;
            right >>= 1;
            offset++;
        }
        return left << offset;
    }
};