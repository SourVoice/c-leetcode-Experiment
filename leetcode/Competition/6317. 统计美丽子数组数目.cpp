#include <string>
#include <stack>
#include <functional>
#include <deque>
#include <vector>
#include <map>
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
// ͳ��������������Ŀ
class Solution
{
public:
    long long beautifulSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefix(n, 0); // xor prefix
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] ^ nums[i];
        long long ret = 0;
        unordered_map<int, int> mp; // ��ǰ׺�����ж��ٶ���ͬ������
        for (auto &s : prefix)
        {
            ret += mp[s];
            mp[s]++;
        }
        return ret;
    }
};