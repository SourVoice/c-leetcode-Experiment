// 1346. ������������������Ƿ����
#include <stack>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <set>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        set<int> st;
        int num_0 = 0;
        for (auto &e : arr)
        {
            if (e == 0)
                num_0++;
            st.emplace(e);
        }
        if (num_0 >= 2)
            return true;
        for (auto &e : arr)
        {
            cout << e << " " << e * 2 << endl;
            if (st.find(e * 2) != st.end() && e)
                return true;
        }
        return false;
    }
};
// ��ϣ��;�����
class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        set<int> st;
        for (auto &e : arr)
        {
            if (st.find(2 * e) != st.end() || (st.find(e / 2) != st.end() && !(e & 1)))
                return true;
            st.emplace(e); //��ֹ���0���ֵ������Ҫ�����Ԫ��
        }
        return false;
    }
};