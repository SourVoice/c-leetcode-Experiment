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
class Solution
{
public:
    typedef long long ll;
    int minimizeArrayValue(vector<int> &nums)
    {
        int l = 0, r = fmax(*max_element(begin(nums), end(nums)), 1e9);
        int n = nums.size();
        auto check = [&](vector<ll> vec, const int &a) -> bool // ÿһ�ζ��ֲ����в��ܹ��ı�ԭ����
        {
            // �������
            // ̰�ĵ�ʹÿ��Ԫ�ض����a��С, ÿ��ǰ���Ԫ�ر��, �õ�nums[0]Ϊ��С�����Ԫ��
            for (int i = n - 1; i > 0; i--)
            {
                if (vec[i] > a)
                {
                    ll diff = vec[i] - a;
                    vec[i] = a;
                    vec[i - 1] += diff;
                }
            }
            return vec[0] > a;
        };

        while (l < r)
        {
            int mid = ((r - l) >> 1) + l;
            vector<ll> vec(nums.begin(), nums.end());
            if (check(vec, mid)) // nums[0] > mid
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};
