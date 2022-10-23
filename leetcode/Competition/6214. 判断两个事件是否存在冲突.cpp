#include <string>
#include <stack>
#include <bitset>
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
// 字符串
class Solution
{
public:
    bool haveConflict(vector<string> &event1, vector<string> &event2)
    {
        int hour_start1 = stoi(event1[0].substr(0, 2).c_str()), min_start1 = stoi(event1[0].substr(3, 2).c_str());
        int hour_end1 = stoi(event1[1].substr(0, 2).c_str()), min_end1 = stoi(event1[1].substr(3, 2).c_str());

        int hour_start2 = stoi(event2[0].substr(0, 2).c_str()), min_start2 = stoi(event2[0].substr(3, 2).c_str());
        int hour_end2 = stoi(event2[1].substr(0, 2).c_str()), min_end2 = stoi(event2[1].substr(3, 2).c_str());
        int begin1 = hour_start1 * 60 + min_start1, end1 = hour_end1 * 60 + min_end1;
        int begin2 = hour_start2 * 60 + min_start2, end2 = hour_end2 * 60 + min_end2;
        if (end1 < begin2)
            return false;
        else
        {
            if (begin1 > end2)
                return false;
        }
        return true;
    }
};
// 直接比较字符串
class Solution
{
public:
    bool haveConflict(vector<string> &event1, vector<string> &event2)
    {
        if (event1[1] < event2[0])
            return false;
        else
        {
            if (event1[0] > event2[1])
                return false;
        }
        return true;
    }
};
// 精简
class Solution
{
public:
    bool haveConflict(vector<string> &event1, vector<string> &event2)
    {
        return event1[1] < event2[0] ? false : event1[0] <= event2[1];
    }
};