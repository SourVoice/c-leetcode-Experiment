// 275. H Ö¸Êý II
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
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int l = 0, r = n;
        int mid;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (n - mid > citations[mid])
            {
                l = mid + 1;
            }
            else
                r = mid;
        }
        return n - l;
    }
};