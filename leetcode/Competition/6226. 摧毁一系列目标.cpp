// 60��˫����
#include <vector>
#include <map>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
// ����m ��ʱ
class Solution
{
public:
    int destroyTargets(vector<int> &nums, int space)
    {
        vector<int> tmp = nums;
        sort(begin(tmp), end(tmp));
        int maxD = 0;
        int ans = tmp.back();
        int i = 0;
        for (auto &input : tmp)
        {
            int cnt = 0;
            for (auto &target : nums)
            {
                if (target >= input && (target - input) % space == 0)
                {
                    cnt++;
                }
            }
            if (cnt > maxD)
            {
                maxD = cnt;
                ans = input;
            }
            if (maxD > tmp.size() / 2 && i > tmp.size())
                break;

            i++;
        }
        return ans;
    }
};
// ��ѧ; ����
class Solution
{
public:
    int destroyTargets(vector<int> &nums, int space)
    {
        vector<int> tmp = nums;
        sort(begin(tmp), end(tmp));
        int maxD = 0;
        int ans = tmp.back();
        unordered_map<int, pair<int, int>> mp; // key ����, val.first ����, val.second ��С
        for (auto &num : tmp)
        {
            if (!mp.count(num % space))
                mp[num % space].second = num;
            mp[num % space].first++;
        }
        for (auto &[key, val] : mp)
        {
            if (val.first > maxD)
            {
                maxD = val.first;
                ans = val.second;
            }
            else if (val.first == maxD)
                ans = min(ans, val.second);
        }
        return ans;
    }
};