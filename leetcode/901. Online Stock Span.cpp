// 901. ��Ʊ�۸���
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
// ����ջ
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
        int ret = arr.size() - sk.top() - 1; // ��ǰ�����˵�������ȥ��һ������price��������
        sk.push(arr.size() - 1);
        return ret;
    }

private:
    stack<int> sk; // sk�����±�, ������
    vector<int> arr;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */