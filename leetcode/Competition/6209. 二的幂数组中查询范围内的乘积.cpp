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
// ×´Ì¬Ñ¹Ëõ½âÑ¹
class Solution
{
public:
    typedef long long ll;
    vector<int> productQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> powers;
        int mod = 1e9 + 7;
        for (int i = 0; i < 32; i++)
            if ((n >> i) & 1)
                powers.push_back(1 << i);
        vector<int> ans(queries.size(), 1);
        for (int i = 0; i < queries.size(); i++)
        {
            int l = queries[i][0], r = queries[i][1];
            for (int j = l; j <= r; j++)
                ans[i] = (static_cast<ll>(ans[i]) * powers[j]) % mod;
        }
        return ans;
    }
};
