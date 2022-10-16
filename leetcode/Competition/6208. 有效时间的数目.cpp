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
    int countTime(string time)
    {
        char q = '?';
        int h = 1, m = 1;
        char hl = time[0], hr = time[1], ml = time[3], mr = time[4];

        //  hour
        if (hl == q && hr == q)
        {
            h = 24;
        }
        else if (hl == q && hr != q)
        {
            if (hr <= '3')
                h = 3;
            else
                h = 2;
        }
        else if (hl != q && hr == q)
        {
            if (hl < '2')
                h = 10;
            else
                h = 4;
        }
        // minute
        if (ml == q && mr == q)
            m = 60;
        else if (ml == q && mr != q)
            m = 6;
        else if (ml != q && mr == q)
            m = 10;

        return m * h;
    }
};