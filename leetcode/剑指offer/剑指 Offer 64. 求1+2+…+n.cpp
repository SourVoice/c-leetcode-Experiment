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
    int sumNums(int n)
    {
        if (n == 1)
            return 1;
        return n + sumNums(n - 1);
    }
};
// ��ʹ��if���:
class Solution
{
public:
    int sumNums(int n)
    {
        n != 1 && (n += sumNums(n - 1));
        return n;
    }
};
// ���ñ�����
class Solution
{
public:
    int sumNums(int n)
    {
        bool arr[n][n + 1]; // boolռ��һ���ֽ�
        return sizeof(arr) >> 1;
    }
};
