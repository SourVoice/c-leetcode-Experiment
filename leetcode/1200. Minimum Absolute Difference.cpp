// 1200. 最小绝对差
#include <vector>
#include <algorithm>
using namespace std;
// 模拟
class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int min = INT_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            min = fmin(min, arr[i + 1] - arr[i]);
        }
        vector<vector<int>> ret;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i + 1] - arr[i] == min)
                ret.push_back({arr[i], arr[i + 1]});
        }
        return ret;
    }
};