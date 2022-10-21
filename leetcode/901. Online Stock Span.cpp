// 901. 股票价格跨度
#include <string>
#include <stack>
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
// 单调栈
class StockSpanner
{
public:
    StockSpanner()
    {
        sk.push(0);
        arr.push_back(INT_MAX);
    }

    int next(int price)
    {
        arr.push_back(price);
        while (price >= arr[sk.top()])
            sk.pop();
        int ret = arr.size() - sk.top() - 1; // 当前存入了的天数减去第一个大于price处的天数
        sk.push(arr.size() - 1);
        return ret;
    }

private:
    stack<int> sk; // sk保存下标, 即天数
    vector<int> arr;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */