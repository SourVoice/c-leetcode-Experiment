// 779. 第K个语法符号
#include <string>
#include <bitset>
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
// 递归
class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        if (n == 1)
            return 0;
        int parent = kthGrammar(n - 1, (k + 1) >> 1);
        return (k & 1) ? parent : !parent;
    }
};
// 朴素解法
/*
0
01
0110
01101001
0110100110010110
*/
class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        int cnt = 0;
        while (n > 1)
        {
            if (k > pow(2, n - 2))
            {
                int offset = pow(2, n - 1) - k;
                k = pow(2, n - 2) - offset; // k在上一级位置对应的位置
                cnt++;                      // 反转一次
            }
            n--;
        }
        return cnt & 1;
    }
};