// 1539. �� k ��ȱʧ��������
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] - (i + 1) >= k) // x - (i + 1) Ϊarr[i]֮ǰȱʧ�˼�����
                return k + i;
        }
        return k + n;
    }
};