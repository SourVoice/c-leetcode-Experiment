// 969. 煎饼排序

#include <vector>
#include <algorithm>
using namespace std;

//贪心,每次将最大的移至最前之后移至最后
class Solution
{
public:
    vector<int> pancakeSort(vector<int> &arr)
    {
        vector<int> ans;
        int n = arr.size();
        for (int i = n; i > 0; i--)
        {
            int idx = 0;
            for (int j = 0; j < i; j++)
            {
                if (arr[j] > arr[idx])
                {
                    idx = j;
                } // max before i
            }
            if (idx != i - 1)
            {
                ans.push_back(idx + 1);
                reverse(arr.begin(), arr.begin() + idx + 1);
                reverse(arr.begin(), arr.begin() + i);
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//优化
class Solution2
{
public:
    vector<int> pancakeSort(vector<int> arr)
    {
        int n = arr.size();
        vector<int> ans;
        for (int i = n - 1; i > 0; i--)
        {
            int j = max_element(arr.begin(), arr.begin() + i + 1) - arr.begin();
            if (j > 0)
            {
                reverse(arr.begin(), arr.begin() + j + 1);
                ans.push_back(j + 1);
            }
            reverse(arr.begin(), arr.begin() + i + 1);
            ans.push_back(i + 1);
        }
        return ans;
    }
};