// 769. ������������Ŀ�
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
// ̰��
class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int n = arr.size();
        int m = 0, res = 0;
        for (int i = 0; i < n; i++)
        {
            m = max(m, arr[i]); // ��ǰi���ҵ�����
            if (m == i)
                res++;
        }
        return res;
    }
};
