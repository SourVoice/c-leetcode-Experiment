// 1300. ת���������ӽ�Ŀ��ֵ�������
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
// ���ֲ���
// ./658. Find K Closest Elements
class Solution
{
public:
    int findBestValue(vector<int> &arr, int target)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            prefix[i] = arr[i - 1] + prefix[i - 1];
        int l = 0, r = target;
        auto diff = [&](const int &value) -> int
        {
            auto it = upper_bound(arr.begin(), arr.end(), value);
            int i = it - begin(arr);
            int sum = prefix[i] + value * (n - i);
            return abs(sum - target);
        };
        while (l < r)
        {
            int mid = (l + r) / 2;
            // refer 658. �ҵ� K ����ӽ���Ԫ��
            // k = 1;
            if (diff(mid) <= diff(mid + 1))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};