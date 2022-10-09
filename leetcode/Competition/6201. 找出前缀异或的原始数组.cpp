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
    vector<int> findArray(vector<int> &pre)
    {
        vector<int> arr(pre.size(), 0);
        arr[0] = pre[0];
        for (int i = 1; i < pre.size(); i++)
            arr[i] = pre[i - 1] ^ pre[i];
        return arr;
    }
};
